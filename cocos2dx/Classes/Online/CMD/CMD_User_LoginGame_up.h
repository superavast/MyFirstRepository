#ifndef __CMD_User_LoginGame_up_H__ 
#define __CMD_User_LoginGame_up_H__ 
 
#include "cocos2d.h" 
#include "stdafx.h" 
#include "../DataInput/CoutStream.h" 
#include "../BaseUpCMD.h" 
#include <vector> 
 
USING_NS_CC; 
 
/** 
* 登陆 
*/ 
using namespace std; 
 
class CMD_User_LoginGame_up: public BaseUpCMD 
{ 
	public: 
		 
		//implement the "static node()" method manually 
		CREATE_CMD_FUNC(CMD_User_LoginGame_up); 
		 
		CMD_User_LoginGame_up(); 
		~CMD_User_LoginGame_up(); 
		 
		void RebuildCMD(); 
		 
		 
	public: 
		 
	public: 
		//CMD_BODY_UP_START 
		string userName ; //玩家名 
		string password ; //密码 
		char logType ; //注册方式0sp1auto 
		//CMD_BODY_UP_END 
		 
		 
}; 
 
#endif // __CMD_User_LoginGame_up_H__ 
