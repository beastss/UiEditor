#include "UiWidgetButton.h"
#include "UiWidgetsManager.h"
USING_NS_CC;
using namespace std;
using namespace rapidxml;

UiWidgetButton *UiWidgetButton::create(rapidxml::xml_node<>* node)
{
	auto btn = new UiWidgetButton(node);
    btn->autorelease();
    return btn;
}

UiWidgetButton *UiWidgetButton::create()
{
    auto btn = new UiWidgetButton();
    btn->init();
    btn->autorelease();
    return btn;
}

UiWidgetButton::UiWidgetButton(rapidxml::xml_node<>* node)
{
	initBaseInfo(node);

	m_attr.normalPath = node->first_node("normal")->value();
	m_attr.selectedPath = node->first_node("selected")->value();
	m_attr.disabledPath = node->first_node("disabled")->value();

	CCMenuItemImage *m_imageItem = CCMenuItemImage::create(
		m_attr.normalPath.c_str(),
		m_attr.selectedPath.c_str(),
		m_attr.disabledPath.c_str(),
		this,
		NULL);


	CCSize size = CCSprite::create(m_attr.normalPath.c_str())->getContentSize();
	CCMenu *menu = CCMenu::create(m_imageItem, NULL);
	menu->setPosition(ccp(0, 0));
	m_imageItem->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
	m_imageItem->setEnabled(false);
	setContentSize(size);
	addChild(menu);
	drawFrame();
}

void UiWidgetButton::save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	auto myNode = doc.allocate_node(node_element, "button");
	node->append_node(myNode);
	saveBaseInfo(doc, myNode);

	myNode->append_node(doc.allocate_node(rapidxml::node_element, "normal", m_attr.normalPath.c_str()));
	myNode->append_node(doc.allocate_node(rapidxml::node_element, "selected", m_attr.selectedPath.c_str()));
	myNode->append_node(doc.allocate_node(rapidxml::node_element, "disabled", m_attr.disabledPath.c_str()));
}
