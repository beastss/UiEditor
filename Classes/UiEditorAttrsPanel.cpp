#include "UiEditorAttrsPanel.h"
#include "UiWidgetNode.h"

USING_NS_CC;
bool AttrPrintPad::init()
{
	auto winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite *padSpr = CCSprite::create("ui/pad.png");
	padSpr->setAnchorPoint(ccp(0, 0));
	padSpr->setScaleX(0.5f);
	padSpr->setScaleY(1.5f);
	auto rect = padSpr->boundingBox();
	addChild(padSpr);
	setContentSize(rect.size);

	m_maxLabelHeight = rect.size.height;
	m_nextLabelHeight = m_maxLabelHeight;

	return true;
}

void AttrPrintPad::addStr(const char *str)
{
	const float kSpacing = 10;

	auto label = CCLabelTTF::create(str, "Arial", 24);
	addChild(label);
	label->setAnchorPoint(ccp(0, 1));
	label->setPosition(ccp(0, m_nextLabelHeight));
	m_nextLabelHeight -= label->getContentSize().height + kSpacing;
}

void AttrPrintPad::clearPad()
{
	removeAllChildren();
	init();
}

void UiEditorAttrsPanel::onEnter()
{
	CCNode::onEnter();
	UiWidgetsManager::theMgr()->addView(this);
}

void UiEditorAttrsPanel::onExit()
{
	CCNode::onExit();
	UiWidgetsManager::theMgr()->removeView(this);
}

bool UiEditorAttrsPanel::init()
{
	auto winSize = CCDirector::sharedDirector()->getWinSize();
	m_nameLabel = CCLabelTTF::create("", "Arial", 24);
	m_nameLabel->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.97f));
	addChild(m_nameLabel);

	m_printPad = AttrPrintPad::create();
	m_printPad->setAnchorPoint(ccp(1, 1));
	m_printPad->setPosition(ccp(winSize.width, winSize.height * 0.9f));
	addChild(m_printPad);
	return true;
}

void UiEditorAttrsPanel::newLayout(CCSize &size)
{
	m_printPad->clearPad();
	refreshFileName();
}

void UiEditorAttrsPanel::closeLayout()
{
	m_printPad->clearPad();
	refreshFileName();
}

void UiEditorAttrsPanel::nodeSelected(UiWidgetNode *node)
{
	m_printPad->clearPad();
	auto strs = node->selectedPrint();
	for (size_t i = 0; i < strs.size(); ++i)
	{
		m_printPad->addStr(strs[i].c_str());
	}
}

void UiEditorAttrsPanel::refreshFileName()
{
	auto fullPath = UiWidgetsManager::theMgr()->getCurFileName();
	auto fileName = fullPath.substr(fullPath.rfind("\\") + 1);
	m_nameLabel->setString(fileName.c_str());
}
