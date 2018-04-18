#include "UIEditorKeyboardListener.h"

using namespace cocos2d;
using namespace std;



UIEditorKeyboardListener::UIEditorKeyboardListener()
	: m_stopKeyInput(false)
{

}

UIEditorKeyboardListener::~UIEditorKeyboardListener()
{
	m_keyState.clear();
}

static bool isWindowActivated()
{
	HWND hwnd = CCEGLView::sharedOpenGLView()->getHWnd();
	return GetActiveWindow() == hwnd;
}

bool UIEditorKeyboardListener::isKeyDownUp(int keyCode, const string &str)
{
	if (m_stopKeyInput || !isWindowActivated())
	{
		return false;
	}
	unordered_map<string, unordered_map<int, bool> >::iterator iter = m_keyState.find(str);
	if (iter == m_keyState.end())
	{
		unordered_map<int, bool> temp;
		temp.insert(make_pair(keyCode, false));
		m_keyState.insert(make_pair(str, temp));
	}else
	{
		unordered_map<int, bool> &temp = iter->second;
		if (temp.find(keyCode) == temp.end())
		{
			temp.insert(make_pair(keyCode, false));
		}
	}
	iter = m_keyState.find(str);
	if (KEY_DOWN(keyCode))
	{
		iter->second[keyCode] = true;
	}else if (KEY_UP(keyCode) && iter->second[keyCode])
	{
		iter->second[keyCode] = false;
		return true;
	}
	return false;
}

bool UIEditorKeyboardListener::isKeyDown(int keyCode)
{
	if (m_stopKeyInput || !isWindowActivated())
	{
		return false;
	}
	return KEY_DOWN(keyCode);
}

bool UIEditorKeyboardListener::isKeyUp(int keyCode)
{
	if (m_stopKeyInput || !isWindowActivated())
	{
		return false;
	}
	return KEY_UP(keyCode);
}

UIEditorKeyboardListener *UIEditorKeyboardListener::sharedListener()
{
	static UIEditorKeyboardListener listener;
	return &listener;
}

/*
 if (isKeyDown(VK_LCONTROL) && isKeyDownUp(VK_TAB, "main_view"))
	{
 switchToNextLayoutView();
	}else if (isKeyDown(VK_LCONTROL) && isKeyDown('C'))
	{
 */