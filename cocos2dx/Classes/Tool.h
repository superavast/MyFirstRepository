#ifndef _TOOLS_H_
#define  _TOOLS_H_
#include "Top.h"
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	#include "Iconv.h"
//#endif

#include "cocos2d.h"
#include "GE_Base.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//字符转换，使cocos2d-x在win32平台支持中文显示
// 	int code_convert(std::string &gbkStr,const char* toCode,const char* formCode);
// 
// 	void UTF8ToGBK(std::string& strUtf8);
// 
// 	void GBKToUTF8(std::string& strGBK);
#endif

	int code_convert(std::string &gbkStr,const char* toCode,const char* formCode);

	void UTF8ToGBK(std::string& strUtf8);

	void GBKToUTF8(std::string& strGBK);

string stringToCH(const char* gbkStr);

string wtos(const wstring& str);

wstring stow(const string& str);

cocos2d::CCString* valueForDictKey(const char *key, cocos2d::CCDictionary/*<std::string, CCString*>*/* dict);

cocos2d::CCArray/*CCMutableArray<cocos2d::CCString*>*/* splitString(const char* src, const char ch);

int IsTextUTF8(const char* str,ulong length) ;

#endif //_TOOLS_H_