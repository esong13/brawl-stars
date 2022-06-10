#ifndef _HERO_SPRITE_
#define _HERO_SPRITE_

#include "cocos2d.h"
#include "Item.h"
USING_NS_CC;


class HeroSprite :public Item {
	//������
	CC_SYNTHESIZE(int, attackNum, AttackNum);
	//MP(��ҩ)
	CC_SYNTHESIZE(int, magicPointMax, MagicPointMax);//��ҩ����
	CC_SYNTHESIZE(int, magicPointNow, MagicPointNow);//��ǰ��ҩ��

public:
	//�����ͳ�ʼ��
	CREATE_FUNC(HeroSprite);
	virtual bool init();
	
	//�ƶ�����
	bool isRun;//�Ƿ����˶�
	int direction;//�˶�����
	Point position;//�����λ��
	virtual void heroSetAction(int direction, int num);//��̬ ��ͬӢ�۵��ƶ�
	void heroMoveTo(float x, float y);//�ƶ���

	//��������
	virtual void attack(Point targetPosition);


	//MP����
	void setMagicBar(int magic);
protected:
	//�ƶ�����
	Animate* createAnimate(int direction, const char* name, int num);//�ƶ�����
	void setAction(int direction, const char* name, int num);//��ĳ�����˶�
};

#endif
