#include "AppDelegate.h"
#include "MainScene.h"

USING_NS_CC;
using namespace std;
AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

	pEGLView->setFrameSize(1440, 1000);

    pDirector->setOpenGLView(pEGLView);
	
	CCFileUtils::sharedFileUtils()->addSearchPath("..\\assets");
	CCFileUtils::sharedFileUtils()->addSearchPath("..\\Resources");

	//CCFileUtils::sharedFileUtils()->addSearchPath("E:\\cocos2d-x-2.2.3\\projects\\CuteSnake\\proj.zydm.cutesnake\\assets");
	CCFileUtils::sharedFileUtils()->addSearchPath("E:\\cocos2d-x-2.2.3\\dddd\\");
	//auto paths = CCFileUtils::sharedFileUtils()->getSearchPaths();

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    CCScene *pScene = MainScene::scene();
	
    // run
    pDirector->runWithScene(pScene);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
