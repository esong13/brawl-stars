#include "SwordMan.h"

bool SwordMan::init()
{
	if (!HeroSprite::init()) return false;
	setAttackNum(SWORDMAN_ATTACKNUM);//���ù�����
	setHealthPointMax(SWORDMAN_HP);//����Ѫ��
	setHealthPointNow(SWORDMAN_HP);
	setMoveSpeed(SWORDMAN_SPEED);//�����ƶ��ٶ�

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
	//������ȴ
	//attackIsColding = true;
	//���ø��ຯ��
	HeroSprite::attack(targetPosition);

	//������ʱ��������2�ε���
	for (int i = 1; i <= 2; ++i) {
		Bullet* bulletNode= Bullet::create();
		bulletNode->bindSprite(Sprite::create("sword_light.png"));
		bulletNode->getBulletSprite()->setScale(0.1f);
		this->addChild(bulletNode);

		//�����ӵ����ֵ
		bulletNode->setPosition(getRoleSprite()->getPosition());
		bulletNode->setBulletDistance(40);
		bulletNode->setBulletAttackNum(this->getAttackNum());
		bulletNode->setBulletSpeed(10* SWORDMAN_SPEED);

		//�ӵ��ƶ�
		bulletNode->bulletMoveTo(targetPosition);

		bulletHasBeenShot.pushBack(bulletNode);
	}
}
