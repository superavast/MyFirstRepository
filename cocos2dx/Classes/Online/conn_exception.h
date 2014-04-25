#pragma once

#include <string>
#include <exception>

using std::string;
using std::exception;

#if defined CC_TARGET_OS_IPHONE || defined ANDROID
    typedef unsigned long   DWORD;
    #define errno 0
#endif

//connection exception
class ConnException : public exception
{
public:
	int exc;
	string msg;
	DWORD err;

public:
	ConnException(int e,const string str,DWORD er){
		exc=e;
		msg=str;
		err=er;
	}
#if defined CC_TARGET_OS_IPHONE || defined ANDROID
    ~ConnException() throw()
    {
        
    };
#elif defined WIN32
	~ConnException(){
	}
#endif
};
