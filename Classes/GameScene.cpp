#include "GameScene.h"
Scene* Game::createScene(vector<int> chosenPlayer)
{
	auto scene = Scene::create();
	auto layer = Game::create();
	scene->addChild(layer);
	for(int i=0;i<chosenPlayer.size();i++)
	{
		_chosenPlayer.push_back(chosenPlayer[i]);
	}
	return scene;
}


bool Game::init()
{
    if (!Layer::init())
    {
        return false;
    }
	this->scheduleUpdate();
    //set the background music and it volume
   

    //initialize the map
	

    //sync the window size with the map
 
    auto Mysize = Director::getInstance()->getVisibleSize();

    //add the map to the center of the window
	_tilemap = TMXTiledMap::create("map.tmx");
	this->addChild(_tilemap, -1);



    /*音量调整*/
    auto menuitem = MenuItemImage::create("SoundSet.png", "SoundSet.png", CC_CALLBACK_1(Game::EnterSoundSet, this));/*菜单的设置*/
    menuitem->setPosition(Vec2(Mysize.width / 2, Mysize.height / 2));
    auto SoundSet = Menu::create(menuitem, NULL);
    SoundSet->setScale(0.2);
    SoundSet->setPosition(Vec2(-150,-100));
    this->addChild(SoundSet,10);



	//创建英雄
	FHero = Sprite::create("Colt.PNG");/*Fhero 方便处理碰撞问题 为Hero不显示的虚拟*/
	FHero->setScale(2);
	FHero->setPosition(ROLENODE_POSITION_X, ROLENODE_POSITION_Y);//自定义出生地点
	FHero->setVisible(false);
	_tilemap->addChild(FHero, 1);


	hero = SwordMan::create();;
	hero->setScale(1);
	hero->setPosition(ROLENODE_POSITION_X, ROLENODE_POSITION_Y);//自定义出生地点
	hero->bindSprite(Sprite::create("Colt.PNG"));
	hero->addBulletBar();
	hero->addHealthBar();
	hero->heroSetAction(hero->direction, 1);
	this->heroIsDead = false;

	_tilemap->addChild(hero, 1);
	//子弹恢复
	schedule(CC_SCHEDULE_SELECTOR(Game::bulletBackUpdate), 2, 10000, 2.0f);

	//鼠标监听器
	listener = EventListenerTouchOneByOne::create();
	//绑定监听事件
	listener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);

	listener->setSwallowTouches(true);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);







	ObstacleCreate();/*用于测试的obstacles*/



    auto keyListener = EventListenerKeyboard::create();/*键盘操作*/




    keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keyMap[keyCode] = true;
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_SPACE:
        {
            //新建jump指针,指向JumpBy::create()返回一个Action的指针对象
            Action* jump = JumpBy::create(.5, Vec2(0, 0), 20, 1);
            //执行,让它跳一下
            Hero->runAction(jump); break;
        }
        }

    };
    keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {

        keyMap[keyCode] = false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

    return true;
}

void Game::EnterSoundSet(Ref* p)/*切换场景*/
{
    Director::getInstance()->pushScene(TransitionSlideInL::create(1, SoundSet::createScene()));
}
void Game::set1ViewPoint(const Point& point)/*视角拖动*/
{
	Size winSize = Director::getInstance()->getWinSize();

	int x = point.x;
	int y = point.y;
	

	Point actualPoint(x, y);
	Point centerOfView(winSize.width / 2, winSize.height / 2);
	Point viewPoint = centerOfView - actualPoint;
	_tilemap->setPosition(viewPoint);
}

//鼠标点击攻击
bool Game::onTouchBegan(Touch* touch, Event* event)
{
	//得到触屏点坐标
	Point point = touch->getLocation();
	if (!hero->getAttackIsColding()) {
		scheduleOnce(CC_SCHEDULE_SELECTOR(Game::attackCDUpdate), hero->getAttackCDTime());
	}
	hero->attack(point);
	return true;
}

void Game::heroMoveDirection(int offsetx, int offsety)
{
	if (offsetx < 0 && offsety == 0) { direction = LEFT; }
	else if (offsetx > 0 && offsety == 0) { direction = RIGHT; }
	else if (offsetx == 0 && offsety < 0) { direction = DOWN; }
	else if (offsetx == 0 && offsety > 0) { direction = UP; }
	else if (offsetx < 0 && offsety > 0) { direction = LEFT_UP; }
	else if (offsetx < 0 && offsety < 0) { direction = LEFT_DOWN; }
	else if (offsetx > 0 && offsety > 0) { direction = RIGHT_UP; }
	else if (offsetx > 0 && offsety < 0) { direction = RIGHT_DOWN; }


	if (hero->isRun == false)
	{
		hero->isRun = true;
		hero->direction = direction;
		hero->heroSetAction(hero->direction, 4);
	}
	else if (hero->isRun == true)
	{
		if (hero->direction != direction)
		{
			hero->direction = direction;
			hero->heroSetAction(hero->direction, 4);
		}
	}
	hero->heroMoveTo(offsetx, offsety, hero->getMoveSpeed());
}


