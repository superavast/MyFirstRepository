#include "NetWorkNode.h"
//#include "AppMacros.h"
#include <iostream>
#include <string>
#include <pthread.h>// <pthread.h>
#include <semaphore.h>
// 
// #include "../wrapper/wrapper.h"
// #include "../homeScene/HomeScene.h"

#include "../Online/ODSocket.h"
#include "../Online/DataInput/CoutStream.h"
#include "../Online/DataInput/CinStream.h"
#include "../Online/CMD/CmdMaker.h"
#include "../Online/BaseUpCMD.h"
#include "../Online/BaseDownCMD.h"
//#include "GAdminister.h"

USING_NS_CC;

// #define NETWORK_DEBUG_GETMSG
// #define NETWORK_DEBUG

#ifdef NETWORK_DEBUG
	#define NETWORK_CALLLINE	, __FILE__ , __LINE__ 
#else
	#define NETWORK_CALLLINE
#endif

//"42.120.51.43"
//"172.16.2.89"  LOCAL
//#define SERVER_IP						"42.120.51.43"
//#define SERVER_IP						"172.16.2.89"
// #define SERVER_IP						"192.168.138.79"
// 
// #define SERVER_PORT						11401

#define SOCKET_RECEIVE_BYTE_MAX			1024
#define SOCKET_RECEIVE_BYTE_TEMP_MAX	10000
#define GAME_NETWORK_CMD_MAX			200
#define GAME_NETWORK_TIMEOUT_TIME		(5000)

#define COMMAND_END							-1
#define COMMAND_SUCCESS						1
#define COMMAND_ERROR						107


//char* curSERVER_IP="192.168.1.102"/*"127.0.0.1"*/;
//short curSERVER_PORT=11402;

static const int RECONNECT_TIME = 3; // 重连次数

static ODSocket* mODSocket;
static bool s_isConnected = false;
static int _sTime  = 0;
static bool _sNeedConnected  = true;

static bool s_hasQuitSendThread = true;
static bool s_hasQuitReadThread = true;

/// 消息读取
static CoutStream*		m_MessageSender;
static CinStream*		m_MessageReceiver;
static CinStream*		m_MessageReceiverTemp;

static char*	m_FirstMessageReceiverTemp;

static char*	m_MessageReceiverByteArray;
static char*	m_MessageReceiverByteArrayTemp;
static int		m_MessageReceiverByteLength;
static int		m_MessageReceiverByteLengthTotal;

/// 消息缓存
static CCArray/*<BaseUpCMD*>*/* s_pSendBuffer;
static CCArray/*<BaseDownCMD*>*/* s_pRecvBuffer;
static CCArray/*<BaseUpCMD*>*/* s_pTempSendBuffer;
static CCArray/*<BaseDownCMD*>*/* s_pTempRecvBuffer;
// static CCArray* s_pSendBuffer;
// static CCArray* s_pRecvBuffer;
// static CCArray* s_pTempSendBuffer;
// static CCArray* s_pTempRecvBuffer;

/// 线程锁
static pthread_mutex_t s_sendMutex;
static pthread_mutex_t s_recvMutex;

/// 原子操作
static sem_t* s_pSem = NULL;

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
#define CC_ASYNC_NETWORKNODE_USE_NAMED_SEMAPHORE 1
#else
#define CC_ASYNC_NETWORKNODE_USE_NAMED_SEMAPHORE 0
#endif

#if CC_ASYNC_NETWORKNODE_USE_NAMED_SEMAPHORE
#define CC_ASYNC_NETWORKNODE_SEMAPHORE "ccNetWorkNodeAsync"
#else
static sem_t s_sem;
#endif

static LONG_TYPE m_LastSendTime; // 心跳发送
static bool s_hasRecvHeartBeat = true;	 // 心跳接收
static int MySendMessageCount = 0;

NetWorkNode::NetWorkNode()
{
	curSERVER_IP="127.0.0.1";
    curSERVER_PORT=5555;
	retry();
}

