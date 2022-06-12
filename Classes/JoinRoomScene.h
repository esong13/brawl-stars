#pragma once
#include <string>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;

static const string JoinRoomInfo = "On-line mode is not supported yet, but will come soon ;)";

class JoinRoom : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void menuBackCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(JoinRoom);
};