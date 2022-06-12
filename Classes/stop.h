#pragma once
#include"cocos2d.h"
#include"GameScene.h"
using namespace cocos2d;

class Stop : public  Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(Stop);

	void EnterMyscene(Ref* p);

}; 
