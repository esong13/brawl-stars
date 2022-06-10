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
//启动摇杆
void HRocker::startRocker(bool _isStopOther)
{
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	rocker->setVisible(true);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rockerBG->setVisible(true);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
//停止摇杆
void HRocker::stopRocker()
{
	//精灵设置不可见，，取消监听
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	rocker->setVisible(false);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rocker->setVisible(false);
	Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
}

void HRocker::rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position)
{
	//添加摇杆背景图
	Sprite* spRockerBG = Sprite::create(rockerBGImageName);
	spRockerBG->setVisible(false);
	spRockerBG->setPosition(position);
	addChild(spRockerBG, 0, tag_rockerBG);
	spRockerBG->setOpacity(100);
	//添加摇杆上方那个可移动的图
	Sprite* spRocker = Sprite::create(rockerImageName);
	spRocker->setVisible(false);
	spRocker->setPosition(position);
	spRocker->setScale(spRockerBG->getScale() / 3);
	addChild(spRocker, 1, tag_rocker);
	spRocker->setOpacity(180);
	//摇杆背景图坐标
	rockerBGPosition = position;
	//摇杆背景图半径
	rockerBGR = spRockerBG->getContentSize().width / 2;
	listener = EventListenerTouchOneByOne::create();
	//绑定监听事件
	listener->onTouchBegan = CC_CALLBACK_2(HRocker::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HRocker::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HRocker::onTouchEnded, this);
	listener->setSwallowTouches(true);
}

//得到与角度对应的半径为r的圆上一坐标点
Point HRocker::getAnglePosition(float r, float angle)
{
	return Point(r*cos(angle),r*sin(angle));
}

float HRocker::getRad(Point pos1, Point pos2)
{
	//得到两点的坐标xy
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;
	//求出两边长度
	float x = px2 - px1;
	float y = py1 - py2;
	//求出两点直线距离
	float xie = sqrt(pow(x, 2) + pow(y, 2));
	float cos = x / xie;
	//求角度
	float rad = acos(cos);
	//当触屏y坐标<摇杆的y坐标时，取反值
	if (py1 > py2) {
		rad = -rad;
	}
	return rad;
}

bool HRocker::onTouchBegan(Touch* touch, Event* event)
{
	Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
	//得到触屏点坐标
	Point point = touch->getLocation();
	//判断是否单击到sp这个精灵
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
	//判断两个圆心的距离是否大于摇杆的背景半径
	if (sqrt(pow(point.x - rockerBGPosition.x, 2) + pow(point.y - rockerBGPosition.y, 2)) >= rockerBGR) {
		//得到触点与摇杆背景圆心形成的角度
		float angle = getRad(rockerBGPosition, point);
		//确保小圆运动范围在背景园内
		sp->setPosition(getAnglePosition(rockerBGR, angle)+rockerBGPosition);
	}
	else {
		//触点在背景圆内跟随触点移动
		sp->setPosition(point);
	}
	//获取方向
	auto basePosition = ((Sprite*)getChildByTag(tag_rockerBG))->getPosition();
	//摇杆方向的偏移
	this->dx = sp->getPosition().x - basePosition.x;
	this->dy = sp->getPosition().y - basePosition.y;
	//摇杆与原点的距离
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
