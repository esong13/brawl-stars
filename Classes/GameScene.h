#pragma once
#include <iostream>
#include <vector>
#include "cocos2d.h" 
#include "Myscene.h" 
#include "My2scene.h" 
#include "SoundSet.h" 
#include "AudioEngine.h"
#include "HeroSprite.h"
#include "SwordMan.h"
using namespace std;
using namespace cocos2d;

#define Colt 1     //white hair
#define Nita 2     //orange hair
#define Rosa 3     //violet hair
#define Shelly 4   //blue hair

static vector<int> _chosenPlayer = {};

class Game : public Layer
{
public:

    virtual bool init();


    // implement the "static create()" method manually
    CREATE_FUNC(Game);


	void ObstacleCreate();
	Point tileCoordForPosition(Point position);/*×ø±ê×ª»»*/
	static Scene* createScene(vector<int> chosenPlayer);
	void set1ViewPoint(const Point& point);
	void update(float dt);
	void EnterSoundSet(Ref* p);
private:
	TMXTiledMap* _tilemap;
	Sprite* obs1;
	Sprite* obs2;
	Sprite* obs3;
	Sprite* obs4;
	Sprite* obs5;
	Sprite* obs6;
	Sprite* obs7;
	Sprite* obs8;
	Sprite* obs9;
	Sprite* obs10;
	Sprite* Hero;
	Sprite* FHero;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
};