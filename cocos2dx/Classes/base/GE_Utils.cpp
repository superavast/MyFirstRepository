// #include "GE_Utils.h"
// 
// bool GE_Utils::Compress(void* dest, int* destSize, const void* src, int srcSize, int level)
// {
// 	if(compress2((Bytef*)dest, (uLongf*)destSize, (Bytef*)src, srcSize, level) == Z_OK)
// 	{
// 		return true;
// 	}
// 
// 	return false;
// }
// 
// bool GE_Utils::Decompress(void* dest, int* destSize, const void* src, int srcSize)
// {
// 	if(uncompress((Bytef*)dest, (uLongf*)destSize, (Bytef*)src, srcSize) == Z_OK)
// 	{
// 		return true;
// 	}
// 
// 	return false;
// }
// 
// int GE_Utils::GetMaxCompressSize(int srcSize)
// {
// 	int destSize = (int)(srcSize * 1.001 + 12 + 0.5);
// 
// 	return destSize;
// }
// 
// bool GE_Utils::IsCanInflate(const void* src, int srcSize, int level)
// {
// 	int destSize = GetMaxCompressSize(srcSize);
// 	char* dest = new char[destSize];
// 
// 	if(dest == NULL)
// 	{
// 		return false;
// 	}
// 
// 	if(!Compress(dest, &destSize, src, srcSize, level))
// 	{
// 		delete [] dest;
// 		return false;
// 	}
// 
// 	delete [] dest;
// 
// 	if(destSize >= srcSize)
// 	{
// 		return false;
// 	}
// 
// 	return true;
// }
// 
// int GE_Utils::SplitString(const string& input,const string& delimiter, strary& output)
// {
// 	if(input.size() == 0)
// 	{
// 		return 0;
// 	}
// 
// 	if(delimiter.size() == 0)
// 	{
// 		output.push_back(input);
// 
// 		return 1;
// 	}
// 
// 	int startIndex = 0;
// 	int findIndex = 0;
// 	int count = 0;
// 
// 	while(true)
// 	{
// 		findIndex = input.find(delimiter, startIndex);
// 		if(findIndex == -1)
// 		{
// 			if(startIndex != input.size())
// 			{
// 				output.push_back(input.substr(startIndex, input.size() - startIndex));
// 				++count;
// 			}
// 
// 			break;
// 		}
// 
// 		int length = findIndex - startIndex;
// 		if(length > 0)
// 		{
// 			output.push_back(input.substr(startIndex, length));
// 		}
// 
// 		startIndex = findIndex + 1;
// 
// 		++count;
// 	}
// 
// 	return count;
// }
// 
// int GE_Utils::SplitString2(const string& input, const string& delimiter, strary& output)
// {
// 	if(input.size() == 0)
// 	{
// 		return 0;
// 	}
// 
// 	if(delimiter.size() == 0)
// 	{
// 		output.push_back(input);
// 
// 		return 1;
// 	}
// 
// 	int startIndex = 0;
// 	int findIndex = 0;
// 	int count = 0;
// 
// 	while(true)
// 	{
// 		findIndex = -1;
// 
// 		for(uint i = 0; i < delimiter.length(); ++i)
// 		{
// 			int fi = input.find(delimiter[i], startIndex);
// 
// 			if(fi != -1)
// 			{
// 				if(findIndex == -1)
// 				{
// 					findIndex = fi;
// 				}
// 				else if(fi < findIndex)
// 				{
// 					findIndex = fi;
// 				}
// 			}
// 		}
// 
// 		if(findIndex == -1)
// 		{
// 			if(startIndex != input.size())
// 			{
// 				output.push_back(input.substr(startIndex, input.size() - startIndex));
// 				++count;
// 			}
// 
// 			break;
// 		}
// 
// 		int length = findIndex - startIndex;
// 		if(length > 0)
// 		{
// 			output.push_back(input.substr(startIndex, length));
// 		}
// 
// 		startIndex = findIndex + 1;
// 
// 		++count;
// 	}
// 
// 	return count;
// }
// 
// wstring GE_Utils::A2U(const string& str)
// {
// 	wstring ret;
// 
// 	ret.resize(str.size());
// 
// 	for(size_t i = 0; i < str.size(); ++i)
// 	{
// 		ret[i] = (wstring::value_type)str[i];
// 	}
// 
// 	return ret;
// }
// 
// string GE_Utils::U2A(const wstring& str)
// {
// 	string ret;
// 
// 	ret.resize(str.size());
// 
// 	for(size_t i = 0; i < str.size(); ++i)
// 	{
// 		ret[i] = (string::value_type)str[i];
// 	}
// 
// 	return ret;
// }
// 
// int GE_Utils::String2Number(string& str)
// {
// 	return atoi(str.c_str());
// }
// 
// int GE_Utils::UnicodeToUTF8(const wstring& unicode, string& utf8)
// {
// 	int utflen = 0;
// 	for(size_t i = 0; i < unicode.length(); ++i)
// 	{
// 		wchar_t ch = unicode[i];
// 
// 		if((ch >= 0x0001) && (ch <= 0x007F))
// 		{
// 			utflen++;
// 		}
// 		else if(ch > 0x07FF)
// 		{
// 			utflen += 3;
// 		}
// 		else
// 		{
// 			utflen += 2;
// 		}
// 	}
// 
// 	utf8.resize(utflen);
// 
// 	int index = 0;
// 	for (size_t i = 0; i < unicode.length(); i++)
// 	{
// 		wchar_t ch = unicode[i];
// 
// 		if((ch >= 0x0001) && (ch <= 0x007F))
// 		{
// 			utf8[index++] = (char) ch;
// 		}
// 		else if(ch > 0x07FF)
// 		{
// 			utf8[index++] = (char) (0xE0 | ((ch >> 12) & 0x0F));
// 			utf8[index++] = (char) (0x80 | ((ch >>  6) & 0x3F));
// 			utf8[index++] = (char) (0x80 | ((ch >>  0) & 0x3F));
// 		}
// 		else
// 		{
// 			utf8[index++] = (char) (0xC0 | ((ch >>  6) & 0x1F));
// 			utf8[index++] = (char) (0x80 | ((ch >>  0) & 0x3F));
// 		}
// 	}
// 
// 	return utflen;
// }
// 
// int GE_Utils::UTF8ToUnicode(const string& utf8, wstring& unicode)
// {
// 	int ch1, ch2, ch3;
// 	int index = 0;
// 
// 	unicode.resize(utf8.length());
// 
// 	for(uint i = 0; i < utf8.length(); )
// 	{
// 		ch1 = (int) utf8[i] & 0xff;
// 
// 		switch(ch1 >> 4)
// 		{
// 		case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:
// 			/* 0xxxxxxx*/
// 			unicode[index++] = (wchar_t)ch1;
// 			i++;
// 			break;
// 		case 12: case 13:
// 			/* 110x xxxx   10xx xxxx*/
// 			ch2 = (int)utf8[i + 1];
// 			unicode[index++] = (wchar_t)(((ch1 & 0x1F) << 6) | (ch2 & 0x3F));
// 			i += 2;
// 			break;
// 		case 14:
// 			/* 1110 xxxx  10xx xxxx  10xx xxxx */
// 			ch2 = (int)utf8[i + 1];
// 			ch3 = (int)utf8[i + 2];
// 			unicode[index++] = (wchar_t)(((ch1 & 0x0F) << 12) | ((ch2 & 0x3F) << 6) | ((ch3 & 0x3F) << 0));
// 			i += 3;
// 			break;
// 		default:
// 			/* 10xx xxxx,  1111 xxxx */
// 			return -1;
// 		}
// 	}
// 
// 	return index;
// }
// 
