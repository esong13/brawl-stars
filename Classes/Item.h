#ifndef _ITEM_H_
#define _ITEM_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
using namespace cocos2d::ui;

class Item : public cocos2d::Node {
	//精灵
	CC_SYNTHESIZE(Sprite*, roleSprite, RoleSprite);
	//Hp
	CC_SYNTHESIZE(int, healthPointMax, HealthPointMax);//Hp上限
	CC_SYNTHESIZE(int, healthPointNow, HealthPointNow);//当前Hp
	//能量
	CC_SYNTHESIZE(int, power, Power);//携带的能量值

public:

	//精灵
	void bindSprite(Sprite* sprite);//绑定精灵


	//Hp
	Slider* createHealthBar();
	void Item::setHealth(Slider* theHealthBar, int health);
	Slider* healthBar;
	void addHealthBar();
	//受伤
	bool Wounded(int damage);  
	//死亡
	void Dead();
};

#endif