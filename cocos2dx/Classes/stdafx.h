// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#include "Top.h"
#include <cstring>
#pragma once
/*
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>*/


#define DIPAN_STATE_BLACK				-3
#define DIPAN_STATE_LOCK				-2
#define DIPAN_STATE_OPEN				-1


//<<<<<<< .mine
#define SERVER_IP		"192.168.1.150"/*"42.96.168.206"*///"192.168.1.100""127.0.0.1"  115.29.140.131
#define SERVER_OUT_IP	/*"115.29.140.131"*//*"192.168.1.102"*/"42.96.168.206"
//=======
//#define SERVER_IP		"42.96.168.206"/*"192.168.1.101"*/   
//>>>>>>> .r24



#define SERVER_PORT		/*11402 */  11100 
#define SOCKET_RECEIVE_BYTE_MAX			1030
#define SOCKET_RECEIVE_BYTE_TEMP_MAX	10000
#define GAME_NETWORK_CMD_MAX			200
#define GAME_NETWORK_TIMEOUT_TIME		(5000)

typedef unsigned long long		u64;
typedef long long				s64;

#define INT_TYPE                                                                    int
#define UNBYTE_TYPE																	unsigned char
#define BYTE_TYPE                                                                   signed char
#define SHORT_TYPE                                                                  short
#define BOOLEAN_TYPE                                                                bool
#define FLOAT_TYPE																	float
#define LONG_TYPE                                                                   s64

#define STRING_REF                                                                  char*
#define STRING_ARRAY_REF                                                            char**
#define STRING_ARRAY_ARRAY_REF														char***

#define GAME_NEW new

#define NOTNULL(x)	(x)

#define INIT_ARRAY(type,objects,length)		{\
	objects = GAME_NEW type[length];\
}


#define INIT_ARRAY_REF(type,objects,length)		{\
	DELETE_ARRAY_REF(objects,length);\
	objects = GAME_NEW type[length];\
}\


#define UNLOAD( variable )	{\
	variable = NULL;\
}

//实例化的指针删除时用这个
//GameLibPlayer *abc = new GameLibPlayer(this);
#define DELETE_VAR( variable )															if NOTNULL(variable)\
{\
	delete variable;\
	variable = 0;\
}

//非实例化的指针删除时用这个
//int *abc = new int [10];
#define DELETE_ARRAY( variable )													if NOTNULL(variable)\
{\
	delete[] variable;\
	variable = 0;\
}

//二位可实例化指针用这个
//ASprite **abc;
//abc = new ASprite *[10];
//循环 -> abc[i] = new ASprite();
#define DELETE_ARRAY_REF(objects,length)		if NOTNULL(objects)\
{\
	for(INT_TYPE dar=0;dar<length;dar++)\
	DELETE_VAR(objects[dar]);\
	DELETE_ARRAY(objects);\
}\
												else objects = NULL;
//二位基础类型指针删除用这个
//int **abc;
//abc = new int *[10];
//循环 -> abc[i] = new int [10];
#define DELETE_ARRAY_ARRAY(objects,length)											if NOTNULL(objects)\
																					{\
																					for(INT_TYPE daa=0;daa<length;daa++)\
																					DELETE_ARRAY(objects[daa]);\
																					DELETE_ARRAY(objects);\
																					}\
																					else objects = NULL;


#define COMMAND_END							-1
#define COMMAND_SUCCESS						1
#define COMMAND_ERROR						107

#if defined( WIN32 )

	#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
	#define _WIN32_DCOM

// 	#include <windows.h>
// 	#include <Vfw.h>
// 	#include <Mmreg.h>
 	#include <math.h>
 	#include <assert.h>
 	#include <stdlib.h>
 	#include <stdio.h>
 	#include <malloc.h>
 	#include <memory.h>
 	#include <string.h>
 	#include <sys/types.h>
// 	#include <sys/stat.h>
// 	#include <fcntl.h>
 	#include <io.h>
// 	#include <limits.h>
// 	#include <signal.h>
 	#include <time.h>
// 	#include "Commctrl.h"
 	#include <wchar.h>
	#include <tchar.h>
	#include <iostream>
#endif

#if defined (IPHONE)
	#include <stddef.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <fcntl.h>
	#include <time.h>
	#include <sys/time.h>
	#include <wchar.h>
	#include <pthread.h>
	#include <unistd.h>
	#include <string.h>
	#include <malloc/malloc.h>
#include "math.h"
#endif


// TODO: reference additional headers your program requires here
