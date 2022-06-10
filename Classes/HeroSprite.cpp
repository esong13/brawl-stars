#include "HeroSprite.h"

//初始化
bool HeroSprite::init(){
	if (!Item::init()) return false;
	this->isRun = false;
	this->direction = 1;
	setMagicPointMax(3);
	setMagicPointNow(3);
	setPower(1);
	setIsDead(false);
	return true;
}

//
void HeroSprite::heroSetAction(int direction, int num){
	setAction(direction, "sword_man", num);
}

//移动到
void HeroSprite::heroMoveTo(float x, float y) {
	float r = sqrt(x * x + y * y);
	position.x += x / r;
	position.y += y / r;
	roleSprite->setPosition(position);
}

void HeroSprite::setMagicBar(int magic)
{



}

//产生Animate
Animate* HeroSprite::createAnimate(int direction, const char* name, int num)
{
	auto* m_frameCache = SpriteFrameCache::getInstance();
	
	Vector<SpriteFrame*> frameArray;
	char heroSpriteString[100];
	sprintf(heroSpriteString, "%s/HDR/%s.plist", name, name);
	m_frameCache->addSpriteFramesWithFile(heroSpriteString);
	
	//将八方向简化为四方向动画
	if (direction > 4) {
		direction -= 4;
	}
	for (int i = 1; i <= num; i++) {
		sprintf(heroSpriteString, "%s%d-%d.png", name, direction, i);
		frameArray.pushBack(m_frameCache->getSpriteFrameByName(heroSpriteString));
	}
	Animation* animation = Animation::createWithSpriteFrames(frameArray);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	return Animate::create(animation);
}


//移动动作
void HeroSprite::setAction(int direction, const char* name, int num)
{
	roleSprite->stopActionByTag(100);
	auto* animate = createAnimate(direction, name, num);
	animate->setTag(100);
	roleSprite->runAction(animate);
}


//攻击行为
void HeroSprite::attack(Point targetPosition)
{

	magicPointNow--;//弹药减少
	setMagicBar(magicPointNow);//设置弹药条
}