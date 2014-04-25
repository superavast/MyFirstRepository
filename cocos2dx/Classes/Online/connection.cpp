#include "stdafx.h"
#include "connection.h"

SOCKET Connection::passivesock(const string &serv, const string &tp, const int qlen)
{
	this->service=serv;
	this->protocal_type=tp;
	this->qlen=qlen;

	const char *service=serv.data();
	const char *transport=tp.data();

	struct servent	*pse;	/* pointer to service information entry	*/
	struct protoent *ppe;	/* pointer to protocol information entry*/
	struct sockaddr_in sin;	/* an Internet endpoint address		*/
	SOCKET s;	/* socket descriptor			*/
	int type;	/* socket type (SOCK_STREAM, SOCK_DGRAM)*/

	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;

	/* Map service name to port number */
	if ( pse = getservbyname(service, transport) )
		sin.sin_port = htons(ntohs((u_short)pse->s_port)+ portbase);
	else if ( (sin.sin_port = htons((u_short)atoi(service))) == 0 )
	{
#ifndef ANDROID
		throw (ConnException(1,"can't get service entry ",(DWORD)errno)); 
#else
		CCLOG("can't get service entry 1  %d",errno);
#endif
	}
	/* Map protocol name to protocol number */
	if ( (ppe = getprotobyname(transport)) == 0){
#ifndef ANDROID
		throw (ConnException(1,"can't get protocol entry ",(DWORD)errno)); 
#else
		CCLOG("can't get protocol entry 2  %d",errno);
		return INVALID_SOCKET;
#endif
	}

	/* Use protocol to choose a socket type */
	if (strcmp(transport, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;

	/* Allocate a socket */
	s = ::socket(PF_INET, type, ppe->p_proto);
	if (s == INVALID_SOCKET){
#ifndef ANDROID
		throw (ConnException(1,"can't create socket ",(DWORD)errno)); 
#else
		//CCLOG("can't create socket 3  %d",errno);
		return INVALID_SOCKET;
#endif
	}
	/* Bind the socket */
	if (::bind(s, (struct sockaddr *)&sin, sizeof(sin)) == SOCKET_ERROR){
#ifndef ANDROID
		throw (ConnException(1,"can't bind to port ",(DWORD)errno)); 
#else
		CCLOG("can't bind to port 4  %d",errno);
		return INVALID_SOCKET;
#endif
	}

	if (type == SOCK_STREAM && listen(s, qlen) == SOCKET_ERROR)
	{
#ifndef ANDROID
		throw (ConnException(1,"can't listen port ",(DWORD)errno)); 
#else
		CCLOG("can't listen port 5  %d",errno);
		return INVALID_SOCKET;
#endif
	}

	return s;
}

SOCKET Connection::connectsock(const string &h, const string &serv, const string &tp)
{
	this->host=h;
	this->service=serv;
	this->protocal_type=tp;

	const char *host=h.data();
	const char *service=serv.data();
	const char *transport=tp.data();

	struct hostent	*phe;	/* pointer to host information entry	*/
	struct servent	*pse;	/* pointer to service information entry	*/
	struct protoent *ppe;	/* pointer to protocol information entry*/
	struct sockaddr_in sin;	/* an Internet endpoint address		*/
	SOCKET s;
	int type;	/* socket descriptor and socket type	*/


	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;

	/* Map service name to port number */
	if ( pse = getservbyname(service, transport) )
		sin.sin_port = pse->s_port;
	else if ( (sin.sin_port = htons((u_short)atoi(service))) == 0 ){
#ifndef ANDROID
		throw (ConnException(1,"can't get service entry ",errno)); 
#else
		CCLOG("can't get service entry 6  %d",errno);
		return INVALID_SOCKET;
#endif
	}

	/* Map host name to IP address, allowing for dotted decimal */
	if ( phe = gethostbyname(host) )
		memcpy(&sin.sin_addr, phe->h_addr, phe->h_length);
	else if ( (sin.sin_addr.s_addr = inet_addr(host)) == INADDR_NONE){
#ifndef ANDROID
		throw (ConnException(1,"can't get host entry",(DWORD)errno));
#else
		CCLOG("can't get host entry 7  %d",errno);
		return INVALID_SOCKET;
#endif
	}

#ifndef ANDROID
	/* Map protocol name to protocol number */
	if ( (ppe = getprotobyname(transport)) == 0){
#ifndef ANDROID
		throw (ConnException(1,"can't get protocol entry ",(DWORD)errno)); 
#else
		CCLOG("can't get protocol entry 8  %d",errno);
		return INVALID_SOCKET;
#endif
	}
#endif
	/* Use protocol to choose a socket type */
	if (strcmp(transport, "udp") == 0)
		type = SOCK_DGRAM;
	else
		type = SOCK_STREAM;

	/* Allocate a socket */
#ifndef ANDROID
	s = ::socket(PF_INET, type, ppe->p_proto);
#else
	s = ::socket(PF_INET, type, SOL_TCP);
#endif
	if (s == INVALID_SOCKET){
#ifndef ANDROID
		throw (ConnException(1,"can't create socket ",(DWORD)errno)); 
#else
		//CCLOG("can't create socket 9  %d",errno);
		return INVALID_SOCKET;
#endif
	}
	//int nTimeout = 100;
	//setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char*)&nTimeout, sizeof(nTimeout));

	/* Connect the socket */
	if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) ==	SOCKET_ERROR)
    {
        printf("error is %d", errno);
#ifndef ANDROID
		throw (ConnException(1,"can't connect to server ",(DWORD)errno)); 
#else
		CCLOG("can't create socket 10  %d",errno);
#endif
    }

	CCLOG("create socket over  %d",s);

	return s;
}

bool Connection::makePassive(const string &service, const string &transport, const int qlen){
#ifndef ANDROID
	try{
		sock=passivesock(service, transport, qlen);
	}catch(ConnException e){
		if(e.exc) throw e;
		sock=INVALID_SOCKET;
		return false;
	}
#else
	sock=passivesock(service, transport, qlen);
	if(sock == INVALID_SOCKET)
		return false;
#endif
	return true;
}

bool Connection::makeConnect(const string &host, const string &service, const string &protocal){
#ifndef ANDROID
	try{
		sock=connectsock(host, service, protocal);
	}catch(ConnException e){
		if(e.exc) throw e;
		sock=INVALID_SOCKET;
		return false;
	}
#else
	sock=connectsock(host, service, protocal);
	if(sock==INVALID_SOCKET)
		return false;
#endif
	return true;
}
