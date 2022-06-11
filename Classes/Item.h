#ifndef _ITEM_H_
#define _ITEM_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "Const.h"
USING_NS_CC;
using namespace cocos2d::ui;

class Item : public cocos2d::Node {
	//����
	CC_SYNTHESIZE(Sprite*, roleSprite, RoleSprite);
	//Hp
	CC_SYNTHESIZE(int, healthPointMax, HealthPointMax);//Hp����
	CC_SYNTHESIZE(int, healthPointNow, HealthPointNow);//��ǰHp
	//����
	CC_SYNTHESIZE(int, power, Power);//Я��������ֵ

public:

	//����
	void bindSprite(Sprite* sprite);//�󶨾���


	//Hp
	Slider* createHealthBar();
	void Item::setHealth(Slider* theHealthBar, int health);
	Slider* healthBar;
	void addHealthBar();


	//����
	bool Wounded(int damage);  
	//����
	void Dead();
};

#endif