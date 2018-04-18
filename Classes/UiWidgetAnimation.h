#ifndef __UIWIDGETANIMATION_H__
#define __UIWIDGETANIMATION_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"

class UiWidgetAnimation : public UiWidgetNode
{
public:
	static UiWidgetAnimation *create(rapidxml::xml_node<>* node);
	virtual void save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node);
	virtual std::vector<std::string> selectedPrint();
private:
	UiWidgetAnimation(rapidxml::xml_node<>* node);
private:
	cocos2d::extension::CCArmature *m_armature;
	std::string m_path;
	std::string m_movementName;
	float m_speed;
	float m_scale;
};

#endif 