NetWorkNode::~NetWorkNode()
{
	mODSocket->Close();
	DELETE_VAR(mODSocket);

	if( s_pSem != NULL )
	{
#if CC_ASYNC_NETWORKNODE_USE_NAMED_SEMAPHORE
		sem_unlink(CC_ASYNC_NETWORKNODE_SEMAPHORE);
		sem_close(s_pSem);
#else
		sem_destroy(s_pSem);
#endif
		s_pSem = NULL;
	}

	DELETE_VAR(m_MessageSender);
	DELETE_VAR(m_MessageReceiver);
	DELETE_VAR(m_MessageReceiverTemp);

	DELETE_ARRAY(m_FirstMessageReceiverTemp);

	CC_SAFE_DELETE(s_pSendBuffer);
	CC_SAFE_DELETE(s_pRecvBuffer);
}

// on "init" you need to initialize your instance
bool NetWorkNode::init()
{
	mODSocket = new ODSocket();

	m_MessageSender = new CoutStream();
	m_MessageReceiver = new CinStream();
	m_MessageReceiverTemp = new CinStream(); 
	INIT_ARRAY(char,m_MessageReceiverByteArray,SOCKET_RECEIVE_BYTE_TEMP_MAX);
	INIT_ARRAY(char,m_MessageReceiverByteArrayTemp, SOCKET_RECEIVE_BYTE_TEMP_MAX);
	m_MessageReceiver->setData(m_MessageReceiverByteArray, SOCKET_RECEIVE_BYTE_TEMP_MAX);
	m_MessageReceiverTemp->setData(m_MessageReceiverByteArrayTemp, SOCKET_RECEIVE_BYTE_TEMP_MAX);

	INIT_ARRAY(char, m_FirstMessageReceiverTemp, SOCKET_RECEIVE_BYTE_MAX) ;
	
	s_pSendBuffer = new CCArray/*CCMutableArray<BaseUpCMD*>*/();//*[SYNC_CMD_MAX];//CCArray::create();
	s_pSendBuffer->retain();
	s_pRecvBuffer = new CCArray/*CCMutableArray<BaseUpCMD*>*/();//CCArray::create();
	s_pRecvBuffer->retain();

	s_pTempSendBuffer = new CCArray/*CCMutableArray<BaseUpCMD*>*/();// CCArray::create();
	s_pTempSendBuffer->retain();
	s_pTempRecvBuffer =  new CCArray/*CCMutableArray<BaseUpCMD*>*/();//CCArray::create();
	s_pTempRecvBuffer->retain();

	schedule(schedule_selector(NetWorkNode::update));

	pthread_mutex_init(&s_sendMutex, NULL);
	pthread_mutex_init(&s_recvMutex, NULL);

#if CC_ASYNC_NETWORKNODE_USE_NAMED_SEMAPHORE
	s_pSem = sem_open(CC_ASYNC_NETWORKNODE_SEMAPHORE, O_CREAT, 0644, 0);
	if( s_pSem == SEM_FAILED )
	{
		CCLOG( "NetWorkNode async thread semaphore init error: %s\n", strerror( errno ) );
		s_pSem = NULL;
		return false;
	}
#else
	int semInitRet = sem_init(&s_sem, 0, 0);
	if( semInitRet < 0 )
	{
		CCLOG( "NetWorkNode async thread semaphore init error: %s\n", strerror( errno ) );
		return false;
	}
	s_pSem = &s_sem;
#endif
    
//	m_LastSendTime = CSystem::currentTimeMillis();

    reconnect();

	return true;
}

void NetWorkNode::initSocket()
{
	s_isConnected = false;

	// init socket
	mODSocket->Close();
	mODSocket->Init();

#ifndef ANDROID
	if (mODSocket->Create(AF_INET,SOCK_STREAM,0) == false)
#else
	if (mODSocket->Create(PF_INET,SOCK_STREAM,SOL_TCP) == false)
#endif
	{
		return;
	}
}

void NetWorkNode::connect()
{
	CCLOG("connect SERVER_IP=%s SERVER_PORT=%d",curSERVER_IP,curSERVER_PORT);
	s_isConnected = mODSocket->Connect(curSERVER_IP,curSERVER_PORT);//SERVER_IP,SERVER_PORT);

	if (s_isConnected)
	{
		CCLOG("s_isConnected=true");
		// 断线重连成功
// 		if (m_hero)
// 		{
// 			GameBaseScene* pScene = dynamic_cast<GameBaseScene*>(getParent());
// 			if (pScene)
// 			{
// 				pScene->send_CMD_LoginToServer(m_hero->userUUID);
// 			}
// 		}
	}
}

