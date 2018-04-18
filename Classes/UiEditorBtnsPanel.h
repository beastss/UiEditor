#ifndef __UIEDITORBTNSPANEL_H__
#define __UIEDITORBTNSPANEL_H__

#include "cocos2d.h"
#include <string.h>
using namespace std;
class UiEditorBtnsPanel
	: public cocos2d::CCLayer
{
public:
    virtual bool init();  
    CREATE_FUNC(UiEditorBtnsPanel);
private:
	virtual void onEnter();
	virtual void onExit();
	cocos2d::CCMenuItemSprite *getBtnWithLabel(const char* str, cocos2d::SEL_MenuHandler selector);
private:
	void initWidgetsBtn();
	void onButtonBtnClicked(cocos2d::CCObject* pSender);
	void onImageBtnClicked(cocos2d::CCObject* pSender);
	void onLabelBtnClicked(cocos2d::CCObject* pSender);
	void onEmptyBoxBtnClicked(cocos2d::CCObject* pSender);
	void onImageNumBtnClicked(cocos2d::CCObject* pSender);
	void onAnimationBtnClicked(cocos2d::CCObject* pSender);
private:
	string openPath();
	void initFuncsBtn();
	void onUpdateBtnClicked(cocos2d::CCObject* pSender);
	void onSaveBtnClicked(cocos2d::CCObject* pSender);
	void onOpenBtnClicked(cocos2d::CCObject* pSender);
	void onCloseBtnClicked(cocos2d::CCObject* pSender);
	void onShowXmlBtnClicked(cocos2d::CCObject* pSender);

};

#endif 
