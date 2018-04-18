#ifndef __UTIL_H__
#define __UTIL_H__
#include "UIEditorKeyboardListener.h"

#define isKeyDown(vk_code) (UIEditorKeyboardListener::sharedListener()->isKeyDown(vk_code)) 
#define isKeyDownUp(vk_code, str) (UIEditorKeyboardListener::sharedListener()->isKeyDownUp(vk_code, str))

namespace uitl
{

};
#endif