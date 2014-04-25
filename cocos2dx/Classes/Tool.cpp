#include "Tool.h"

USING_NS_CC;


#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//字符转换，使cocos2d-x在win32平台支持中文显示
// 	int code_convert(std::string &gbkStr,const char* toCode,const char* formCode)
// 	{
// 		iconv_t iconvH;
// 		iconvH = iconv_open(formCode,toCode);
// 		if(iconvH == 0)
// 		{
// 			return -1;
// 		}
// 
// 		const char* strChar = gbkStr.c_str();
// 		const char** pin = &strChar;
// 
// 		size_t strLength = gbkStr.length();
// 		char* outbuf = (char*)malloc(strLength*4);
// 		char* pBuff = outbuf;
// 		memset(outbuf,0,strLength*4);
// 		size_t outLength = strLength*4;
// 		if(-1 == iconv(iconvH,pin,&strLength,&outbuf,&outLength))
// 		{
// 			iconv_close(iconvH);
// 			return -1;
// 		}
// 
// 		gbkStr = pBuff;
// 		iconv_close(iconvH);
// 		return 0;
// 	}

// 	void UTF8ToGBK(std::string& strUtf8) 
// 	{
// 		if (IsTextUTF8(strUtf8.c_str(),strUtf8.length()) != 2)
// 		{
// 			code_convert(strUtf8,"utf-8","gb2312");
// 		}
// 	}
// 
// 	void GBKToUTF8(std::string& strGBK)
// 	{
// 		code_convert(strGBK,"gb2312","utf-8");
// 	}
#endif
int code_convert(std::string &gbkStr,const char* toCode,const char* formCode)
{
	iconv_t iconvH;
	iconvH = iconv_open(formCode,toCode);
	if(iconvH == 0)
	{
		return -1;
	}

	const char* strChar = gbkStr.c_str();
	const char** pin = &strChar;

	size_t strLength = gbkStr.length();
	char* outbuf = (char*)malloc(strLength*4);
	char* pBuff = outbuf;
	memset(outbuf,0,strLength*4);
	size_t outLength = strLength*4;
	if(-1 == iconv(iconvH,pin,&strLength,&outbuf,&outLength))
	{
		iconv_close(iconvH);
		return -1;
	}

	gbkStr = pBuff;
	iconv_close(iconvH);
	return 0;
}

	void UTF8ToGBK(std::string& strUtf8) 
	{
		if (IsTextUTF8(strUtf8.c_str(),strUtf8.length()) != 2)
		{
			code_convert(strUtf8,"utf-8","gb2312");
		}
	}


	void GBKToUTF8(std::string& strGBK)
	{
		// 	if (IsTextUTF8(strGBK.c_str(),strGBK.length()) != 2)
		// 	{
		code_convert(strGBK,"gb2312","utf-8");
		//	}
	}

	string stringToCH(const char* gbkStr){
		string str = gbkStr;
		GBKToUTF8(str);
		return str;
	}

string wtos(const wstring& ws)
{
	std::string curLocale = setlocale(LC_ALL, NULL);
	setlocale(LC_ALL, "chs");
	const wchar_t* _Source = ws.c_str();
	size_t _Dsize = 2 * ws.size() + 1;
	char *_Dest = new char[_Dsize];
	memset(_Dest,0,_Dsize);
	wcstombs(_Dest,_Source,_Dsize);
	std::string result = _Dest;
	delete []_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

wstring stow(const string& s)
{
	setlocale(LC_ALL, "chs"); 
	const char* _Source = s.c_str();
	size_t _Dsize = s.size() + 1;
	wchar_t *_Dest = new wchar_t[_Dsize];
	wmemset(_Dest, 0, _Dsize);
	mbstowcs(_Dest,_Source,_Dsize);
	std::wstring result = _Dest;
	delete []_Dest;
	setlocale(LC_ALL, "C");
	return result;
}




CCString* valueForDictKey(const char *key, cocos2d::CCDictionary* dict)
{
	if (dict)
	{
		return (CCString*)dict->objectForKey(key);
	}
	return new CCString();
}

/*CCMutableArray<CCString*>*/CCArray* splitString(const char* src, const char ch)
{
	if (src == NULL)
	{
		return NULL;
	}

	int index = 0;
	int length = (int)strlen(src);

	int size = 0;

	for (int i = 0; i < length; ++i)
	{
		if (src[i] == ch)
		{
			if (i - index >= 1)
			{
				++size;
			}
			index = i + 1;
		}
		else if (i == length - 1)
		{
			++size;
		}
	}
	/*CCMutableArray<CCString*>*/CCArray* pdest = new /*CCMutableArray<CCString*>*/CCArray(size);
	int pos = 0;
	int len = 0;
	index = 0;

	for (int i = 0; i < length; ++i)
	{
		if (src[i] == ch)
		{
			if (i - index >= 1)
			{
				len = i - index;
				char* dest = new char[len + 1];
				memcpy(dest, src + index, len);
				dest[len] = 0;
				CCString* temp = new CCString(dest);
				delete[] dest;
				dest=NULL;
				temp->autorelease();
				pdest->addObject(temp);
				++pos;
			}
			index = i + 1;
		}
		else if (i == length - 1)
		{
			len = length - index;
			char* dest = new char[len + 1];
			memcpy(dest, src + index, len);
			dest[len] = 0;
			CCString* temp = new CCString(dest);
			delete[] dest;
			dest=NULL;
			temp->autorelease();
			pdest->addObject(temp);
			++pos;
		}
	}
	pdest->autorelease();
	return pdest;
}

int IsTextUTF8(const char* str,ulong length) 
{ 
	int i; 
	int nBytes = 0;//UFT8可用1-6个字节编码,ASCII用一个字节 
	//ulong chr; 
	bool bAllAscii = true; //如果全部都是ASCII, 说明不是UTF-8 
	uchar chr;
	for(i = 0;i < length;i++) 
	{ 
		chr = str[i]&0xff;
		//chr= *(str+i); 
		if( (chr&0x80) != 0 ) //128 判断是否ASCII编码,如果不是,说明有可能是UTF-8,ASCII用7位编码,但用一个字节存,最高位标记为0,o0xxxxxxx 
			bAllAscii= false; 
		if(nBytes==0) //如果不是ASCII码,应该是多字节符,计算字节数 
		{ 
			if(chr>=0x80) 
			{ 
				if(chr >= 0xFC && chr <= 0xFD) //252 253
					nBytes=6; 
				else if(chr>=0xF8) //248
					nBytes=5; 
				else if(chr>=0xF0) //240
					nBytes=4; 
				else if(chr>=0xE0) //224
					nBytes=3; 
				else if(chr>=0xC0) //192
					nBytes=2; 
				else 
				{ 
					return 0; 
				} 
				nBytes--; 
			} 
		} 
		else //多字节符的非首字节,应为 10xxxxxx 
		{ 
			if( (chr & 0xC0) != 0x80 ) 
			{ 
				return 0; 
			} 
			nBytes--; 
		} 
	} 

	if( nBytes > 0 ) //违返规则 
	{ 
		return 0; 
	} 

	if( bAllAscii ) //如果全部都是ASCII, 说明不是UTF-8 
	{ 
		return 2; 
	} 

	return 1; 
}