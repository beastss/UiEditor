#include "UiWidgetAnimation.h"
USING_NS_CC;
using namespace std;
using namespace rapidxml;
using namespace extension;
UiWidgetAnimation *UiWidgetAnimation::create(rapidxml::xml_node<>* node)
{
	const char* str = "hello";
	UiWidgetAnimation *label = new UiWidgetAnimation(node);
	label->autorelease();
	return label;
}

UiWidgetAnimation::UiWidgetAnimation(rapidxml::xml_node<>* node)
{
	initBaseInfo(node);

	m_path = node->first_node("path")->value();
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo(m_path.c_str());
	int pos1 = m_path.rfind("/");
	int pos2 = m_path.rfind(".");
	string armatureName = m_path.substr(pos1 + 1, pos2 - pos1 - 1);

	m_armature = CCArmature::create(armatureName.c_str());

	m_movementName = node->first_node("movement")->value();
	do 
	{
		if (m_movementName != "0")
		{
			auto movementNames = m_armature->getAnimation()->getAnimationData()->getMovementNames();
			auto iter = find(movementNames.begin(), movementNames.end(), m_movementName);
			if (iter != movementNames.end())
			{
				m_armature->getAnimation()->play(m_movementName.c_str());
				break;
			}
			else
			{
				char str[100] = { 0 };
				sprintf(str, "armature \"%s\" doesn't have movement \"%s\",now load the first movement.", armatureName.c_str(), m_movementName.c_str());
				CCMessageBox(str, "error");
				m_movementName = "0";
			}
		}
		if (m_movementName == "0")
		{
			m_armature->getAnimation()->playWithIndex(0);
		}
	} while (0);

	//m_armature->getAnimation()->playWithIndex(0);
	//m_armature->getAnimation()->setSpeedScale(0.4f);
	//m_armature->setPosition(ccp(200, 200));
	//m_armature->setScale(0.6f);

	CCSize size = m_armature->getContentSize();
	m_armature->setPosition(ccp(size.width * 0.5f, size.height * 0.5f));

	setContentSize(size);
	addChild(m_armature);
	drawFrame();
}

void UiWidgetAnimation::save(rapidxml::xml_document<> &doc, rapidxml::xml_node<> *node)
{
	auto myNode = doc.allocate_node(node_element, "animation");
	node->append_node(myNode);
	saveBaseInfo(doc, myNode);

	myNode->append_node(doc.allocate_node(rapidxml::node_element, "path", m_path.c_str()));
	myNode->append_node(doc.allocate_node(rapidxml::node_element, "movement", m_movementName.c_str()));
}

vector<string> UiWidgetAnimation::selectedPrint()
{
	auto movementNames = m_armature->getAnimation()->getAnimationData()->getMovementNames();
	return movementNames;
}
