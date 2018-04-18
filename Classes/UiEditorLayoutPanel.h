#ifndef __UIEDITORLAYOUTPANEL_H__
#define __UIEDITORLAYOUTPANEL_H__

#include "cocos2d.h"
#include "UiWidgetsManager.h"

class UiEditorLayoutPanel
	: public cocos2d::CCLayer
	, public IUiWidgetView
{
public:
    virtual bool init();  
	static UiEditorLayoutPanel *create(cocos2d::CCSize &size);
public:
	virtual void addNewWidget(UiWidgetNode *node);
	virtual void save(std::string &filePath);
	virtual void nodeSelected(UiWidgetNode *node);
private:
	UiEditorLayoutPanel(cocos2d::CCSize &size);
	void virtual onEnter();
	void virtual onExit();

	void addClippingNode();
	void clearNodes();
	void removeNode(UiWidgetNode *);
	virtual void UiEditorLayoutPanel::update(float dt);

private:
	void drawFrame();
private:
	std::vector<UiWidgetNode *>m_widgets;
	cocos2d::CCSize m_layoutSize;
	UiWidgetNode *m_curSelectedNode;
};

#endif 
