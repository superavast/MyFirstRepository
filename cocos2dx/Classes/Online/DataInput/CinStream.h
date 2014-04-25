#pragma once

#include <string>

class CinStream
{
private:

public:
	CinStream(void)
	{
		date = NULL;
		datelength = 0;
	}
	CinStream(char* v, int length)
	{
		date = v;
		point = 0;
		datelength = length;
	}
	virtual ~CinStream(void)
	{
		if (datelength > 0)
			DELETE_ARRAY( date ) ;
	}

	char* date;
	int point;
	int datelength;
	void setData(char* v, int length);
	void setData(char* v)
	{
		if (datelength > 0)
			DELETE_ARRAY( date ) ;
		date = v;
	}
	void setDataLength( int length)
	{
		datelength = length;
	}
	void ResetPointer();

	bool readBoolean();
	int readInt();
	char readByte();
	char* readBytes(int length);
	short readShort();
	std::string readUTF();
	LONG_TYPE readLong();
};
