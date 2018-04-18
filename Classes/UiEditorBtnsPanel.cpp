#include "UiEditorBtnsPanel.h"
#include "UiWidgetsManager.h"
//#include <shlobj.h>
USING_NS_CC;
void UiEditorBtnsPanel::onEnter()
{
	CCLayer::onEnter();
}

void UiEditorBtnsPanel::onExit()
{
	CCLayer::onExit();
}

bool UiEditorBtnsPanel::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	initFuncsBtn();
	initWidgetsBtn();
	return true;
}

void UiEditorBtnsPanel::initWidgetsBtn()
{
	auto winsize = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemSprite* imageBtn = getBtnWithLabel("image", menu_selector(UiEditorBtnsPanel::onImageBtnClicked));
	imageBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.45f));
	CCMenuItemSprite* buttonBtn = getBtnWithLabel("button", menu_selector(UiEditorBtnsPanel::onButtonBtnClicked));
	buttonBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.35f));
	CCMenuItemSprite* labelBtn = getBtnWithLabel("label", menu_selector(UiEditorBtnsPanel::onLabelBtnClicked));
	labelBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.25f));
	CCMenuItemSprite* emptyBoxBtn = getBtnWithLabel("emptyBox", menu_selector(UiEditorBtnsPanel::onEmptyBoxBtnClicked));
	emptyBoxBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.15f));
	CCMenuItemSprite* imageNumBtn = getBtnWithLabel("imageNum", menu_selector(UiEditorBtnsPanel::onImageNumBtnClicked));
	imageNumBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * 0.05f));
	CCMenuItemSprite* animationBtn = getBtnWithLabel("animation", menu_selector(UiEditorBtnsPanel::onAnimationBtnClicked));
	animationBtn->setPosition(ccp(-winsize.width * 0.45f, winsize.height * -0.05f));

	CCMenu *menu = CCMenu::create();
	menu->addChild(imageBtn);
	menu->addChild(buttonBtn);
	menu->addChild(labelBtn);
	menu->addChild(emptyBoxBtn);
	menu->addChild(imageNumBtn);
	menu->addChild(animationBtn);
	addChild(menu);
}

void UiEditorBtnsPanel::initFuncsBtn()
{
	/*
	auto winsize = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemSprite* updateBtn = getBtnWithLabel("update", menu_selector(UiEditorBtnsPanel::onUpdateBtnClicked));
	updateBtn->setPosition(ccp(-winsize.width * 0.1f, -winsize.height * 0.45f));
	CCMenuItemSprite* saveBtn = getBtnWithLabel("save", menu_selector(UiEditorBtnsPanel::onSaveBtnClicked));
	saveBtn->setPosition(ccp(winsize.width * 0.0f, -winsize.height * 0.45f));
	CCMenuItemSprite* openBtn = getBtnWithLabel("open", menu_selector(UiEditorBtnsPanel::onOpenBtnClicked));
	openBtn->setPosition(ccp(winsize.width * 0.1f, -winsize.height * 0.45f));
	CCMenuItemSprite* closeBtn = getBtnWithLabel("close", menu_selector(UiEditorBtnsPanel::onCloseBtnClicked));
	closeBtn->setPosition(ccp(winsize.width * 0.2f, -winsize.height * 0.45f));
	*/

	auto winsize = CCDirector::sharedDirector()->getWinSize();
	CCMenuItemSprite* openBtn = getBtnWithLabel("open", menu_selector(UiEditorBtnsPanel::onOpenBtnClicked));
	openBtn->setPosition(ccp(winsize.width * 0.45f, -winsize.height * 0.15f));
	CCMenuItemSprite* saveBtn = getBtnWithLabel("save", menu_selector(UiEditorBtnsPanel::onSaveBtnClicked));
	saveBtn->setPosition(ccp(winsize.width * 0.45f, -winsize.height * 0.25f));
	CCMenuItemSprite* updateBtn = getBtnWithLabel("update", menu_selector(UiEditorBtnsPanel::onUpdateBtnClicked));
	updateBtn->setPosition(ccp(winsize.width * 0.45f, -winsize.height * 0.35f));
	CCMenuItemSprite* closeBtn = getBtnWithLabel("close", menu_selector(UiEditorBtnsPanel::onCloseBtnClicked));
	closeBtn->setPosition(ccp(winsize.width * 0.45f, -winsize.height * 0.45f));
	CCMenuItemSprite* openXmlBtn = getBtnWithLabel("xml", menu_selector(UiEditorBtnsPanel::onShowXmlBtnClicked));
	openXmlBtn->setPosition(ccp(winsize.width * 0.45f, winsize.height * 0.45f));

	CCMenu *menu = CCMenu::create();
	menu->addChild(updateBtn);
	menu->addChild(saveBtn);
	menu->addChild(openBtn);
	menu->addChild(closeBtn);
	menu->addChild(openXmlBtn);
	addChild(menu);
}

