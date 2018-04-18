#ifndef __UIEDITORMANAGER_H__
#define __UIEDITORMANAGER_H__

class UiEditorManager
{
public:
	static UiEditorManager *theMgr();
	~UiEditorManager(){}
private:
	UiEditorManager(){}
	
};
#endif