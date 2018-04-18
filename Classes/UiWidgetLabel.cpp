#include "UiWidgetLabel.h"
USING_NS_CC;
using namespace std;
using namespace rapidxml;

UiWidgetLabel *UiWidgetLabel::create(rapidxml::xml_node<>* node)
{
	const char* str = "hello";
	UiWidgetLabel *label = new UiWidgetLabel(node);
	label->autorelease();
	return label;
}

UiWidgetLabel::UiWidgetLabel(rapidxml::xml_node<>* node)
{
	initBaseInfo(node);

	m_str = node->first_node("text")->value();
	m_label = CCLabelTTF::create(m_str.c_str(), "Arial", 24);

	CCSize size = m_label->getContentSize();
	m_label->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));

	setContentSize(size);
	addChild(m_label);
	drawFrame();
}

void UiWidgetLabel::save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	auto myNode = doc.allocate_node(node_element, "label");
	node->append_node(myNode);
	saveBaseInfo(doc, myNode);

	myNode->append_node(doc.allocate_node(rapidxml::node_element, "text", m_str.c_str()));
}