void Game::update(float dt)/*实时监听移动 检测碰撞等操作*/
{
	log("1");
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	int offsetx = 0;
	int offsety = 0;
	if (keyMap[a])
	{
		offsetx = -4;
	}
	if (keyMap[d])
	{
		offsetx = 4;
	}
	if (keyMap[w])
	{
		offsety = 4;
	}
	if (keyMap[s])
	{
		offsety = -4;
	}
	//键盘移动
	if (offsetx == 0 && offsety == 0) {
		hero->isRun = false;
		hero->heroSetAction(hero->direction, 1);
		return;
	}
	heroMoveDirection(offsetx, offsety);

	//判断是否可能拾取buff
	/*
	for (int i = 0; i < powerInTheWorld.size(); i++) {
		Sprite* power = powerInTheWorld.at(i);
		if (power->getPosition() == hero->getPosition()) {
			//若拾取
			hero->setPower(hero->getPower() + 1);
			hero->setHealthPointMax(hero->getHealthPointMax() + 500);
			hero->setHealth(hero->healthBar, hero->getHealthPointNow() + 500);
			powerInTheWorld.erase(i);
			removeChild(power, true);
			continue;
		}
	}
	*/
	/*
	FHero->setPosition(hero->getPosition());
	auto moveto = MoveTo::create(0.1f, Vec2(FHero->getPosition().x + offsetx, FHero->getPosition().y + offsety));
	FHero->runAction(moveto);
	Rect cr1 = FHero->getBoundingBox();
	Rect cr2 = obs1->getBoundingBox();
	Rect cr3 = obs2->getBoundingBox();
	Rect cr4 = obs3->getBoundingBox();
	Rect cr5 = obs4->getBoundingBox();
	Rect cr6 = obs5->getBoundingBox();
	Rect cr7 = obs6->getBoundingBox();
	Rect cr11 = obs10->getBoundingBox();

	if (cr1.intersectsRect(cr2))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr3))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr4))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr5))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr6))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr7))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr11))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	Hero->runAction(moveto);
	this->set1ViewPoint(Hero->getPosition());
*/

	/*以下为碰撞检测的demo实现*/
	/*
	FHero->setPosition(Hero->getPosition());
	auto moveto = MoveTo::create(0.1f, Vec2(FHero->getPosition().x + offsetx, FHero->getPosition().y + offsety));
	FHero->runAction(moveto);
	Rect cr1 = FHero->getBoundingBox();
	Rect cr2 = obs1->getBoundingBox();
	Rect cr3 = obs2->getBoundingBox();
	Rect cr4 = obs3->getBoundingBox();
	Rect cr5 = obs4->getBoundingBox();
	Rect cr6 = obs5->getBoundingBox();
	Rect cr7 = obs6->getBoundingBox();
	Rect cr11 = obs10->getBoundingBox();
		
	if (cr1.intersectsRect(cr2))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr3))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr4))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr5))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr6))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr7))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr11))	//是否存在交集
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	Hero->runAction(moveto);
	this->set1ViewPoint(Hero->getPosition());
	*/




}

Point Game::tileCoordForPosition(Point position)
{
	//将人物的目的的坐标的x轴坐标转换成瓦片地图中的x轴的坐标

	int x = position.x / _tilemap->getTileSize().width;
	//将人物的目的的坐标的y轴坐标转换成瓦片地图中的y轴的坐标

	int y = ((_tilemap->getMapSize().height * _tilemap->getTileSize().height) - position.y) / _tilemap->getTileSize().height;
	return Vec2(x, y);
}

void Game::ObstacleCreate()
{
	Size Mysize = Director::getInstance()->getVisibleSize();
	obs1 = Sprite::create("tree.png");
	obs1->setPosition(Mysize.width / 2 - 200, Mysize.height / 2);
	_tilemap->addChild(obs1);
	obs2 = Sprite::create("tree.png");
	obs2->setPosition(Mysize.width / 2 - 200, Mysize.height / 2 + 100);
	_tilemap->addChild(obs2);
	obs3 = Sprite::create("tree.png");
	obs3->setPosition(Mysize.width / 2 - 100, Mysize.height / 2 + 99);
	_tilemap->addChild(obs3);
	obs4 = Sprite::create("tree.png");
	obs4->setPosition(Mysize.width / 2 - 200 - 54, Mysize.height / 2 + 46);
	_tilemap->addChild(obs4);
	obs5 = Sprite::create("tree.png");
	obs5->setPosition(Mysize.width / 2 - 200 - 99, Mysize.height / 2 + 78);
	_tilemap->addChild(obs5);
	obs6 = Sprite::create("tree.png");
	obs6->setPosition(Mysize.width / 2 - 200, Mysize.height / 2);
	_tilemap->addChild(obs6);
	obs7 = Sprite::create("tree.png");
	obs7->setPosition(Mysize.width / 2 - 200, Mysize.height / 2);
	_tilemap->addChild(obs7);
	obs8 = Sprite::create("tree.png");
	obs8->setPosition(Mysize.width / 2 - 200, Mysize.height / 2);
	_tilemap->addChild(obs8);
	obs9 = Sprite::create("tree.png");
	obs9->setPosition(Mysize.width / 2 - 200, Mysize.height / 2);
	_tilemap->addChild(obs9);
	obs10 = Sprite::create("tree.png");
	obs10->setPosition(0, 0);
	_tilemap->addChild(obs10);



}
void Game::bulletBackUpdate(float dt)
{
	hero->setBullet(hero->bulletBar, hero->getBulletNow() + 1);
}

void Game::attackCDUpdate(float dt)
{
	hero->setAttackIsColding(false);
}