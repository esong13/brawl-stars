#include "Nita.h"

bool Nita::init()
{
	if (!HeroSprite::init()) return false;
	setAttackNum(SWORDMAN_ATTACKNUM);//���ù�����
	setHealthPointMax(SWORDMAN_HP);//����Ѫ��
	setHealthPointNow(SWORDMAN_HP);
	setMoveSpeed(SWORDMAN_SPEED);//�����ƶ��ٶ�
	setAttackCDTime(SWORDMAN_ATTACKCDTIME);//���ù���

	return true;
}

void Nita::heroSetAction(int direction, int num)
{
	setAction(direction, "Nita", num);
}

void Nita::attack(Point targetPosition)
{
	if (getBulletNow() <= 0 || attackIsColding) {
		return;
	}
	//������ȴ
	setAttackIsColding(true);

	//���ø��ຯ��
	HeroSprite::attack(targetPosition);

	//Nita�������Ż�
	Bullet* bulletNode = Bullet::create();
	bulletNode->bindSprite(Sprite::create("fire.png"));

	bulletNode->getBulletSprite()->setScale(2.0f);
	bulletNode->getBulletSprite()->setRotation(90.0f);
	this->addChild(bulletNode);

	//�����ӵ����ֵ
	bulletNode->setPosition(getRoleSprite()->getPosition());
	bulletNode->setBulletDistance(40);
	bulletNode->setBulletAttackNum(this->getAttackNum());
	bulletNode->setBulletSpeed(10 * SWORDMAN_SPEED);

	//�ӵ��ƶ�
	bulletNode->bulletMoveTo(targetPosition);

	bulletHasBeenShot.pushBack(bulletNode);
}
