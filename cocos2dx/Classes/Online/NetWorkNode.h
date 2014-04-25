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
	 * ��������
	 */
	static void retry();

	char* curSERVER_IP;
    short curSERVER_PORT;
private:
	void initSocket();
	void connect();
	void reconnect();

	int threadStart_send();// �����̵߳ķ���  
	int threadStart_read();// �����̵߳ķ���
	static void* thread_funcation_send(void *arg);// ���������̺߳�����ע������Ǿ�̬����  
	static void* thread_funcation_read(void *arg);// ���������̺߳�����ע������Ǿ�̬���� 

	static bool sendMessage();
	static int sendMessageToServer();

	static bool getMessageFromServer();
};

#endif // __NETWORKNODE_H__
