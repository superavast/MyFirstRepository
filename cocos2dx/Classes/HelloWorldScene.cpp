#include "HelloWorldScene.h"
#include "CmdMaker.h"

//引入扩展类 
#include "cocos-ext.h" 
//添加命名空间 
using namespace cocos2d::extension; 
//#include "UICCTextField.h"
USING_NS_CC;
using namespace cocos2d::gui;

CCScene* HelloWorld::scene()
{

    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}


void HelloWorld::NetInit()
{
	netNode=new NetWorkNode();
	//	netNode->InOrOut=InOrOut;
// 	if(InOrOut==0)
// 	{
// 		netNode->curSERVER_IP=SERVER_IP;
// 	}
// 	else
// 	{
// 		netNode->curSERVER_IP=SERVER_OUT_IP;
// 	}
	netNode->init();
}
// void HelloWorld::NetReconnect(cocos2d::CCObject *pSender)
// {
// 	NetWorkNode::retry();
//// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
     NetInit();
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);

	
  //创建一个UILayer层 
    ul =UILayer::create(); 
    //将UILayer层加入到当前的场景 
    this->addChild(ul); 
	ul->setTag(10026);
    //使用json文件给Layer层添加CocoStudio生成的控件 
    ul->addWidget(GUIReader::shareReader()->widgetFromJsonFile("\\json\\DemoLogin.json")); 
	UIButton* CloseButton = dynamic_cast<UIButton*>(ul->getWidgetByName("close_Button"));
	CloseButton->addTouchEventListener(this,toucheventselector(HelloWorld::Close));
	UIButton* LoginButton = dynamic_cast<UIButton*>(ul->getWidgetByName("login_Button"));
	LoginButton->addTouchEventListener(this,toucheventselector(HelloWorld::GetLoginText));
	this->addChild(netNode);
    return true;
}
void HelloWorld::GetLoginText(cocos2d::CCObject *obj, TouchEventType eventType)
{
	switch (eventType)
	{
	case TOUCH_EVENT_ENDED:
		 {
			 ul = (UILayer*)this->getChildByTag(10026);
			 TextField* LoginText = dynamic_cast<TextField*>(ul->getWidgetByName("name_TextField"));
			 string text = LoginText->getStringValue();
			 CCLOG("login text = %s",text.c_str());
		 }
		 break;
	default:
		break;
	}
}
void HelloWorld::SChatShout(char* text)
{
	
}
void HelloWorld::Close(cocos2d::CCObject *obj, TouchEventType eventType)
{
	 CCDirector::sharedDirector()->end();
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
 //   CCDirector::sharedDirector()->end();
	
	CMD_User_LoginGame_up* cmd=(CMD_User_LoginGame_up*)CmdMaker::CmdFactory(CMD_LOGIN);
	CmdMaker::setNetCallback(CMD_LOGIN,this,NULL/*callfuncO_selector(NULL)*/); 
	cmd->userName = "wwwww";
	cmd->password = "qqqqqq";
	//cmd->ver=serverVer;
	netNode->AddToCommandList(cmd);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
