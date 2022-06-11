#ifndef _HERO_SPRITE_
#define _HERO_SPRITE_

#include "cocos2d.h"
#include "Item.h"
#include "ui/CocosGUI.h"
#include "Bullet.h"
USING_NS_CC;
using namespace cocos2d::ui;


class HeroSprite :public Item {
	//������
	CC_SYNTHESIZE(int, attackNum, AttackNum);
	//�ӵ���
	CC_SYNTHESIZE(int, bulletMax, BulletMax);//��ҩ����
	CC_SYNTHESIZE(int, bulletNow, BulletNow);//��ǰ��ҩ��

	//��������
	CC_SYNTHESIZE(int, skillEnergyNow, SkillEnergyNow);//��ǰ��������
	CC_SYNTHESIZE(int, skillEnergyMax, SkillEnergyMax);//������������

	//����
	CC_SYNTHESIZE(int, moveSpeed, MoveSpeed);//������������

public:
	//�����ͳ�ʼ��
	CREATE_FUNC(HeroSprite);
	virtual bool init();
	
	//�ƶ�����
	bool isRun;//�Ƿ����˶�
	int direction;//�˶�����
	virtual void heroSetAction(int direction, int num);//��̬ ��ͬӢ�۵��ƶ�
	void heroMoveTo(float x, float y,float heroSpeed);//�ƶ���

	//��������
	virtual void attack(Point targetPosition);


	//��ҩ����
	Slider* createBulletBar();
	Slider* setBullet(int health);
	Slider* bulletBar;
	void addBulletBar();

	//�ѷ�����ӵ�
	Vector<Bullet*> bulletHasBeenShot;
	void update(float dt)override;

protected:
	//�ƶ�����
	Animate* createAnimate(int direction, const char* name, int num);//�ƶ�����
	void setAction(int direction, const char* name, int num);//��ĳ�����˶�
};

#endif
