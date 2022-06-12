#ifndef __SPRITE_DEMO__
#define __SPRITE_DEMO__

#include "Const.h"
#include "cocos2d.h"
#include "Item.h"
#include "HeroSprite.h"
#include "SwordMan.h"
//#include "PlayerControllerListener.h"
USING_NS_CC;

class MyWorld : public cocos2d::Layer {
	//����GameScene�ĺϲ�����
	//vector<int> _chosenPlayer = {};
public:

	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MyWorld);

	int direction;

	SwordMan* hero;
	bool heroIsDead;

	//PlayerControllerListener* controllerListener;
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	//void EnterSoundSet(Ref* p);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;

	//ȫ����ʱ��
	void update(float dt);
	//��ҩ�ָ���ʱ��
	void bulletBackUpdate(float dt);

	//������ȴ��ʱ��
	void attackCDUpdate(float dt);

	//ȫ��������power
	Vector<Sprite*> powerInTheWorld;

};

#endif