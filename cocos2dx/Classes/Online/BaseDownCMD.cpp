#include "BaseDownCMD.h"

BaseDownCMD::BaseDownCMD()
{
	m_MessageReceiver = new CinStream ; 
}

BaseDownCMD::~BaseDownCMD()
{
	DELETE_VAR(m_MessageReceiver); 
}

void BaseDownCMD::setSerialID(INT_TYPE s) 
{
	SerialID = s;
}

void BaseDownCMD::SetReceiver(char* rec, int lengt)
{
	m_MessageReceiver->setData(rec, lengt);
	AnalyzeCMD(); 
}
