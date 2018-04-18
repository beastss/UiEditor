#ifndef __MAINSCENE_H__
#define __MAINSCENE_H__

#include "cocos2d.h"

class MainScene : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(MainScene);
};

#endif 
