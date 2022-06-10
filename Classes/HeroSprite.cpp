#include "HeroSprite.h"

//��ʼ��
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

//�ƶ���
void HeroSprite::heroMoveTo(float x, float y) {
	float r = sqrt(x * x + y * y);
	position.x += x / r;
	position.y += y / r;
	roleSprite->setPosition(position);
}

void HeroSprite::setMagicBar(int magic)
{



}

//����Animate
Animate* HeroSprite::createAnimate(int direction, const char* name, int num)
{
	auto* m_frameCache = SpriteFrameCache::getInstance();
	
	Vector<SpriteFrame*> frameArray;
	char heroSpriteString[100];
	sprintf(heroSpriteString, "%s/HDR/%s.plist", name, name);
	m_frameCache->addSpriteFramesWithFile(heroSpriteString);
	
	//���˷����Ϊ�ķ��򶯻�
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


//�ƶ�����
void HeroSprite::setAction(int direction, const char* name, int num)
{
	roleSprite->stopActionByTag(100);
	auto* animate = createAnimate(direction, name, num);
	animate->setTag(100);
	roleSprite->runAction(animate);
}


//������Ϊ
void HeroSprite::attack(Point targetPosition)
{

	magicPointNow--;//��ҩ����
	setMagicBar(magicPointNow);//���õ�ҩ��
}