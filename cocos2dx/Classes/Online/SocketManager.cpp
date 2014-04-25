
#include "stdafx.h"
#include "SocketManager.h"

bool SocketManager::toConnect()
{
#ifndef ANDROID
	try{
#endif
#ifdef WIN32
		if (WSAStartup(WSVERS, &wsadata) != 0){   /* Æô¶¯Ä³°æ±¾µÄDLL */
			return false;
		}
#endif
		cn.makeConnect(server, port, "tcp");
		socket=cn.getSocket();
		return true;
#ifndef ANDROID
	}catch(ConnException e){
		cout<<e.msg<<" ´íÎóºÅ "<<e.err<<endl;
		return false;
	}
#endif
}

bool SocketManager::sendMessage(const char* message, int msgSize)
{
#ifndef ANDROID
	try{
#endif
#ifdef WIN32
		if (WSAStartup(WSVERS, &wsadata) != 0){   /* Æô¶¯Ä³°æ±¾µÄDLL */
			return false;
		}
#endif
		if(send(socket, message, msgSize, 0)==SOCKET_ERROR){	
			return false;
		}
		return true;
#ifndef ANDROID
	}catch(ConnException e){
		cout<<e.msg<<" ´íÎóºÅ "<<e.err<<endl;
		return false;
	}
#endif
}


int SocketManager::receive(char * buf, int len){
#ifndef ANDROID
	try{
#endif
		int	charCount;			/* recv character count		*/
		if(socket == INVALID_SOCKET || socket == SOCKET_ERROR) 
			return -1;

		//recieve messages
		charCount = recv(socket, buf, len, 0);
		if( charCount != SOCKET_ERROR && charCount > 0) {
			buf[charCount] = '\0';		/* ensure null-termination	*/
		}
		return charCount;
#ifndef ANDROID
	}catch(ConnException e){
		cout<<"error in receive.."<<endl;
		return -1;
	}
#endif
}	
