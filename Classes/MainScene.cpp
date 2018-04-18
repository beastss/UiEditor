#include "MainScene.h"
#include "UiEditorPanel.h"
#include "UiWidgetsManager.h"
USING_NS_CC;

CCScene* MainScene::scene()
{
	CCScene *scene = CCScene::create();
	MainScene *layer = MainScene::create();
	scene->addChild(layer);
	return scene;
}

bool MainScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	
	CCLayerColor *bg = CCLayerColor::create(ccc4(60, 60, 60, 255));
	addChild(bg);

    UiWidgetsManager::theMgr()->init();
    
	auto panel = UiEditorPanel::create();
	addChild(panel);

	return true;
}


