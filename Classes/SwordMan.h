#ifndef _SwordMan_H_
#define _SwordMan_H_

#include "cocos2d.h"
#include "HeroSprite.h"
USING_NS_CC;

class SwordMan : public HeroSprite {


public:
	//�����ͳ�ʼ��
	CREATE_FUNC(SwordMan);
	virtual bool init();
	//�ƶ�
	void heroSetAction(int direction, int num);
	//����
	virtual void attack(Point targetPosition);
};
#endif