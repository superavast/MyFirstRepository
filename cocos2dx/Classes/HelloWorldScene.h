#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "NetWorkNode.h"
//引入扩展类 
#include "cocos-ext.h" 
//添加命名空间 
using namespace cocos2d::extension; 
//#include "UICCTextField.h"
USING_NS_CC;
using namespace cocos2d::gui;


class HelloWorld : public cocos2d::CCLayer//,public cocos2d::CCTextFieldDelegate//CCIMEDelegate
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	void NetInit();
	void Close(cocos2d::CCObject *obj, TouchEventType eventType);
	void GetLoginText(cocos2d::CCObject *obj, TouchEventType eventType);
	void SChatShout(char* text);
	UILayer*   ul;
	NetWorkNode* netNode;
};

#endif // __HELLOWORLD_SCENE_H__
