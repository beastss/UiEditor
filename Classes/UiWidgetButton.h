#ifndef __UiWidgetButton_H__
#define __UiWidgetButton_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"

struct BtnAttr
{
	std::string normalPath;
	std::string selectedPath;
	std::string disabledPath;
	
};
class UiWidgetButton : public UiWidgetNode
{
public:
    static UiWidgetButton *create(rapidxml::xml_node<>* node);
    static UiWidgetButton *create();
    
	virtual void save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node);
private:
	UiWidgetButton(){}
	UiWidgetButton(rapidxml::xml_node<>* node);
private:
	BtnAttr m_attr;
	cocos2d::CCMenuItemImage *m_imageItem;
	
};

#endif 
