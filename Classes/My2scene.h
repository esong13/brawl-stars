#pragma once
#include"cocos2d.h"

using namespace cocos2d;

class My2scene : public  Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(My2scene);

	void EnterMyscene(Ref* p);

};