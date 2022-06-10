#include "Item.h"


void Item::bindSprite(Sprite* sprite){
	roleSprite = sprite;
	addChild(roleSprite);

	//创建血条
	healthBar = createHealthBar();
	healthBar->setPosition(Point(roleSprite->getPosition().x+6, roleSprite->getPosition().y + 26));
	healthBar->setScale(0.1f,0.5f);
	roleSprite->addChild(healthBar);


}

//创建血条
Slider* Item::createHealthBar()
{
	Slider* healthBar = Slider::create();
	healthBar -> loadBarTexture("sliderTrack.png");
	healthBar -> loadProgressBarTexture("sliderProgress.png");
	healthBar -> setPercent(100);
	return healthBar;
}
//更新血条状态
Slider* Item::setHealth(int health)
{
	if (health >= 0 && health <= healthPointMax)
	{
		setHealthPointNow(health);
	}
	Slider* healthBar = Slider::create();
	healthBar -> loadBarTexture("sliderTrack.png");
	healthBar -> loadProgressBarTexture("sliderProgress.png");
	healthBar -> setPercent(100.0f * healthPointNow / healthPointMax);
	return healthBar;
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

	//停止伤害
	//...

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

