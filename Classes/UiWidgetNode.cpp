#include "UiWidgetNode.h"
#include "UiWidgetsManager.h"
USING_NS_CC;
using namespace std;
using namespace rapidxml;

UiWidgetNode::UiWidgetNode(int touchPriority)
: m_isShowIdTips(false)
, m_idTips(NULL)
{

}

bool UiWidgetNode::init()
{
	return true;
}

void UiWidgetNode::onEnter(){
	CCNode::onEnter();
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
}

void UiWidgetNode::onExit(){
	CCNode::onExit();
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool UiWidgetNode::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	auto pos = convertToNodeSpace(pTouch->getLocation());
	auto size = getContentSize();
	CCRect rect(0, 0, size.width, size.height);

	if (rect.containsPoint(pos))
	{
		m_oldPos = getParent()->convertToNodeSpace(pTouch->getLocation());
		onTouchBegan();
		UiWidgetsManager::theMgr()->nodeSelected(this);
		return true;
	}
	return false;
}

void UiWidgetNode::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	auto worldPos = pTouch->getLocation();
	auto curPos = getParent()->convertToNodeSpace(worldPos);
	
	auto offset = ccpSub(curPos, m_oldPos);
	setPosition(ccpAdd(getPosition(), offset));
	m_oldPos = curPos;
}

void UiWidgetNode::drawFrame()
{
	CCSize size = getContentSize();
	CCPoint leftBottom(0, 0);
	CCPoint leftTop(0, size.height);
	CCPoint rightBottom(size.width, 0);
	CCPoint rightTop(size.width, size.height);

	CCDrawNode *drawNode = CCDrawNode::create();
	addChild(drawNode, 1);

	drawNode->drawSegment(leftBottom, rightBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightBottom, rightTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(rightTop, leftTop, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
	drawNode->drawSegment(leftTop, leftBottom, 0.5f, ccc4f(0.5f, 0.5f, 0.5f, 1));
}

void UiWidgetNode::initBaseInfo(rapidxml::xml_node<> *node)
{
	int id = atoi(node->first_node("id")->value());
	m_id = UiWidgetsManager::theMgr()->getWidgetId(id);
    float x = atof(node->first_node("x")->value());
    float y = atof(node->first_node("y")->value());
	float anchorPtX = atof(node->first_node("anchorPtX")->value());
	float anchorPtY = atof(node->first_node("anchorPtY")->value());
	float scale = atof(node->first_node("scale")->value());
    setPosition(ccp(x, y));
	setAnchorPoint(ccp(anchorPtX, anchorPtY));
	setScale(scale);
}

void UiWidgetNode::saveBaseInfo(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	char str[100] = { 0 };

	sprintf(str, "%d", m_id);
	node->append_node(doc.allocate_node(node_element, "id", doc.allocate_string(str)));

	sprintf(str, "%.02f", getPositionX());
	node->append_node(doc.allocate_node(node_element, "x", doc.allocate_string(str)));

	sprintf(str, "%.02f", getPositionY());
	node->append_node(doc.allocate_node(node_element, "y", doc.allocate_string(str)));
	
	sprintf(str, "%.02f", getAnchorPoint().x);
	node->append_node(doc.allocate_node(node_element, "anchorPtX", doc.allocate_string(str)));

	sprintf(str, "%.02f", getAnchorPoint().y);
	node->append_node(doc.allocate_node(node_element, "anchorPtY", doc.allocate_string(str)));

	sprintf(str, "%.02f", getScale());
	node->append_node(doc.allocate_node(node_element, "scale", doc.allocate_string(str)));
}

CCNode *UiWidgetNode::getIdTips()
{
	CCNode *node = CCNode::create();
	CCSize tipSize = CCSize(20, 20);
	CCLayerColor *bg = CCLayerColor::create(ccc4(175, 175, 175, 120));
	bg->setContentSize(tipSize);
	char str[100] = { 0 };
	sprintf(str, "%d", m_id);
	CCLabelTTF *label = CCLabelTTF::create(str, "Arial", 24);
	label->setPosition(ccp(tipSize.width * 0.5f, tipSize.height *0.5f));

	node->setContentSize(tipSize);
	node->addChild(bg);
	node->addChild(label);
	return node;
}

void UiWidgetNode::callIdTipsToggle()
{
	if (!m_idTips)
	{
		m_idTips = getIdTips();
		m_idTips->setAnchorPoint(ccp(0, 1));
		m_idTips->setPositionX(getContentSize().width);
		m_idTips->setPositionY(getContentSize().height);
		addChild(m_idTips, 1);
	}
	m_isShowIdTips = !m_isShowIdTips;
	m_idTips->setVisible(m_isShowIdTips);
}




