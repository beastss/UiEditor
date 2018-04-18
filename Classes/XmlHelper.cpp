#include "XmlHelper.h"
#include "support/tinyxml2/tinyxml2.h"
USING_NS_CC;
using namespace std;

void XmlHelper::parse()
{
	/*
	tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
	pDoc->LoadFile(m_path.c_str());
	tinyxml2::XMLElement *rootEle = pDoc->RootElement();
	CCLog("%s", rootEle->GetText());
	const tinyxml2::XMLAttribute *attribute = rootEle->FirstAttribute();
	CCLog("%s %s", attribute->Name(), attribute->Value());
	float value = 0.1f;
	rootEle->QueryFloatAttribute("version", &value);
	CCLog("%f", value);
	rootEle->SetAttribute("version", 1.4);
	tinyxml2::XMLElement *dictEle = rootEle->FirstChildElement();
	tinyxml2::XMLElement *keyEle = dictEle->FirstChildElement();
	CCLog("%s,%s", keyEle->Name(), keyEle->GetText());
	tinyxml2::XMLElement *stringEle = keyEle->NextSiblingElement();
	CCLog("%s,%s", stringEle->Name(), stringEle->GetText());
	tinyxml2::XMLElement *nulXmlEle = stringEle->FirstChildElement();
	if (NULL == nulXmlEle) {
		CCLog("string下面没有子点了");
	}
	pDoc->SaveFile(m_path.c_str());
	*/
}