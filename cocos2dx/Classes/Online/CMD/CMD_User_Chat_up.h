#ifndef __CMD_User_Chat_up_H__ 
#define __CMD_User_Chat_up_H__ 
 
#include "cocos2d.h" 
#include "stdafx.h" 
#include "../DataInput/CoutStream.h" 
#include "../BaseUpCMD.h" 
#include <vector> 
 
USING_NS_CC; 
 
/** 
* ��½ 
*/ 
using namespace std; 
 
class CMD_User_Chat_up: public BaseUpCMD 
{ 
	public: 
		 
		//implement the "static node()" method manually 
		CREATE_CMD_FUNC(CMD_User_Chat_up); 
		 
		CMD_User_Chat_up(); 
		~CMD_User_Chat_up(); 
		 
		void RebuildCMD(); 
		 
		 
	public: 
		 
	public: 
		//CMD_BODY_UP_START 
		int chatindex;
		int chatsrc;
		string chatcontent ; //����� 
	//	string password ; //���� 
	//	char logType ; //ע�᷽ʽ0sp1auto 
		//CMD_BODY_UP_END 
		 
		 
}; 
 
#endif // __CMD_User_LoginGame_up_H__ 
