#pragma once
#include "cocos2d.h"
#include "AudioEngine.h"
#include "CreateRoomScene.h"
#include "JoinRoomScene.h"
#include "SettingsScene.h"
using namespace cocos2d;

class Start : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCreateRoomCallback(Ref* pSender);
    void menuJoinRoomCallback(Ref* pSender);
    void menuSettingsCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Start);
};