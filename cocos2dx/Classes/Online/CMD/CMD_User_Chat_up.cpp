#include "CMD_User_Chat_up.h" 
 
/** 
* ��½ 
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
	m_MessageSender->writeInt( chatsrc ) ; //���id 
	m_MessageSender->writeInt( chatindex ) ; //��ҵڼ�������
	//m_MessageSender->writeUTF( password ) ; //���� 
	//m_MessageSender->writeByte( logType ) ; //ע�᷽ʽ0sp1auto 
} 
