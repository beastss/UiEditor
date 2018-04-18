#ifndef __UIWIDGETSMANAGER_H__
#define __UIWIDGETSMANAGER_H__
#include "cocos2d.h"
#include <functional>
#include <unordered_map>
#include "rapidxml/rapidxml.hpp"


#define NOTIFY_VIEWS(_FUNC_ ,...)						\
for (size_t index = 0; index < m_views.size(); ++index) \
{														\
	m_views[index]->_FUNC_(__VA_ARGS__);				\
}

class UiWidgetNode;

struct IUiWidgetView
{
	virtual void newLayout(cocos2d::CCSize &size){}
	virtual void addNewWidget(UiWidgetNode *node){}
	virtual void nodeSelected(UiWidgetNode *node){}
	virtual void save(std::string &filePath){}
	virtual void closeLayout(){}
};


class UiWidgetsManager
{
public:
	static UiWidgetsManager *theMgr();
	~UiWidgetsManager(){}
	void openNewLayout(std::string path);
	void save();
	void refresh();

	void nodeSelected(UiWidgetNode *node);
	void addView(IUiWidgetView *view);
	void removeView(IUiWidgetView *view);
	
	void loadXmlFile(std::string path);
	void createWidgetByName(const char *name);
    void init();
	int getWidgetId(int id);
	void closeCurLayout();
	UiWidgetNode *openImage(rapidxml::xml_node<> *node);
	std::string openPath();

	std::string getCurFileName(){ return m_xmlPath; }
private:
	UiWidgetsManager() :m_maxWidgetId(0){}
    void registerWidget(std::string name, std::function<UiWidgetNode *(rapidxml::xml_node<>*)> creater);
    UiWidgetNode *createButton(rapidxml::xml_node<> *node);
    UiWidgetNode *createLabel(rapidxml::xml_node<> *node);
    UiWidgetNode *createImage(rapidxml::xml_node<> *node);
	UiWidgetNode *createEmptyBox(rapidxml::xml_node<> *node);
	UiWidgetNode *createImageNum(rapidxml::xml_node<> *node);
	UiWidgetNode *createAnimation(rapidxml::xml_node<> *node);



	bool checkXml(rapidxml::xml_node<> *layout);
	bool isFilesExit(int id, std::vector<std::string > &files);
private:
	std::vector<IUiWidgetView *> m_views;
    std::unordered_map<std::string, std::function<UiWidgetNode *(rapidxml::xml_node<>*)> > m_creaters;
	int m_maxWidgetId; //当前最大控件的id;
	std::string m_xmlPath;
	
};
#endif