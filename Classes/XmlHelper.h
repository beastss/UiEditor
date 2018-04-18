#ifndef __XMLHELPER_H__
#define __XMLHELPER_H__
#include "cocos2d.h"

class XmlHelper
{
public:
	XmlHelper(std::string path) : m_path(path){}
	void parse();
private:
	std::string m_path;
};
#endif