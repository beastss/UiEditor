#ifndef UI_EDITOR_KEYBOARD_LISTENER_H_
#define UI_EDITOR_KEYBOARD_LISTENER_H_

#include "cocos2d.h"
#include <unordered_map>
#include <windows.h>

#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 1 : 0)
#define KEY_UP(vk_code) (GetAsyncKeyState(vk_code) & 0x8000 ? 0 : 1)



class UIEditorKeyboardListener
{
public:	
	static UIEditorKeyboardListener *sharedListener();

private:
	UIEditorKeyboardListener();
	~UIEditorKeyboardListener();

public:
	bool isKeyDownUp(int keyCode, const std::string &str);
	bool isKeyDown(int keyCode);
	bool isKeyUp(int keyCode);
	void stopKeyInput(bool isStop) { m_stopKeyInput = isStop; }

private:
	std::unordered_map<std::string, std::unordered_map<int, bool> > m_keyState;

private:
	bool m_stopKeyInput;

};


#endif