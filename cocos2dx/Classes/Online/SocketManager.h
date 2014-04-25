#include <iostream>
#include <string>
 
#include "cocos2d.h"
#if defined (CC_TARGET_OS_IPHONE) || defined (ANDROID)
    #include <sys/socket.h>
#else 
	#include <winsock.h>
#endif

#include "connection.h"

using namespace std;

#ifndef INVALID_SOCKET
#define INVALID_SOCKET (SOCKET)(~0)
#endif
#ifndef SOCKET_ERROR
#define SOCKET_ERROR -1
#endif
#ifndef SD_RECEIVE
#define SD_RECEIVE 0x00
#define SD_SEND 0x01
#define SD_BOTH 0x02
#endif

//user pre-compile identifiers
#define WSVERS MAKEWORD(2, 0)	 //winsock version 2.0


class SocketManager
{
private:
#ifdef WIN32
	WSADATA wsadata;
#endif
	string server;
	string port;
	SOCKET socket;
	Connection cn;

public:
	SocketManager(string server, string port){
		this->server = server;
		this->port = port;
		socket=INVALID_SOCKET;
	}

	~SocketManager(){
#ifndef ANDROID
		try{
#endif//ANDROID

			shutdown(socket, SD_BOTH);
#if defined CC_TARGET_OS_IPHONE || defined ANDROID
            close(socket);
#else
			closesocket(socket);
            WSACleanup(); 
#endif

#ifndef ANDROID
		}catch(ConnException e){
			cout<<e.msg<<" ..... "<<e.err<<endl;
		}
#endif//ANDROID
	}



	bool sendMessage(const char* message,int msgSize);
	bool toConnect();
	int receive(char * buf, int len);
};
