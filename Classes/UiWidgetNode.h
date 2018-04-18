#ifndef __UIWIDGETNODE_H__
#define __UIWIDGETNODE_H__

#include "cocos2d.h"
#include "rapidxml/rapidxml.hpp"

enum WidgetType
{
	kWidgetImage,
	kWidgetButton,
	kWidgetLabel,
};

class UiWidgetNode
	: public cocos2d::CCNode
	, public cocos2d::CCTouchDelegate
{
public:
	virtual ~UiWidgetNode(){}
	virtual bool init();
public:
	virtual void save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node){}
	virtual std::vector<std::string> selectedPrint(){ return std::vector<std::string>(); }
	void callIdTipsToggle();
protected:
	UiWidgetNode(int touchPriority = 0);
	virtual void onTouchBegan(){}
	void drawFrame();
    void initBaseInfo(rapidxml::xml_node<> *node);
	void saveBaseInfo(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node);
	void setId(int id){ m_id = id; }
private:
	virtual void onEnter();
	virtual void onExit();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

	cocos2d::CCNode *getIdTips();
private:
	int m_touchPriority;
	cocos2d::CCPoint m_oldPos;
	int m_id;

	bool m_isShowIdTips;
	cocos2d::CCNode *m_idTips;
};

#endif 
