#pragma once
#include <string>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::ui;

class Settings : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void menuBackCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Settings);
};