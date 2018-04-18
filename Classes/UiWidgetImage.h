#ifndef __UIWIDGETIMAGE_H__
#define __UIWIDGETIMAGE_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"
class UiWidgetImage : public UiWidgetNode
{
public:
    static UiWidgetImage *create(rapidxml::xml_node<>* node);
	UiWidgetImage(rapidxml::xml_node<>* node);
	UiWidgetImage(rapidxml::xml_node<>* node, std::string path);
	virtual void save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node);
	static UiWidgetImage *createImage(rapidxml::xml_node<>* node, std::string path);
private:


private:
	cocos2d::CCSprite *m_spr;
	std::string m_path;
};


#endif 
