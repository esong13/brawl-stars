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
Slider* Item::setHealth(int health)
{
	if (health >= 0 && health <= healthPointMax)
	{
		setHealthPointNow(health);
	}
	Slider* slider = Slider::create();
	slider-> loadBarTexture("sliderTrack.png");
	slider-> loadProgressBarTexture("sliderProgress.png");
	slider-> setPercent(100.0f * healthPointNow / healthPointMax);
	return slider;
}

void Item::addHealthBar()
{
	//创建并更新血条
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

	//还活着则更新血量状态
	setHealth(healthPointNow);

	return true;
}

void Item::Dead()
{
	//掉落能量
	auto powerFalled = Sprite::create("power.png");
	powerFalled->setPosition(getPosition());
	getParent()->addChild(powerFalled, 1);


	//从屏幕中移除自己
	this->removeFromParent();
	isDead = true;
}

