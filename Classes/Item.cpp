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
	//����������Ѫ��
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

	//�����������Ѫ��״̬
	setHealth(healthPointNow);

	return true;
}

void Item::Dead()
{
	//��������
	auto powerFalled = Sprite::create("power.png");
	powerFalled->setPosition(getPosition());
	getParent()->addChild(powerFalled, 1);


	//����Ļ���Ƴ��Լ�
	this->removeFromParent();
	isDead = true;
}

