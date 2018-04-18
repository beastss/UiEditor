#include "UiEditorManager.h"
UiEditorManager *UiEditorManager::theMgr()
{
	static UiEditorManager mgr;
	return &mgr;
}
