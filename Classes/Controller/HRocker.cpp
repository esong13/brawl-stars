#include "HRocker.h"

HRocker* HRocker::createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position)
{
	HRocker* layer = HRocker::create();
	if (layer) {
		layer->rockerInit(rockerImageName, rockerBGImageName, position);
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return NULL;
}
//����ҡ��
void HRocker::startRocker(bool _isStopOther)
{
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	rocker->setVisible(true);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rockerBG->setVisible(true);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
//ֹͣҡ��
void HRocker::stopRocker()
{
	//�������ò��ɼ�����ȡ������
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	rocker->setVisible(false);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rocker->setVisible(false);
	Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
}

void HRocker::rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position)
{
	//���ҡ�˱���ͼ
	Sprite* spRockerBG = Sprite::create(rockerBGImageName);
	spRockerBG->setVisible(false);
	spRockerBG->setPosition(position);
	addChild(spRockerBG, 0, tag_rockerBG);
	spRockerBG->setOpacity(100);
	//���ҡ���Ϸ��Ǹ����ƶ���ͼ
	Sprite* spRocker = Sprite::create(rockerImageName);
	spRocker->setVisible(false);
	spRocker->setPosition(position);
	spRocker->setScale(spRockerBG->getScale() / 3);
	addChild(spRocker, 1, tag_rocker);
	spRocker->setOpacity(180);
	//ҡ�˱���ͼ����
	rockerBGPosition = position;
	//ҡ�˱���ͼ�뾶
	rockerBGR = spRockerBG->getContentSize().width / 2;
	listener = EventListenerTouchOneByOne::create();
	//�󶨼����¼�
	listener->onTouchBegan = CC_CALLBACK_2(HRocker::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HRocker::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HRocker::onTouchEnded, this);
	listener->setSwallowTouches(true);
}

//�õ���Ƕȶ�Ӧ�İ뾶Ϊr��Բ��һ�����
Point HRocker::getAnglePosition(float r, float angle)
{
	return Point(r*cos(angle),r*sin(angle));
}

float HRocker::getRad(Point pos1, Point pos2)
{
	//�õ����������xy
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;
	//������߳���
	float x = px2 - px1;
	float y = py1 - py2;
	//�������ֱ�߾���
	float xie = sqrt(pow(x, 2) + pow(y, 2));
	float cos = x / xie;
	//��Ƕ�
	float rad = acos(cos);
	//������y����<ҡ�˵�y����ʱ��ȡ��ֵ
	if (py1 > py2) {
		rad = -rad;
	}
	return rad;
}

bool HRocker::onTouchBegan(Touch* touch, Event* event)
{
	Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
	//�õ�����������
	Point point = touch->getLocation();
	//�ж��Ƿ񵥻���sp�������
	if (sp->getBoundingBox().containsPoint(point)) {
		sp->setOpacity(255);
		isCanMove = true;
	}
	return true;
}

void HRocker::onTouchMoved(Touch* touch, Event* event)
{
	if (!isCanMove) {
		return;
	}
	Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
	Point point = touch->getLocation();
	//�ж�����Բ�ĵľ����Ƿ����ҡ�˵ı����뾶
	if (sqrt(pow(point.x - rockerBGPosition.x, 2) + pow(point.y - rockerBGPosition.y, 2)) >= rockerBGR) {
		//�õ�������ҡ�˱���Բ���γɵĽǶ�
		float angle = getRad(rockerBGPosition, point);
		//ȷ��СԲ�˶���Χ�ڱ���԰��
		sp->setPosition(getAnglePosition(rockerBGR, angle)+rockerBGPosition);
	}
	else {
		//�����ڱ���Բ�ڸ��津���ƶ�
		sp->setPosition(point);
	}
	//��ȡ����
	auto basePosition = ((Sprite*)getChildByTag(tag_rockerBG))->getPosition();
	//ҡ�˷����ƫ��
	this->dx = sp->getPosition().x - basePosition.x;
	this->dy = sp->getPosition().y - basePosition.y;
	//ҡ����ԭ��ľ���
	float r = sqrt(dx * dx + dy * dy);
	if (dx > 0 && fabs(dy / r) < sin(15 * PI / 180))
	{
		CCLOG("RIGHT");
		this->direction = RIGHT;
	}
	else if (dx < 0 && fabs(dy / r) < sin(15 * PI / 180))
	{
		CCLOG("LEFT");
		this->direction = LEFT;
	}
	else if (dy > 0 && fabs(dx / r) < sin(15 * PI / 180))
	{
		CCLOG("UP");
		this->direction = UP;
	}
	else if (dy < 0 && fabs(dx / r) < sin(15 * PI / 180))
	{
		CCLOG("DOWN");
		this->direction = DOWN;
	}
	else if (dx > 0 && dy > 0)
	{
		CCLOG("RIGHT-UP");
		this->direction = RIGHT_UP;
	}
	else if (dx > 0 && dy < 0)
	{
		CCLOG("RIGHT-DOWN");
		this->direction = RIGHT_DOWN;
	}
	else if (dx < 0 && dy < 0)
	{
		CCLOG("LEFT-DOWN");
		this->direction = LEFT_DOWN;
	}
	else if (dx < 0 && dy > 0)
	{
		CCLOG("LEFT-UP");
		this->direction = LEFT_UP;
	}	
}

void HRocker::onTouchEnded(Touch* touch, Event* event)
{
	if (!isCanMove) {
		return;
	}
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rocker->stopAllActions();
	rocker->setOpacity(180);
	rocker->runAction(MoveTo::create(0.08, rockerBG->getPosition()));
	isCanMove = false;
}
