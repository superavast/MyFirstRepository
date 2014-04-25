#include "BaseUpCMD.h"

BaseUpCMD::BaseUpCMD()
{
	m_MessageSender = new CoutStream ;   
}

BaseUpCMD::~BaseUpCMD()
{
	DELETE_VAR(m_MessageSender) ; 
}

INT_TYPE BaseUpCMD::getLength() 
{
	return m_MessageSender->getDataLength();
}

char* BaseUpCMD::getData() 
{
	return m_MessageSender->getData();
}