#include "stdafx.h"
#include "CinStream.h"

void  CinStream::setData(char* v, int length)
{
	if (datelength > 0)
		DELETE_ARRAY( date ) ;

	date = v;
	point = 0;
	datelength = length;
}

void CinStream::ResetPointer()
{
	point = 0;
}

bool CinStream::readBoolean()
{
	return readByte() != 0; 
}

char CinStream::readByte()
{
	char val = date[point];
	point ++;
	return val&0xff;
}

char* CinStream::readBytes(int length)
{
	char *val = new char[length];
	memcpy( val, date + point, length);
	point += length;
	return val;
}

short CinStream::readShort()	
{ 
	char r1 = readByte(); 
	char r2 = readByte();

	return ((r2&0x000000ff) | ((r1&0x000000ff) << 8)); 
}

int CinStream::readInt()
{
	char r1 = readByte();
	char r2 = readByte();
	char r3 = readByte();
	char r4 = readByte();
		
	return ((r4&0x000000ff) | ((r3&0x000000ff) << 8) | ((r2&0x000000ff)<< 16) | ((r1&0x000000ff) << 24));
}

std::string CinStream::readUTF()	
{
	int length = readShort();

	char *val = new char[length+1];

	memcpy(val, date + point, length);
	point += length;

	val[length] = '\0';

	std::string tmp = std::string(val);
	delete[] val;
	return tmp;
}

LONG_TYPE CinStream::readLong()
{
	LONG_TYPE r1 = readInt() ;
	LONG_TYPE r2 = readInt() ;

	return ((r1&0xffffffff) << 32) | (r2&0xffffffff) ;
}