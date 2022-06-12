#include "Item.h"


void Item::bindSprite(Sprite* sprite){
	setRoleSprite(sprite);
	addChild(roleSprite);
}

//Ѫ��
Slider* Item::createHealthBar()
{
	Slider* slider = Slider::create();
	slider-> loadBarTexture("sliderTrack.png");
	slider-> loadProgressBarTexture("sliderProgress.png");
	slider-> setPercent(100);
	return slider;
}
//����Ѫ��״̬
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
	//����Ѫ��
	healthBar = createHealthBar();
	healthBar->setPosition(Point(getRoleSprite()->getPosition().x + 6, getRoleSprite()->getPosition().y + 26));
	healthBar->setScale(0.1f, 0.5f);
	getRoleSprite()->addChild(healthBar);
}

bool Item::Wounded(int damage)
{
	//Ѫ���½�
	healthPointNow -= damage;
	if (healthPointNow <= 0){
		Dead();
		return true;
	}//����

	//�����������Ѫ��
	setHealth(healthBar, healthPointNow);

	return false;
}

void Item::Dead()
{
	//ͨ�����������жϵ����������
	for (int i = 1; i <= (getPower() - 1) / 2 + 1;++i) {
		Sprite* powerFalled = Sprite::create("power.png");
		powerFalled->setPosition(getPosition()+getRoleSprite()->getPosition());
		getParent()->addChild(powerFalled);
		//MyWorld::getSpriteLayer()->powerInTheWorld.pushBack(powerFalled);
	}

	//�Ƴ��Լ�
	this->removeFromParent();
}

