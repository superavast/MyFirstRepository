#ifndef __BaseUpCMD_H__
#define __BaseUpCMD_H__

#include "cocos2d.h"
// #include "cocos-ext.h"
// #include "AppMacros.h"
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

class BaseUpCMD: public CCObject
{
public:    
    BaseUpCMD();
	~BaseUpCMD();

public:
	INT_TYPE CMDID ;
	clock_t nTimeStamp; //本地时间戳 

	virtual void RebuildCMD() {};
	CoutStream *m_MessageSender;
	INT_TYPE getLength() ;
	char* getData() ;

};

#endif // __BaseUpCMD_H__