void NetWorkNode::reconnect()
{
    CCLOG("reconnect %d-%d",s_isConnected,_sTime);
	while(!s_isConnected && _sTime < RECONNECT_TIME)
	{
		initSocket();
		connect();
		_sTime++;
		CCLOG("_sTime=%d",_sTime);
	}
	if (_sTime>=RECONNECT_TIME&&!s_isConnected)
	{
		//GAdminister::getInstance()->NetConnectFailedMessage();
//		switch(GAdminister::getInstance()->getCurrentScene())
//		{
//		case SCENE_ID_LOGIN:
//LoginScene::
//
//					SCENE_ID_LOAD,
//	SCENE_ID_LOGIN,
//    SCENE_ID_CARTOON,
//	SCENE_ID_GAME,
//	SCENE_ID_SCENARIO,
//		
//		}
// 		switch(s_currentScene)
// 		{
// 		case SCENE_MM:
// 			// 登录失败
// 			// TODO
// 			CCLOG("ERR: NET CONNECT");
// 			break;
// 
// 		case SCENE_HOME:
// 			// 重连失败
// 			{
// 				HomeScene* pScene = dynamic_cast<HomeScene*>(getParent());
// 				if (pScene)
// 				{
// 					pScene->openNetBreakScene();
// 				}
// 			}
// 			break;
// 
// 		case SCENE_SINGE_GAME:
// 			// 重连失败
// 			{
// 				GameScene* pScene = dynamic_cast<GameScene*>(getParent());
// 				if (pScene &&
// 					pScene->m_gameEndState != GAME_END_NONE)
// 				{
// 					pScene->openNetBreakScene();
// 				}
// 			}
// 			break;
// 
// 		default:
// 			break;
// 		}
	}
	else if(s_isConnected)
	{
		// start thread
		threadStart_read();
		threadStart_send();
	}
} 

// 启动线程的方法  
int NetWorkNode::threadStart_send()  
{   
	pthread_t pid;
	pthread_create(&pid, NULL, thread_funcation_send, NULL);
	pthread_detach(pid);
    return 0;
}  

// 需要线程来完成的功能都写在这个函数里  
void* NetWorkNode::thread_funcation_send(void *arg)  
{
	CCLOG("thread_funcation_send ..... start");

	s_hasQuitSendThread = false;

	while (true) {
		int semWaitRet = sem_wait(s_pSem);
		if( semWaitRet < 0 )
		{
			CCLOG( "thread_funcation_send thread semaphore error: %s\n", strerror( errno ) );
			break;
		}

		if (!s_isConnected)
		{
			// 断网了
			CCLOG("thread_funcation_send quit");
			break;
		}

		if (!sendMessage())
		{
			// 发送失败 断网了
			s_isConnected = false;
			retry();
			CCLOG("thread_funcation_send no connected ..... quit");
			break;
		}
    }

	s_hasQuitSendThread = true;

	return NULL; 
} 
 
// 启动线程的方法  
int NetWorkNode::threadStart_read()
{  
    pthread_t pid;
	pthread_create(&pid, NULL, thread_funcation_read, NULL);
	pthread_detach(pid);
	return 0;
}  

// 需要线程来完成的功能都写在这个函数里  
void* NetWorkNode::thread_funcation_read(void *arg)  
{
	CCLOG("thread_funcation_read ..... start");

	s_hasQuitReadThread = false;

    while (true) 
	{
		if (!s_isConnected)
		{
			// 断网了
			CCLOG("thread_funcation_read quit");
			break;
		}

		if (!getMessageFromServer())
		{
			// 读取失败 断网了
			s_isConnected = false;
			sem_post(s_pSem); // 激活发送线程， 方便结束
			retry();
			CCLOG("thread_funcation_read no connected ..... quit");
			break;
		}
    }

	s_hasQuitReadThread = true;

	return NULL;
} 

void NetWorkNode::AddToCommandList(BaseUpCMD* bsCMD) 
{
	if (!s_isConnected)
	{
		retry();
	}

	bsCMD->RebuildCMD();

    pthread_mutex_lock(&s_sendMutex);
	s_pSendBuffer->addObject(bsCMD);
	bsCMD->release();
    pthread_mutex_unlock(&s_sendMutex);

	sem_post(s_pSem);
}

void NetWorkNode::retry()
{
	if (s_isConnected)
	{
		return;
	}
	_sTime = 0;
	_sNeedConnected = true;
}

