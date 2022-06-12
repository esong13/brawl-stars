#pragma once
#include <iostream>
#include <vector>
#include "cocos2d.h" 
#include "stop.h" 
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

	//����Ӣ�۵ĺ���
	
	//��������
	EventListenerTouchOneByOne* listener;
	//�����¼�
	virtual bool onTouchBegan(Touch* touch, Event* event);
	//��ҩ�ָ���ʱ��
	void bulletBackUpdate(float dt);
	void attackCDUpdate(float dt);
	//Ӣ�۷���
	int direction;
	void heroMoveDirection(int offsetx, int offsety);
	//ȫ��������power
	Vector<Sprite*> powerInTheWorld;

	//box����
	bool isBox1Dead;
	//Ӣ��
	SwordMan* hero;
	bool heroIsDead;
	Point getHeroPositionInMap();
	//��ײ����
	void thingsRectOn(Rect cr1, int action);
	int offsetx;
	int offsety;
	//��ײ�����Ϊ
	void thingsRectOnMove();//�ƶ���ײ

	void ObstacleCreate();
	Point tileCoordForPosition(Point position);/*����ת��*/
	static Scene* createScene(vector<int> chosenPlayer);
	void set1ViewPoint(const Point& point);
	void update(float dt);
	void EnterSoundSet(Ref* p);
	void EnterStop(Ref* p);
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
	Box* box1;
	Box* box2;
	Box* box3;
	Sprite* Hero;
	Sprite* FHero;
	Sprite* Hero1;
	Sprite* Hero2;
	Sprite* Hero3;
	int GameScenemp3;
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keyMap;
};