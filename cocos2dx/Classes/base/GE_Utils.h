#if 0//ndef __GE_UTILS_H__
#define __GE_UTILS_H__

//#include "NET_Base.h"
#include "GE_Base.h"
#include "zlib.h"

class GE_Utils
{
public:
	static bool Compress(void* dest, int* destSize, const void* src, int srcSize, int level);
	static bool Decompress(void* dest, int* destSize, const void* src, int srcSize);
	static int GetMaxCompressSize(int srcSize);
	static bool IsCanInflate(const void* src, int srcSize, int level);

	static int SplitString(const string& input, const string& delimiter, strary& output);
	static int SplitString2(const string& input, const string& delimiter, strary& output);
	static wstring A2U(const string& str);
	static string U2A(const wstring& str);
	static int String2Number(string& str);

	static int UnicodeToUTF8(const wstring& unicode, string& utf8);
	static int UTF8ToUnicode(const string& utf8, wstring& unicode);

private:
	GE_Utils(){}
	~GE_Utils(){}
};

#endif /*__GE_UTILS_H__*/


