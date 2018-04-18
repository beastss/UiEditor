#ifndef __UIWIDGETIMAGENUM_H__
#define __UIWIDGETIMAGENUM_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"
class UiWidgetImageNum : public UiWidgetNode
{
public:
	static UiWidgetImageNum *create(rapidxml::xml_node<>* node);
	virtual void save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node);
private:
	UiWidgetImageNum(rapidxml::xml_node<>* node);
private:
	cocos2d::CCLabelAtlas  *m_label;
	std::string m_str;
	std::string m_imgNumPath;
	int m_amount;
};

#endif 
