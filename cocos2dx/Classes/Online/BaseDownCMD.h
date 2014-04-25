#ifndef __BaseDownCMD_H__
#define __BaseDownCMD_H__

#include "cocos2d.h"
//#include "cocos-ext.h"
//#include "AppMacros.h"
#include "stdafx.h"
#include "../Online/DataInput/CoutStream.h"
#include "../Online/DataInput/CinStream.h"

USING_NS_CC;
//USING_NS_CC_EXT;

/**
 * define a create function for a specific type, such as CCLayer
 * @__TYPE__ class type to add create(), such as CCLayer
 */
#define CREATE_CMD_FUNC(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new __TYPE__(); \
    if (pRet) \
    { \
        return pRet; \
    } \
    else \
    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
    } \
}

class BaseDownCMD: public CCObject
{
public:    
    BaseDownCMD();
	~BaseDownCMD();

public:
	INT_TYPE CMDID ;
	INT_TYPE SerialID ;

	void setSerialID(INT_TYPE s) ;
	clock_t nTimeStamp;

	virtual void AnalyzeCMD() {};

	CinStream  *m_MessageReceiver;
	void SetReceiver(char* rec, int lengt);
};

#endif // __BaseDownCMD_H__
