#include "Item.h"


void Item::bindSprite(Sprite* sprite){
	roleSprite = sprite;
	addChild(roleSprite);

	//����Ѫ��
	healthBar = createHealthBar();
	healthBar->setPosition(Point(roleSprite->getPosition().x+6, roleSprite->getPosition().y + 26));
	healthBar->setScale(0.1f,0.5f);
	roleSprite->addChild(healthBar);


}

//����Ѫ��
Slider* Item::createHealthBar()
{
	Slider* healthBar = Slider::create();
	healthBar -> loadBarTexture("sliderTrack.png");
	healthBar -> loadProgressBarTexture("sliderProgress.png");
	healthBar -> setPercent(100);
	return healthBar;
}
//����Ѫ��״̬
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
	//Ѫ���½�
	healthPointNow -= damage;
	if (healthPointNow <= 0){
		Dead();
		return true;
	}//����

	//�����������Ѫ��״̬
	setHealth(healthPointNow);

	//ֹͣ�˺�
	//...

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

