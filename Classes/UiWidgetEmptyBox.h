#ifndef __UIWIDGETEMPTYBOX_H__
#define __UIWIDGETEMPTYBOX_H__

#include "cocos2d.h"
#include "UiWidgetNode.h"
#include "rapidxml/rapidxml.hpp"
#include "EmptyBox.h"
class UiWidgetEmptyBox : public UiWidgetNode
{
public:
    static UiWidgetEmptyBox *create(rapidxml::xml_node<>* node);
    UiWidgetEmptyBox(rapidxml::xml_node<>* node);

	virtual void save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node);

private:
    EmptyBox *m_emptyBox;
};


#endif 
