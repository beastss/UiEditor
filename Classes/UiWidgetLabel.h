#ifndef __UIWIDGETLABEL_H__
#define __UIWIDGETLABEL_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"
class UiWidgetLabel : public UiWidgetNode
{
public:
	static UiWidgetLabel *create(rapidxml::xml_node<>* node);
	virtual void save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node);
private:
	UiWidgetLabel(rapidxml::xml_node<>* node);
private:
	cocos2d::CCLabelTTF *m_label;
	std::string m_str;
};

#endif 