void NetWorkNode::lineNewIP(char* nip,short nport)
{
	curSERVER_IP=nip;
	curSERVER_PORT=nport;

	unschedule(schedule_selector(NetWorkNode::update));//schedule(schedule_selector(NetWorkNode::update));

	mODSocket->Close();
	DELETE_VAR(mODSocket);
	if( s_pSem != NULL )
	{
#if CC_ASYNC_NETWORKNODE_USE_NAMED_SEMAPHORE
		sem_unlink(CC_ASYNC_NETWORKNODE_SEMAPHORE);
		sem_close(s_pSem);
#else
		sem_destroy(s_pSem);
#endif
		s_pSem = NULL;
	}

	DELETE_VAR(m_MessageSender);
	DELETE_VAR(m_MessageReceiver);
	DELETE_VAR(m_MessageReceiverTemp);

	DELETE_ARRAY(m_FirstMessageReceiverTemp);

	CC_SAFE_DELETE(s_pSendBuffer);
	CC_SAFE_DELETE(s_pRecvBuffer);

	init();
}
void NetWorkNode::update(float dt) 
{
	// check net
	if (!s_isConnected)
	{
		if (!(s_hasQuitSendThread && s_hasQuitReadThread))
		{
			// 等待线程结束
			CCLOG("update .... wait reconnect");
			return;
		}

		if (_sNeedConnected)
		{
// 			GameBaseScene* pScene = dynamic_cast<GameBaseScene*>(getParent());
// 			if (pScene)
// 			{
// 				pScene->openLoading();
// 			}
            
			reconnect();
            
//             if (pScene)
// 			{
// 				pScene->closeLoading();
// 			}
            
			_sNeedConnected = false;
		}
		return;
	}

    // heart beat
// 	if (CSystem::currentTimeMillis() - m_LastSendTime > 10000)
// 	{
// 		 // CCLOG("TIME GetMessageFromServer =========>>>>>>>>>>>>%d<<<<<<<<<<<" , (CSystem::currentTimeMillis() - m_LastSendTime)) ;
// 		if (!s_hasRecvHeartBeat)
// 		{
// 			CCLOG("TIME s_hasRecvHeartBeat =========>>>>>>>>>>>>%d<<<<<<<<<<<" , (CSystem::currentTimeMillis() - m_LastSendTime)) ;
// 			s_isConnected = false;
// 			mODSocket->Close();		// XXX 接受线程可能不能正常接受
// 			sem_post(s_pSem);		// 激活发送线程， 方便结束
// 			retry();
// 			return;
// 		}
// 
// 		AddToCommandList(CmdMaker::CmdFactory(CMD_Heartbeat)) ;
// 		CMD_CALLBACK(CMD_Heartbeat, this, NetWorkNode::CMD_HeartbeatCallback);
// 		s_hasRecvHeartBeat = false;
// 	}

    BaseDownCMD* pCmd = NULL;
    
    pthread_mutex_lock(&s_recvMutex);
    int count = s_pRecvBuffer->count();
    if (count > 0) {
        for (int i = 0; i < count; i++)
        {
            s_pTempRecvBuffer->addObject(s_pRecvBuffer->objectAtIndex(i));//objectAtIndex(i));
        }
        s_pRecvBuffer->removeAllObjects();
    }
    pthread_mutex_unlock(&s_recvMutex);
    
    if (count > 0)
    {
		CCLOG("BaseDownCMD count=%d",count);
        for (int i = 0; i < count; i++)
        {
			// 消息回调
			CCLOG("BaseDownCMD index=%d",i);
            pCmd = (BaseDownCMD*)s_pTempRecvBuffer->objectAtIndex(i);//objectAtIndex(i);
            CmdMaker::NetworkCallBack(pCmd);
        }
        s_pTempRecvBuffer->removeAllObjects();
    }
}

