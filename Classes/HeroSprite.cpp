#include "HeroSprite.h"

//��ʼ��
bool HeroSprite::init(){

	if (!Item::init()) return false;

	this->isRun = false;
	this->direction = 1;
	setBulletMax(3);//��ҩ����
	setBulletNow(3);//��ǰ��ҩ
	this->scheduleUpdate();
	setAttackIsColding(false);//δ����ȴ��
	return true;
}

//������
void HeroSprite::heroSetAction(int direction, int num){
	setAction(direction, "sword_man", num);
}

//�ƶ���
void HeroSprite::heroMoveTo(float x, float y,float heroSpeed) {
	float r = sqrt(x * x + y * y);
	getRoleSprite()->setPosition(getRoleSprite()->getPosition()+Point((x / r) , (y / r) )* heroSpeed);
}

//������ҩ��
Slider* HeroSprite::createBulletBar()
{
	Slider* slider = Slider::create();
	slider->loadBarTexture("sliderTrack.png");
	slider->loadProgressBarTexture("sliderProgress.png");
	slider->setPercent(100);
	return slider;
}
//���µ�ҩ��״̬
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
	//��������ʾ��ҩ��
	bulletBar = createBulletBar();
	bulletBar->setPosition(Point(getRoleSprite()->getPosition().x + 6, getRoleSprite()->getPosition().y + 24));
	bulletBar->setScale(0.1f, 0.3f);
	getRoleSprite()->addChild(bulletBar);
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


	bulletNow--;//��ҩ����
	setBullet(bulletBar,bulletNow);//���õ�ҩ��
}







//��ʱ��
void HeroSprite::update(float dt)
{
	
	//�ж��ѷ����ӵ��Ƿ񵽴��յ����

	for (int i = 0; i < bulletHasBeenShot.size(); i++){
		Bullet* bullet = bulletHasBeenShot.at(i);
		if (bullet->getBulletSprite()->getPosition() == bullet->getBulletTerminal()) {
			bulletHasBeenShot.erase(i);
			removeChild(bullet, true);
			continue;
		}
	}
	//�ж��ӵ��Ƿ���ײ����




}