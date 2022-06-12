#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"AudioEngine.h"
using namespace cocos2d;
using namespace cocos2d::ui;
static int _audioID= AudioEngine::INVALID_AUDIO_ID;;
class SoundSet : public  Layer
{
public:
	static Scene* createScene(int audioID);

	virtual bool init();

	CREATE_FUNC(SoundSet);

	void EnterMyscene(Ref* p);

};