#include "UiEditorPanel.h"
#include "UiEditorBtnsPanel.h"
#include "UiEditorAttrsPanel.h"
#include "util.h"
#include "UiEditorLayoutPanel.h"

USING_NS_CC;

UiEditorPanel::UiEditorPanel()
:m_curLayout(NULL)
{

}

bool UiEditorPanel::init()
{
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	setContentSize(winSize);

	drawFrame();
	addChild(UiEditorBtnsPanel::create());
	addChild(UiEditorAttrsPanel::create());
	//scheduleUpdate();
	return true;
}
    
void UiEditorPanel::onEnter()
{
	CCNode::onEnter();
	UiWidgetsManager::theMgr()->addView(this);
}

void UiEditorPanel::onExit()
{
	CCNode::onExit();
	UiWidgetsManager::theMgr()->removeView(this);
}


void UiEditorPanel::update(float dt)
{
	
}

void UiEditorPanel::drawFrame()
{
	CCSize size = CCSize(1000, 800);

	CCPoint leftBottom(0, 0);
	CCPoint leftTop(0, size.height);
	CCPoint rightBottom(size.width, 0);
	CCPoint rightTop(size.width, size.height);

	CCDrawNode *drawNode = CCDrawNode::create();
	addChild(drawNode);

	drawNode->drawSegment(leftBottom, rightBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightBottom, rightTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightTop, leftTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(leftTop, leftBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));

	auto winSize = CCDirector::sharedDirector()->getWinSize();
	auto offset = ccp((winSize.width - size.width) * 0.5f, (winSize.height - size.height) * 0.5f);
	drawNode->setPosition(offset);
}

void UiEditorPanel::newLayout(CCSize &size)
{
	removeCurLayout();
	m_curLayout = UiEditorLayoutPanel::create(size);
	addChild(m_curLayout);
}

void UiEditorPanel::closeLayout()
{
	removeCurLayout();
}

void UiEditorPanel::removeCurLayout()
{
	if (m_curLayout)
	{
		m_curLayout->removeFromParentAndCleanup(true);
		m_curLayout = NULL;
	}
}