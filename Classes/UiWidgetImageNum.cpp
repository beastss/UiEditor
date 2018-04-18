#include "UiWidgetImageNum.h"
USING_NS_CC;
using namespace std;
using namespace rapidxml;

UiWidgetImageNum *UiWidgetImageNum::create(rapidxml::xml_node<>* node)
{
	const char* str = "0";
	UiWidgetImageNum *label = new UiWidgetImageNum(node);
	label->autorelease();
	return label;
}

UiWidgetImageNum::UiWidgetImageNum(rapidxml::xml_node<>* node)
{
	initBaseInfo(node);

	m_str = node->first_node("num")->value();
	m_imgNumPath = node->first_node("path")->value();
	m_amount = atoi(node->first_node("amount")->value());

	auto imgSize = CCSprite::create(m_imgNumPath.c_str())->getContentSize();

	m_label = CCLabelAtlas::create(m_str.c_str(), m_imgNumPath.c_str(), imgSize.width / m_amount, imgSize.height, '0');

	CCSize size = m_label->getContentSize();

	setContentSize(size);
	addChild(m_label);
	drawFrame();
}

void UiWidgetImageNum::save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	auto myNode = doc.allocate_node(node_element, "imageNum");
	node->append_node(myNode);
	saveBaseInfo(doc, myNode);

	char str[100] = { 0 };
	sprintf(str, "%d", m_amount);
	myNode->append_node(doc.allocate_node(rapidxml::node_element, "amount", doc.allocate_string(str)));
	myNode->append_node(doc.allocate_node(rapidxml::node_element, "num", m_str.c_str()));
	myNode->append_node(doc.allocate_node(rapidxml::node_element, "path", m_imgNumPath.c_str()));
}


