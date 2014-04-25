#include "CMD_User_Chat_up.h" 
 
/** 
* 登陆 
*/ 
 
CMD_User_Chat_up::CMD_User_Chat_up() 
{ 
	CMDID = 100; 
} 
 
CMD_User_Chat_up::~CMD_User_Chat_up() 
{ 
} 
 
void CMD_User_Chat_up::RebuildCMD() 
{ 
	/** 
	*/ int chatindex;
		int chatsrc;
		string chatcontent ;
	 
	m_MessageSender->reset(); 
	m_MessageSender->writeInt( CMDID ) ; 
	m_MessageSender->writeInt( chatsrc ) ; //玩家id 
	m_MessageSender->writeInt( chatindex ) ; //玩家第几条聊天
	//m_MessageSender->writeUTF( password ) ; //密码 
	//m_MessageSender->writeByte( logType ) ; //注册方式0sp1auto 
} 
