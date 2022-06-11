#ifndef __SPRITE_DEMO__
#define __SPRITE_DEMO__

#include "Const.h"
#include "cocos2d.h"
#include "Item.h"
#include "HeroSprite.h"
#include "SwordMan.h"
USING_NS_CC;

class MyWorld : public cocos2d::Layer {
public:
	SwordMan* hero;
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MyWorld);

	int direction;


	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	//void EnterSoundSet(Ref* p);
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
	void update(float dt);
};

#endif