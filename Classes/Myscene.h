#pragma once
#include"cocos2d.h"

using namespace cocos2d;

class Myscene : public Layer
{
public:
	void Myscene::ObstacleCreate();
	Point Myscene::tileCoordForPosition(Point position);/*����ת��*/
	static Scene* createScene();
	virtual bool init();
	void set1ViewPoint(const Point& point);/*ceshi*/
	void update(float dt);
	void EnterSoundSet(Ref* p);
	CREATE_FUNC(Myscene);
	CC_SYNTHESIZE_RETAIN(TMXLayer*, _meta, Meta);
	CC_SYNTHESIZE_RETAIN(TMXTiledMap*, _tilemap, Tilemap);
	CC_SYNTHESIZE_RETAIN(TMXLayer*, _background, Background);

private:
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