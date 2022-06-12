#ifndef __SPRITE_DEMO__
#define __SPRITE_DEMO__

#include "Const.h"
#include "cocos2d.h"
#include "Item.h"
#include "HeroSprite.h"
#include "SwordMan.h"
#include "Box.h"
USING_NS_CC;

class MyWorld : public cocos2d::Layer {
	//����GameScene�ĺϲ�����
	//vector<int> _chosenPlayer = {};
public:
	SwordMan* hero;
	bool heroIsDead;

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MyWorld); 

	int direction;

	//���̼����� 
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
	//��������
	EventListenerTouchOneByOne* listener;
	//�����¼�
	virtual bool onTouchBegan(Touch* touch, Event* event);
	//virtual void onTouchMoved(Touch* touch, Event* event);
	//virtual void onTouchEnded(Touch* touch, Event* event);


	void update(float dt);
	//��ҩ�ָ���ʱ��
	void bulletBackUpdate(float dt);
	void attackCDUpdate(float dt);

	//ȫ��������power
	Vector<Sprite*> powerInTheWorld;


	//box
	Box* box1;
	bool isBox1Dead;

};

#endif