bool NetWorkNode::sendMessage() 
{
	int tempLength = 0;

	pthread_mutex_lock(&s_sendMutex);
	int count = s_pSendBuffer->count();
	if (count > 0)
	{
		char buff[64];
		sprintf(buff,"s_pSendBuffer->coun=%d",count);
		CCLOG(buff);
		for (int i = 0; i < count; i++)
		{
			// XXX 重登陆消息需要先发 待优化
			BaseUpCMD* pCmd = (BaseUpCMD*)s_pSendBuffer->objectAtIndex(i);//objectAtIndex(i);
// 			if (pCmd->CMDID == CMD_LoginToServer && s_pTempSendBuffer->count() != 0)
// 			{
// 				s_pTempSendBuffer->insertObject(pCmd, 0);
// 			}
// 			else
// 			{
				s_pTempSendBuffer->addObject(pCmd);
//			}
		}
		s_pSendBuffer->removeAllObjects();
	}
	pthread_mutex_unlock(&s_sendMutex);
	
    // no msg
	count = s_pTempSendBuffer->count();
    char buff[64];
	sprintf(buff,"s_pTempSendBuffer->coun=%d",count);
	CCLOG(buff);
    if (count == 0) return true;
     m_MessageSender->reset();
	 m_MessageSender = new CoutStream();
    for (int i = 0; i < count; i++)
    {
		tempLength = 0;
        BaseUpCMD* pCmd = (BaseUpCMD*)s_pTempSendBuffer->objectAtIndex(i);//objectAtIndex(i);
        tempLength += 4;
        tempLength += 4;
		tempLength += 1;
		//tempLength += 4;
		tempLength += pCmd->getLength();
		m_MessageSender->writeInt(tempLength);
		MySendMessageCount++;
		m_MessageSender->writeInt(MySendMessageCount);
		m_MessageSender->writeByte(1);
		//m_MessageSender->writeInt(135);
		//char*  tt=new char[50];
		//sprintf(tt,"qqqqq");
		//std::string a  = "aaaaaa";
		//m_MessageSender->writeUTF(a);
		//m_MessageSender->writeUTF(a);
		m_MessageSender->writeBytes(pCmd->getData(), pCmd->getLength() );
		//m_MessageSender->writeInt(msgId)
    }
    
// 	tempLength = tempLength + 4;//package head
// 	tempLength = tempLength + 4;//version
// 	tempLength = tempLength + 1;//end length
	//tempLength = tempLength + 4;//end

// 	NetManager.iNetMsgSerialNumber += 1;
// 	dOut.writeInt(NetManager.iNetMsgSerialNumber);
// 	dOut.writeByte(msgType);
/*	 dOut.writeInt(msgId);*/
//	dOut.writeInt(sendData.length + 4);
   
//     m_MessageSender->writeByte( tempLength );
//     m_MessageSender->writeInt( tempLength );
//     m_MessageSender->writeByte( 0 );
//     m_MessageSender->writeByte( 1 );
// 	m_MessageSender->writeInt( 0 ) ;//version ID
    
//     for (int i = 0; i < count; i++)
//     {
//         BaseUpCMD* pCmd = (BaseUpCMD*)s_pTempSendBuffer->objectAtIndex(i);//objectAtIndex(i);
//         m_MessageSender->writeInt(pCmd->getLength() - 4) ; //减去命令ID分量
//         m_MessageSender->writeBytes(pCmd->getData(), pCmd->getLength() );
//     }
// 	for(int i = 0; i < count; i++)
// 	{
// 		
// 	
// 	
// 	}
    
//     m_MessageSender->writeInt(COMMAND_END);
//     m_MessageSender->writeInt(COMMAND_END);
    
    // send msg
    if (sendMessageToServer() == -1)
    {
		return false;
    }
	else
	{
		s_pTempSendBuffer->removeAllObjects();

 //       m_LastSendTime = CSystem::currentTimeMillis();
		return true;
	}
}

void NetWorkNode::resetCommandList()
{
	pthread_mutex_lock(&s_sendMutex);
	s_pSendBuffer->removeAllObjects();
	pthread_mutex_unlock(&s_sendMutex);

	pthread_mutex_lock(&s_recvMutex);
	s_pRecvBuffer->removeAllObjects();
	pthread_mutex_unlock(&s_recvMutex);
}

int NetWorkNode::sendMessageToServer()
{
	return mODSocket->Send(m_MessageSender->getData(), m_MessageSender->getDataLength());
}

