#include "CMD_User_LoginGame_up.h" 
 
/** 
* 登陆 
*/ 
 
CMD_User_LoginGame_up::CMD_User_LoginGame_up() 
{ 
	CMDID = 135; 
} 
 
CMD_User_LoginGame_up::~CMD_User_LoginGame_up() 
{ 
} 
 
void CMD_User_LoginGame_up::RebuildCMD() 
{ 
	/** 
	*/ 
	 
	m_MessageSender->reset(); 
	m_MessageSender->writeInt( CMDID ) ; 
	m_MessageSender->writeUTF( userName ) ; //玩家名 
	m_MessageSender->writeUTF( password ) ; //密码 
	//m_MessageSender->writeByte( logType ) ; //注册方式0sp1auto 
} 
