#ifndef _NITA_H_
#define _NITA_H_

#include "cocos2d.h"
#include "HeroSprite.h"
USING_NS_CC;
using namespace cocostudio::timeline;

class Nita : public HeroSprite {


public:
	//�����ͳ�ʼ��
	CREATE_FUNC(Nita);
	virtual bool init();
	//�ƶ�
	void heroSetAction(int direction, int num);
	//����
	void attack(Point targetPosition);
};
#endif
