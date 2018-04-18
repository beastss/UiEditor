#include "UiEditorLayoutPanel.h"
#include "UiWidgetImage.h"
#include "UiWidgetsManager.h"
#include "rapidxml/rapidxml_print.hpp"
#include <fstream>
#include "util.h"

USING_NS_CC;
using namespace std;
using namespace rapidxml;

UiEditorLayoutPanel::UiEditorLayoutPanel(cocos2d::CCSize &size)
:m_curSelectedNode(NULL)
, m_layoutSize(size)
{

}

UiEditorLayoutPanel *UiEditorLayoutPanel::create(cocos2d::CCSize &size)
{
	auto layout = new UiEditorLayoutPanel(size);
	layout->init();
	layout->autorelease();
	return layout;
}

void UiEditorLayoutPanel::onEnter()
{
	CCLayer::onEnter();
	UiWidgetsManager::theMgr()->addView(this);
}

void UiEditorLayoutPanel::onExit()
{
	CCLayer::onExit();
	UiWidgetsManager::theMgr()->removeView(this);
}

bool UiEditorLayoutPanel::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	ignoreAnchorPointForPosition(false);
    setTouchEnabled(true);
	setContentSize(m_layoutSize);
	drawFrame();

	auto winSize = CCDirector::sharedDirector()->getWinSize();
	setPosition(winSize.width * 0.5f, winSize.height * 0.5);
	//addClippingNode();
	
	scheduleUpdate();
	return true;
}

void UiEditorLayoutPanel::addClippingNode()
{
	CCLayerColor *back = CCLayerColor::create(ccc4(0, 0, 0, 255));
	back->setContentSize(m_layoutSize);

	auto clip = CCClippingNode::create(back);
	clip->setInverted(false);
	clip->setAlphaThreshold(0.0f);
	addChild(clip);

	auto spr = CCSprite::create("win.png");

	clip->addChild(spr);
}

void UiEditorLayoutPanel::update(float dt)
{
	if (isKeyDown(VK_DELETE))
	{
		removeNode(m_curSelectedNode);
		m_curSelectedNode = NULL;
	}
	else if (isKeyDownUp('V', "UiEditorLayoutPanel"))
	{
		for (size_t i = 0; i < m_widgets.size(); ++i)
		{
			m_widgets[i]->callIdTipsToggle();
		}
	}
}

void UiEditorLayoutPanel::drawFrame()
{
	CCSize size = m_layoutSize;
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
}

void UiEditorLayoutPanel::addNewWidget(UiWidgetNode *node)
{
	addChild(node);
	m_widgets.push_back(node);
}

void UiEditorLayoutPanel::clearNodes()
{
	m_widgets.clear();
}

void UiEditorLayoutPanel::removeNode(UiWidgetNode *node)
{
	auto iter = find(m_widgets.begin(), m_widgets.end(), node);
	if (iter != m_widgets.end())
	{
		node->removeFromParent();
		m_widgets.erase(iter);
	}
}

void UiEditorLayoutPanel::save(std::string &filePath)
{
	xml_document<> doc;
	auto layout = doc.allocate_node(node_element, "layout");

	char str[100] = { 0 };
	sprintf(str, "%f", m_layoutSize.width);
	layout->append_attribute(doc.allocate_attribute("width", doc.allocate_string(str)));
	sprintf(str, "%f", m_layoutSize.height);
	layout->append_attribute(doc.allocate_attribute("height", doc.allocate_string(str)));

	doc.append_node(layout);
	for (auto iter = m_widgets.begin(); iter != m_widgets.end(); ++iter)
	{
		(*iter)->save(doc, layout);
	}
	
	ofstream out(filePath);
	out << doc;

	out.close();
}

void UiEditorLayoutPanel::nodeSelected(UiWidgetNode *node)
{
	m_curSelectedNode = node;
}
