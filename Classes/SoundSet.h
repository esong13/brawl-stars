#pragma once
#include"cocos2d.h"

using namespace cocos2d;

class SoundSet : public  Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SoundSet);

	void EnterMyscene(Ref* p);

};