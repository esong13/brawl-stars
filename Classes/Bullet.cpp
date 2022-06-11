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
	int dx = position.x- ROLENODE_POSITION_X - getPosition().x;
	int dy = position.y- ROLENODE_POSITION_Y - getPosition().y;
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
	setBulletTerminal(getBulletSprite()->getPosition()+Point((dx / r) * getBulletDistance(), (dy / r) * getBulletDistance()));
	auto moveBy = MoveBy::create(2.0/ getBulletSpeed(), Point((dx / r) * getBulletDistance(), (dy / r) * getBulletDistance()));
	getBulletSprite()->runAction(moveBy);
}
