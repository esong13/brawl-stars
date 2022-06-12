#ifndef _SwordMan_H_
#define _SwordMan_H_

#include "cocos2d.h"
#include "HeroSprite.h"
USING_NS_CC;
using namespace cocostudio::timeline;

class SwordMan : public HeroSprite {


public:
	//创建和初始化
	CREATE_FUNC(SwordMan);
	virtual bool init();
	//移动
	void heroSetAction(int direction, int num);
	//攻击
	void attack(Point targetPosition);
};
#endif