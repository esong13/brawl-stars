#pragma once
#include <vector>
#include "cocos2d.h" 
#include "AudioEngine.h"
using namespace std;
using namespace cocos2d;
using namespace cocos2d::ui;

#define Colt 1     //white hair
#define Nita 2     //orange hair
#define Rosa 3     //violet hair
#define Shelly 4   //blue hair

class Game : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(Game);
private:
    vector<int> _chosenPlayer = {};
};