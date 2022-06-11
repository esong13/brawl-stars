#pragma once
#include <vector>
#include "cocos2d.h" 
#include "AudioEngine.h"
#include "GameScene.h"
using namespace std;
using namespace cocos2d;

#define Colt 1
#define Nita 2
#define Rosa 3
#define Shelly 4

class CreateRoom : public Scene
{
public:
    static Scene* createScene();

    virtual bool init();

    void menuColtCallback(Ref* pSender);
    void menuNitaCallback(Ref* pSender);
    void menuRosaCallback(Ref* pSender);
    void menuShellyCallback(Ref* pSender);
    void menuPlayCallback(Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(CreateRoom);
private:
    vector<int> _chosenPlayer = {};
};