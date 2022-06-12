#ifndef _HERO_SPRITE_
#define _HERO_SPRITE_

#include "cocos2d.h"
#include "Item.h"
#include "ui/CocosGUI.h"
#include "Bullet.h"
USING_NS_CC;
using namespace cocos2d::ui;


class HeroSprite :public Item {
	//攻击
	CC_SYNTHESIZE(int, attackNum, AttackNum);//攻击力
	CC_SYNTHESIZE(bool, attackIsColding, AttackIsColding);//攻击冷却
	CC_SYNTHESIZE(float, attackCDTime, AttackCDTime);//攻击冷却时间



	//子弹量
	CC_SYNTHESIZE(int, bulletMax, BulletMax);//弹药上限
	CC_SYNTHESIZE(int, bulletNow, BulletNow);//当前弹药量


	//大招能量
	CC_SYNTHESIZE(int, skillEnergyNow, SkillEnergyNow);//当前大招能量
	CC_SYNTHESIZE(int, skillEnergyMax, SkillEnergyMax);//大招能量上限

	//移速
	CC_SYNTHESIZE(int, moveSpeed, MoveSpeed);//移动速度

public:
	//创建和初始化
	CREATE_FUNC(HeroSprite);
	virtual bool init();
	
	//移动部分
	bool isRun;//是否在运动
	int direction;//运动方向
	virtual void heroSetAction(int direction, int num);//多态 不同英雄的移动
	void heroMoveTo(float x, float y,float heroSpeed);//移动到

	//攻击部分
	virtual void attack(Point targetPosition);


	//弹药部分
	Slider* createBulletBar();
	void setBullet(Slider* theBulletBar,int bullet);
	Slider* bulletBar;
	void addBulletBar();


	//已发射的子弹
	Vector<Bullet*> bulletHasBeenShot;



	//定时器
	void update(float dt);


protected:
	//移动部分
	Animate* createAnimate(int direction, const char* name, int num);//移动动画
	void setAction(int direction, const char* name, int num);//朝某方向运动
};

#endif
