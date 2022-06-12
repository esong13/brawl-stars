#include "Bullet.h"



bool Bullet::init()
{
	return true;
}

void Bullet::bindSprite(Sprite* sprite)
{
	setBulletSprite(sprite);
	addChild(bulletSprite);
}

void Bullet::bulletMoveTo(Point position) {
	Vec2 visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 midSize = (origin + visibleSize) / 2;
	int dx = position.x - midSize.x;
	int dy = position.y - midSize.y;
	float r = sqrt(dx * dx + dy * dy);
	if (dx > 0) {
		getBulletSprite()->setRotation(-90.0f - (atan(dy / dx) / Pi) * 180.0f);
	}
	else if(dx<0){
		getBulletSprite()->setRotation(90.0f - (atan(dy / dx) / Pi) * 180.0f);
	}
	else if(dx==0&&dy>0){
		getBulletSprite()->setRotation(180.0f);
	}
	else if (dx == 0 && dy == 0) {//若刚好点到英雄原点则设置默认攻击方向
		dy = -1;
		r = 1;
	}
	setBulletTerminal(getBulletSprite()->getPosition()+Point((dx / r) * getBulletDistance(), (dy / r) * getBulletDistance()));
	auto moveBy = MoveBy::create(2.0/ getBulletSpeed(), Point((dx / r) * getBulletDistance(), (dy / r) * getBulletDistance()));
	getBulletSprite()->runAction(moveBy);
}
