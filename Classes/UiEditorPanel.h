#ifndef __UIEDITORPANEL_H__
#define __UIEDITORPANEL_H__

#include "cocos2d.h"
#include "UiWidgetsManager.h"

class UiEditorLayoutPanel;
class UiEditorPanel 
	: public cocos2d::CCNode
	, public IUiWidgetView
{
public:
    CREATE_FUNC(UiEditorPanel);
private:
	virtual void newLayout(cocos2d::CCSize &size);
	virtual void closeLayout();
	virtual void update(float dt);
private:
	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	void removeCurLayout();
private:
	UiEditorPanel();
	void drawFrame();
private:
	UiEditorLayoutPanel *m_curLayout;
};

#endif 
