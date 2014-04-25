#ifndef __NETWORKNODE_H__
#define __NETWORKNODE_H__

#include "cocos2d.h"

class BaseUpCMD;
class BaseDownCMD;
class NetWorkNode : public cocos2d::CCNode
{
public:
	NetWorkNode();
	virtual ~NetWorkNode();

//	CREATE_FUNC(NetWorkNode);

	void lineNewIP(char* nip,short nport);
	static bool getConnectedState();

    virtual bool init();  
	void update(float dt);

	void resetCommandList();

	void CMD_HeartbeatCallback(CCObject* pSender);

	static void AddToCommandList(BaseUpCMD* bsCMD);
	
	/**
	 * 尝试重连
	 */
	static void retry();

	char* curSERVER_IP;
    short curSERVER_PORT;
private:
	void initSocket();
	void connect();
	void reconnect();

	int threadStart_send();// 启动线程的方法  
	int threadStart_read();// 启动线程的方法
	static void* thread_funcation_send(void *arg);// 被启动的线程函数，注意必须是静态方法  
	static void* thread_funcation_read(void *arg);// 被启动的线程函数，注意必须是静态方法 

	static bool sendMessage();
	static int sendMessageToServer();

	static bool getMessageFromServer();
};

#endif // __NETWORKNODE_H__
