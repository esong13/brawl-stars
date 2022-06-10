#ifndef _HERO_SPRITE_
#define _HERO_SPRITE_

#include "cocos2d.h"
#include "Item.h"
USING_NS_CC;


class HeroSprite :public Item {
	//攻击力
	CC_SYNTHESIZE(int, attackNum, AttackNum);
	//MP(弹药)
	CC_SYNTHESIZE(int, magicPointMax, MagicPointMax);//弹药上限
	CC_SYNTHESIZE(int, magicPointNow, MagicPointNow);//当前弹药量

public:
	//创建和初始化
	CREATE_FUNC(HeroSprite);
	virtual bool init();
	
	//移动部分
	bool isRun;//是否在运动
	int direction;//运动方向
	Point position;//精灵的位置
	virtual void heroSetAction(int direction, int num);//多态 不同英雄的移动
	void heroMoveTo(float x, float y);//移动到

	//攻击部分
	virtual void attack(Point targetPosition);


	//MP部分
	void setMagicBar(int magic);
protected:
	//移动部分
	Animate* createAnimate(int direction, const char* name, int num);//移动动画
	void setAction(int direction, const char* name, int num);//朝某方向运动
};

#endif
