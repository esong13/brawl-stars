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
	//来自GameScene的合并功能
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

	//全场定时器
	void update(float dt);
	//弹药恢复定时器
	void bulletBackUpdate(float dt);

	//攻击冷却定时器
	void attackCDUpdate(float dt);

	//全场的能量power
	Vector<Sprite*> powerInTheWorld;

};

#endif