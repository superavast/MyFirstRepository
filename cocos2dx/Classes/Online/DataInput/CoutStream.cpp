#include "stdafx.h"
#include "CoutStream.h"

void CoutStream::reset()
{
	point = 0;
}

char* CoutStream::getData()
{
	return data;
}

int CoutStream::getDataLength()
{
	return point;
}

void CoutStream::writeInt(int v)
{
	char bAry[4];
	char* lpAry = bAry;
	*( int* )lpAry = v;

	data[point++] = lpAry[3];
	data[point++] = lpAry[2];
	data[point++] = lpAry[1];
	data[point++] = lpAry[0];
}

// void CoutStream::writeLong(LONG_TYPE pValue)
// {
// 	for(int j = 0; j < 8; j++)
// 	{
// 		data[point++] = (pValue >> (j * 8)) & 0xff;
// 	}
// }

void CoutStream::writeUTF(std::string& str)
{
	const char* v = str.c_str();
	short length = strlen(v);
	writeShort(length);
	for(int i = 0;i < length;i ++)
	{
		data[point++] = v[i];
	}
}

void CoutStream::writeByte(char v)
{
	data[point++] = v;
}

void CoutStream::writeBytes(char* v, int length) 
{
	memcpy( data + point, v, length);
	point += length;
}

void CoutStream::writeBoolean(bool v)
{
	data[point++] = v?1:0;
}

void CoutStream::writeShort(short v)
{
	char bAry[2];
	char* lpAry = bAry;
	*( short* )lpAry = v;

	data[point++] = lpAry[1];
	data[point++] = lpAry[0];
}

void CoutStream::writeLong(LONG_TYPE v)
{
	char bAry[8];
	char* lpAry = bAry;
	*( LONG_TYPE* )lpAry = v;

	data[point++] = lpAry[7];
	data[point++] = lpAry[6];
	data[point++] = lpAry[5];
	data[point++] = lpAry[4];
	data[point++] = lpAry[3];
	data[point++] = lpAry[2];
	data[point++] = lpAry[1];
	data[point++] = lpAry[0];
}
