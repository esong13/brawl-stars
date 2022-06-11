#ifndef _HERO_SPRITE_
#define _HERO_SPRITE_

#include "cocos2d.h"
#include "Item.h"
#include "ui/CocosGUI.h"
#include "Bullet.h"
USING_NS_CC;
using namespace cocos2d::ui;


class HeroSprite :public Item {
	//����
	CC_SYNTHESIZE(int, attackNum, AttackNum);//������
	CC_SYNTHESIZE(bool, attackIsColding, AttackIsColding);//������ȴ



	//�ӵ���
	CC_SYNTHESIZE(int, bulletMax, BulletMax);//��ҩ����
	CC_SYNTHESIZE(int, bulletNow, BulletNow);//��ǰ��ҩ��

	//��������
	CC_SYNTHESIZE(int, skillEnergyNow, SkillEnergyNow);//��ǰ��������
	CC_SYNTHESIZE(int, skillEnergyMax, SkillEnergyMax);//������������

	//����
	CC_SYNTHESIZE(int, moveSpeed, MoveSpeed);//�ƶ��ٶ�

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
	void setBullet(Slider* theBulletBar,int bullet);
	Slider* bulletBar;
	void addBulletBar();


	//�ѷ�����ӵ�
	Vector<Bullet*> bulletHasBeenShot;



	//��ʱ��
	void update(float dt);
protected:
	//�ƶ�����
	Animate* createAnimate(int direction, const char* name, int num);//�ƶ�����
	void setAction(int direction, const char* name, int num);//��ĳ�����˶�
};

#endif
