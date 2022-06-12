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
#include "Const.h"
#include "Box.h"
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

	//加入英雄的函数
	
	//鼠标监听器
	EventListenerTouchOneByOne* listener;
	//触屏事件
	virtual bool onTouchBegan(Touch* touch, Event* event);
	//弹药恢复定时器
	void bulletBackUpdate(float dt);
	void attackCDUpdate(float dt);
	//英雄方向
	int direction;
	void heroMoveDirection(int offsetx, int offsety);
	//全场的能量power
	Vector<Sprite*> powerInTheWorld;

	//box箱子
	bool isBox1Dead;
	//英雄
	SwordMan* hero;
	bool heroIsDead;
	Point getHeroPositionInMap();
	//碰撞整合
	void thingsRectOn(Rect cr1, int action);
	int offsetx;
	int offsety;
	//碰撞后的行为
	void thingsRectOnMove();//移动碰撞

	void ObstacleCreate();
	Point tileCoordForPosition(Point position);/*坐标转换*/
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
	Sprite* obs11;
	Sprite* obs12;
	Sprite* obs13;
<<<<<<< Updated upstream
	Box* box1;
	Box* box2;
=======
>>>>>>> Stashed changes
	Sprite* Hero;
	Sprite* FHero;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
};