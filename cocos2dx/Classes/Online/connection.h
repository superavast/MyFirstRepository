#pragma once

#include "cocos2d.h"

#include <cstdlib>
#include <string>
#if defined CC_TARGET_OS_IPHONE || defined ANDROID
    #include <sys/socket.h>
    #include <netdb.h>
    #include <unistd.h>
    #include <arpa/inet.h>
#else
	#include <winsock.h>
#endif



#include "conn_exception.h"

using std::string;

#ifndef	INADDR_NONE
#define	INADDR_NONE	0xffffffff
#endif	/* INADDR_NONE */

#ifndef SD_RECEIVE
#define SD_RECEIVE 0x00
#define SD_SEND 0x01
#define SD_BOTH 0x02
#endif

#define CONN_EXCEPTION 1

#define PASSIVE_SOCK 1
#define CONNECT_SOCK 2

#define DEFAULT_QLEN 50

typedef int SOCKET_TYPE;
#if defined CC_TARGET_OS_IPHONE || defined ANDROID
    typedef unsigned int SOCKET;
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR    -1
#elif defined WIN32
//    #define errno GetLastError()
#endif

//class connection
class Connection
{
public:
	Connection(){
		sock=INVALID_SOCKET;
		sock_type=0;
		qlen=DEFAULT_QLEN;
		host="localhost";
		service="service";
		protocal_type="tcp";
		portbase = 0;
	}

	~Connection(){
		shutdown(sock, SD_BOTH);
#if defined CC_TARGET_OS_IPHONE || defined ANDROID
		close(sock);
#else
        closesocket(sock);
#endif
	}

	//make connect-socket
	bool makeConnect(const string &host, const string &service, const string &protocal);
	bool makeConnect(){
		return makeConnect(host, service, protocal_type);
	}
	//make passive-socket
	bool makePassive(const string &service, const string &transport, const int qlen);
	bool makePassive(){
		return makePassive(service, protocal_type, qlen);
	}

	//get protocal
	string getProtocal(){ return protocal_type; }

	//get socket type
	SOCKET_TYPE getSocketType(){ return sock_type; }

	//get socket
	SOCKET getSocket(){	return sock; }

	string getHost(){ return host; }
	string getService(){ return service; }
	string getPort(){ return service; }
	int getQueueLength(){ return qlen; }

protected:

private:
	SOCKET passivesock(const string &service, const string &transport, const int qlen);
	SOCKET connectsock(const string &host, const string &service, const string &transport );

private:
	SOCKET sock;
	SOCKET_TYPE sock_type;
	string protocal_type;
	string host;
	string service;
	int qlen;
	u_short	portbase;
};
