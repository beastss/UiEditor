#include "UiWidgetImage.h"
#include "UiWidgetsManager.h"
using namespace std;
USING_NS_CC;
using namespace rapidxml;

UiWidgetImage *UiWidgetImage::create(rapidxml::xml_node<>* node)
{
    UiWidgetImage *img = new UiWidgetImage(node);
    img->autorelease();
    return img;
}

UiWidgetImage *UiWidgetImage::createImage(rapidxml::xml_node<>* node, std::string path)
{
	UiWidgetImage *img = new UiWidgetImage(node);
	img->autorelease();
	return img;
}

UiWidgetImage::UiWidgetImage(rapidxml::xml_node<>* node)
{
    initBaseInfo(node);
	//m_path = path.c_str();
    m_path = node->first_node("path")->value();

	m_spr = CCSprite::create(m_path.c_str());
    CCSize size = m_spr->getContentSize();
    m_spr->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));
    setContentSize(size);
    addChild(m_spr);
    drawFrame();
}

UiWidgetImage::UiWidgetImage(rapidxml::xml_node<>* node, std::string path)
{
	initBaseInfo(node);
	m_path = path;
	m_spr = CCSprite::create(m_path.c_str());
	CCSize size = m_spr->getContentSize();
	m_spr->setPosition(ccp(size.width * 0.5f,size.height * 0.5f));
	setContentSize(size);
	addChild(m_spr);
	drawFrame();
}

void UiWidgetImage::save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	auto myNode = doc.allocate_node(node_element, "image");
	node->append_node(myNode);
	saveBaseInfo(doc, myNode);

	myNode->append_node(doc.allocate_node(rapidxml::node_element, "path", m_path.c_str()));
}


