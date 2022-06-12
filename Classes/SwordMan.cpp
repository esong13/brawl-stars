#include "SwordMan.h"

bool SwordMan::init()
{
	if (!HeroSprite::init()) return false;
	setAttackNum(SWORDMAN_ATTACKNUM);//设置攻击力
	setHealthPointMax(SWORDMAN_HP);//设置血量
	setHealthPointNow(SWORDMAN_HP);
	setMoveSpeed(SWORDMAN_SPEED);//设置移动速度
	setAttackCDTime(SWORDMAN_ATTACKCDTIME);//设置攻速

	return true;
}

void SwordMan::heroSetAction(int direction, int num)
{
	setAction(direction, "sword_man", num);
}

void SwordMan::attack(Point targetPosition)
{
	if (getBulletNow() <= 0 || attackIsColding) {
		return;
	}
	//攻击冷却
	setAttackIsColding(true);

	//调用父类函数
	HeroSprite::attack(targetPosition);

	//坂田银时攻击：拉2次刀光
	for (int i = 1; i <= 2; ++i) {
		Bullet* bulletNode= Bullet::create();
		bulletNode->bindSprite(Sprite::create("sword_light.png"));
		bulletNode->getBulletSprite()->setScale(0.1f);
		this->addChild(bulletNode);

		//赋予子弹相关值
		bulletNode->setPosition(getRoleSprite()->getPosition());
		bulletNode->setBulletDistance(40);
		bulletNode->setBulletAttackNum(this->getAttackNum());
		bulletNode->setBulletSpeed(10* SWORDMAN_SPEED);

		//子弹移动
		bulletNode->bulletMoveTo(targetPosition);

		bulletHasBeenShot.pushBack(bulletNode);
	}
}
