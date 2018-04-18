#ifndef __UIEDITORATTRSPANEL_H__
#define __UIEDITORATTRSPANEL_H__

#include "cocos2d.h"
#include "UiWidgetsManager.h"

class AttrPrintPad : public cocos2d::CCNode
{
public:
	CREATE_FUNC(AttrPrintPad);
	void clearPad();
	void addStr(const char *str);
private:
	virtual bool init();
private:
	float m_maxLabelHeight;
	float m_nextLabelHeight;
};

class UiEditorAttrsPanel 
	: public cocos2d::CCNode
	, public IUiWidgetView
{
public:
    virtual bool init();  
    CREATE_FUNC(UiEditorAttrsPanel);
private:
	virtual void onEnter();
	virtual void onExit();
	
	virtual void newLayout(cocos2d::CCSize &size);
	virtual void closeLayout();
	virtual void nodeSelected(UiWidgetNode *node);

	void refreshFileName();
private:
	cocos2d::CCLabelTTF *m_nameLabel;
	AttrPrintPad *m_printPad;
};


#endif 