static CCNode *getBtnSprite(const char *str)
{
	const char* path = "ui/btn.png";
	CCNode *node = CCNode::create();
	auto spr = CCSprite::create(path);
	auto size = spr->getContentSize();
	spr->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
	node->addChild(spr);

	CCLabelTTF* pLabel = CCLabelTTF::create(str, "Arial", 24);
	pLabel->setAnchorPoint(ccp(0.5f, 0.5f));
	pLabel->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
	node->addChild(pLabel);

	node->setContentSize(size);
	return node;
}

CCMenuItemSprite *UiEditorBtnsPanel::getBtnWithLabel(const char* str, SEL_MenuHandler selector)
{
	CCNode* sItem = getBtnSprite(str);
	CCNode* sSelItem = getBtnSprite(str);
	float scale = 1.1f;
	sSelItem->setScale(scale);
	CCMenuItemSprite* menuItem = CCMenuItemSprite::create(sItem, sSelItem, this, selector);
	sSelItem->setAnchorPoint(ccp((scale - 1.0f) * 0.5f, (scale - 1.0f) * 0.5f));
	return menuItem;
}

void UiEditorBtnsPanel::onLabelBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("label");
}

void UiEditorBtnsPanel::onButtonBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("button");
}

void UiEditorBtnsPanel::onImageBtnClicked(cocos2d::CCObject* pSender)
{

	//UiWidgetsManager::theMgr()->openImage();
	UiWidgetsManager::theMgr()->createWidgetByName("image");

}

void UiEditorBtnsPanel::onEmptyBoxBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("emptyBox");
}

void UiEditorBtnsPanel::onImageNumBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("imageNum");
}

void UiEditorBtnsPanel::onAnimationBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->createWidgetByName("animation");
}

void UiEditorBtnsPanel::onUpdateBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->refresh();
}

void UiEditorBtnsPanel::onSaveBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->save();
}
//读取xml文件路径
void UiEditorBtnsPanel::onOpenBtnClicked(cocos2d::CCObject* pSender)
{
	/*OPENFILENAMEA ofn;
	char szFile[MAX_PATH];

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	CCLOG(szFile);
	ofn.lpstrFile[0] = 0;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "xml file\0*.xml\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (::GetOpenFileNameA(&ofn))
	{

	}*/
	string path = openPath();
	if (path.size()>=1)
	{
		UiWidgetsManager::theMgr()->openNewLayout(path.c_str());
	}
	
}

string UiEditorBtnsPanel::openPath()
{
	OPENFILENAMEA ofn;
	char szFile[MAX_PATH];

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	CCLOG(szFile);
	ofn.lpstrFile[0] = 0;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = "xml file\0*.xml\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (::GetOpenFileNameA(&ofn))
	{
		string tem = szFile;
		return tem;
	}
	else
	{
		return "";
	}
}

void UiEditorBtnsPanel::onCloseBtnClicked(cocos2d::CCObject* pSender)
{
	UiWidgetsManager::theMgr()->closeCurLayout();
}

void UiEditorBtnsPanel::onShowXmlBtnClicked(cocos2d::CCObject* pSender)
{
	auto fullPath = UiWidgetsManager::theMgr()->getCurFileName();
	if (!fullPath.empty())
	{
		system(fullPath.c_str());
	}
}
