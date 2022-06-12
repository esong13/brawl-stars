#include "Item.h"


void Item::bindSprite(Sprite* sprite){
	setRoleSprite(sprite);
	addChild(roleSprite);
}

//血条
Slider* Item::createHealthBar()
{
	Slider* slider = Slider::create();
	slider-> loadBarTexture("sliderTrack.png");
	slider-> loadProgressBarTexture("sliderProgress.png");
	slider-> setPercent(100);
	return slider;
}
//更新血条状态
void Item::setHealth(Slider* theHealthBar,int health)
{
	if (health >= 0 && health <= healthPointMax)
	{
		setHealthPointNow(health);
	}
	theHealthBar-> setPercent(100.0f * healthPointNow / healthPointMax);
}

void Item::addHealthBar()
{
	//创建血条
	healthBar = createHealthBar();
	healthBar->setPosition(Point(getRoleSprite()->getPosition().x + 6, getRoleSprite()->getPosition().y + 26));
	healthBar->setScale(0.1f, 0.5f);
	getRoleSprite()->addChild(healthBar);
}

bool Item::Wounded(int damage)
{
	//血量下降
	healthPointNow -= damage;
	if (healthPointNow <= 0){
		Dead();
		return true;
	}//死亡

	//还活着则更新血条
	setHealth(healthBar, healthPointNow);

	return false;
}

void Item::Dead()
{
	

	//移除自己
	this->removeFromParent();
}