bool NetWorkNode::getMessageFromServer() 
{
	int count = mODSocket->Recv(m_FirstMessageReceiverTemp, SOCKET_RECEIVE_BYTE_MAX);
    
    if(count <= 0) 
	{
		return false;
	}
    
	char curPack;
	char totalPack;
	int packLength;
    
#ifdef NETWORK_DEBUG_GETMSG
	clock_t start = clock();
#endif

	if(count > 0)
	{
#ifdef NETWORK_DEBUG_GETMSG
		CCLOG("GetSocket()->Recv >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>! %d " , count) ;
#endif
		memcpy(m_MessageReceiverByteArrayTemp + m_MessageReceiverByteLengthTotal, m_FirstMessageReceiverTemp, count);
		m_MessageReceiverByteLengthTotal += count;

		while(m_MessageReceiverByteLengthTotal > 5)
		{
			m_MessageReceiverTemp->ResetPointer();
			curPack			= m_MessageReceiverTemp->readByte();
			totalPack		= m_MessageReceiverTemp->readByte();
			packLength		= m_MessageReceiverTemp->readInt();

			if (!(curPack >= 0 && totalPack > 0 && curPack < totalPack))
				break;			

			if (packLength <= 0 || packLength >= SOCKET_RECEIVE_BYTE_MAX)
				break;

			if (m_MessageReceiverByteLengthTotal < packLength + 6)
				break;

			if(curPack == 0)
			{
				m_MessageReceiverByteLength = packLength ;
				memcpy(m_MessageReceiverByteArray, m_MessageReceiverByteArrayTemp + 6, packLength);
			}
			else
			{
				memcpy(m_MessageReceiverByteArray + m_MessageReceiverByteLength, m_MessageReceiverByteArrayTemp + 6, packLength);
				m_MessageReceiverByteLength = m_MessageReceiverByteLength + packLength;
			}

			m_MessageReceiverByteLengthTotal -= (packLength + 6);
			memcpy(m_MessageReceiverByteArrayTemp, m_MessageReceiverByteArrayTemp + (packLength + 6), packLength + 6);

			if (curPack + 1 == totalPack)//收完了完整的包
			{
				m_MessageReceiver->ResetPointer();
				m_MessageReceiver->readInt();//version number
				//int Serial_Number = m_MessageReceiver->readInt();//Serial_Number
				int cmdid = m_MessageReceiver->readInt();
				CCAssert(cmdid >= 0, "frist cmd id must >= 0 !" );
				while (cmdid > 0)
				{
					int cmdlength = m_MessageReceiver->readInt();

					CCAssert(cmdlength < 10000, "消息异常");

					STRING_REF s_MessagePool;	
					INIT_ARRAY(char , s_MessagePool, cmdlength);
					s_MessagePool = m_MessageReceiver->readBytes(cmdlength);

					CCLOG("down cmd id = <<<<<<%d>>>>> ", cmdid) ;

                    BaseDownCMD* basecmd = CmdMaker::getCallbackCMD(cmdid);
                    basecmd->SetReceiver(s_MessagePool, cmdlength);//Serial_Number
 //                   basecmd->setSerialID(Serial_Number);

                    pthread_mutex_lock(&s_recvMutex);
                    s_pRecvBuffer->addObject(basecmd);
					basecmd->release();
                    pthread_mutex_unlock(&s_recvMutex);

#ifdef NETWORK_DEBUG_GETMSG
                    CCLOG("CMD <%d> add SerialID:%d TIME=%d", basecmd->CMDID,basecmd->SerialID, clock());
#endif
					cmdid = m_MessageReceiver->readInt();
				}	

#ifdef NETWORK_DEBUG_GETMSG
				CCLOG( "----------------------------------------" ) ;
#endif

				if (m_MessageReceiverByteLengthTotal > 5)
				{
					memcpy(m_MessageReceiverByteArrayTemp, m_MessageReceiverByteArrayTemp + packLength + 6, m_MessageReceiverByteLengthTotal);
				}
			}
			else
            {
                if (m_MessageReceiverByteLengthTotal > 5)
#ifdef NETWORK_DEBUG_GETMSG
                    CCLOG("m_MessageReceiverByteLengthTotal > 5") ;
#else
					;
#endif
                else
                    break;
            }
		}

#ifdef NETWORK_DEBUG_GETMSG
		CCLOG("TIME GetMessageFromServer =========>>>>>>>>>>>>%d<<<<<<<<<<<" , (clock() - start)) ;
#endif
	}

	return true;
}

void NetWorkNode::CMD_HeartbeatCallback(CCObject* pSender)
{
	if (false) CCLOG("NetWorkNode ||| receive CMD_Heartbeat");

	s_hasRecvHeartBeat = true;
}
bool NetWorkNode::getConnectedState()
{
	return s_isConnected;
}