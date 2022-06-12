#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"
#include "Const.h"
USING_NS_CC;


class Bullet :public Node{
	CC_SYNTHESIZE(Sprite*, bulletSprite, BulletSprite);//子弹的精灵
	CC_SYNTHESIZE(int, bulletAttackNum, BulletAttackNum);//攻击力
	CC_SYNTHESIZE(int, bulletSpeed, BulletSpeed);//速度
	CC_SYNTHESIZE(int, bulletDistance, BulletDistance);//射程
	CC_SYNTHESIZE(Point, bulletTerminal, BulletTerminal);//目标地点
	

public:
	//创建和初始化
	CREATE_FUNC(Bullet);
	virtual bool init();

	//绑定精灵
	void bindSprite(Sprite* sprite);
	//子弹位移，position为触屏的地方，参考坐标为世界坐标
	virtual void bulletMoveTo(Point position);

	//碰撞


};
#endif

