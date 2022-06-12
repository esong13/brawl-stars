#include "HeroSprite.h"

//初始化
bool HeroSprite::init(){

	if (!Item::init()) return false;

	this->isRun = false;
	this->direction = 1;
	setBulletMax(3);//弹药上限
	setBulletNow(3);//当前弹药
	this->scheduleUpdate();
	setAttackIsColding(false);//未在冷却中
	return true;
}

//父函数
void HeroSprite::heroSetAction(int direction, int num){
	setAction(direction, "sword_man", num);
}

//移动到
void HeroSprite::heroMoveTo(float x, float y,float heroSpeed) {
	float r = sqrt(x * x + y * y);
	getRoleSprite()->setPosition(getRoleSprite()->getPosition()+Point((x / r) , (y / r) )* heroSpeed);
}

//创建弹药条
Slider* HeroSprite::createBulletBar()
{
	Slider* slider = Slider::create();
	slider->loadBarTexture("sliderTrack.png");
	slider->loadProgressBarTexture("sliderProgress.png");
	slider->setPercent(100);
	return slider;
}
//更新弹药条状态
void HeroSprite::setBullet(Slider* theBulletBar,int bullet)
{
	if (bullet >= 0 && bullet <= bulletMax)
	{
		setBulletNow(bullet);
	}
	theBulletBar->setPercent(100.0f * bulletNow / bulletMax);
}

void HeroSprite::addBulletBar()
{
	//创建并显示弹药条
	bulletBar = createBulletBar();
	bulletBar->setPosition(Point(getRoleSprite()->getPosition().x + 6, getRoleSprite()->getPosition().y + 24));
	bulletBar->setScale(0.1f, 0.3f);
	getRoleSprite()->addChild(bulletBar);
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


	bulletNow--;//弹药减少
	setBullet(bulletBar,bulletNow);//设置弹药条
}







//定时器
void HeroSprite::update(float dt)
{
	
	//判断已发射子弹是否到达终点清除

	for (int i = 0; i < bulletHasBeenShot.size(); i++){
		Bullet* bullet = bulletHasBeenShot.at(i);
		if (bullet->getBulletSprite()->getPosition() == bullet->getBulletTerminal()) {
			bulletHasBeenShot.erase(i);
			removeChild(bullet, true);
			continue;
		}
	}
	//判断子弹是否碰撞。。




}