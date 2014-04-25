#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include "Top.h"
#include "CCObject.h"
/*
µ¥ÀýÄ£Ê½
*/
template <typename T>
class Singleton :public cocos2d::CCObject
{
public:
	inline static T* getInstance();
	inline static void releaseInstance();
	void init();
private:
	static T* t;
};

template <typename T>
inline T* Singleton<T>::getInstance()
{
	if (!t)
	{
		t = new T;
		t->init();
	}
	return t;
}

template<typename T>
inline void Singleton<T>::releaseInstance()
{
	if (t)
	{
		delete t;
		t = 0;
	}
}

template <typename T> 
T* Singleton<T>::t = 0;

#endif // __SINGLE_H__