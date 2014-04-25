#pragma once

#include <string>
#include "stdafx.h"
#define OUTSTREAM_POOL_MAX		100000

class CoutStream
{
public:
	char* data;
	int point;
	int datalength;
public:
	CoutStream(void){
		data = NULL;
		INIT_ARRAY( char , data , OUTSTREAM_POOL_MAX );
		point = 0;
		datalength = OUTSTREAM_POOL_MAX;
	}
	~CoutStream(void){
		if (datalength > 0)
			DELETE_ARRAY(data);
		datalength = 0;
	}

	void reset();
	int getDataLength();
	char* getData();
	void writeInt(int v);
//	void writeLong(LONG_TYPE l);
	void writeUTF(std::string& str);
	void writeByte(char v) ;
	void writeBytes(char* v, int length) ;
	void writeBoolean(bool v);
	void writeShort(short v);
	void writeLong(LONG_TYPE v);
};
