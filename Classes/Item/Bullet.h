#ifndef _BULLET_H_
#define _BULLET_H_

#include "cocos2d.h"
#include "Const.h"
USING_NS_CC;


class Bullet :public Node{
	CC_SYNTHESIZE(Sprite*, bulletSprite, BulletSprite);//�ӵ��ľ���
	CC_SYNTHESIZE(int, bulletAttackNum, BulletAttackNum);//������
	CC_SYNTHESIZE(int, bulletSpeed, BulletSpeed);//�ٶ�
	CC_SYNTHESIZE(int, bulletDistance, BulletDistance);//���
	CC_SYNTHESIZE(Point, bulletTerminal, BulletTerminal);//Ŀ��ص�
	CC_SYNTHESIZE(Sprite*, bulletFrom, BulletFrom);//�ӵ�������
	

public:
	//�����ͳ�ʼ��
	CREATE_FUNC(Bullet);
	virtual bool init();

	//�󶨾���
	void bindSprite(Sprite* sprite);
	//�ӵ�λ�ƣ�positionΪ�����ĵط����ο�����Ϊ��������
	virtual void bulletMoveTo(Point position);

	//��ײ


};
#endif

