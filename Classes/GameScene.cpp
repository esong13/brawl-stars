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
<<<<<<< Updated upstream
	_tilemap = TMXTiledMap::create("Map.tmx");
	_tilemap->setPosition(800, 500);
=======
	_tilemap = TMXTiledMap::create("map.tmx");
	_tilemap->setAnchorPoint(Point(0.5,0.5));
>>>>>>> Stashed changes
	this->addChild(_tilemap, -1);



    /*��������*/
    auto menuitem = MenuItemImage::create("SoundSet.png", "SoundSet.png", CC_CALLBACK_1(Game::EnterSoundSet, this));/*�˵�������*/
    menuitem->setPosition(Vec2(Mysize.width / 2, Mysize.height / 2));
    auto SoundSet = Menu::create(menuitem, NULL);
    SoundSet->setScale(0.2);
    SoundSet->setPosition(Vec2(-150,-100));
    this->addChild(SoundSet,10);



<<<<<<< Updated upstream
	//����Ӣ��
	FHero = Sprite::create("Colt.PNG");/*Fhero ���㴦����ײ���� ΪHero����ʾ������*/
	FHero->setScale(1);
	FHero->setPosition(ROLENODE_POSITION_X, ROLENODE_POSITION_Y);//�Զ�������ص�
	FHero->setVisible(false);
	_tilemap->addChild(FHero, 1);


	hero = SwordMan::create();;
	hero->setScale(1);
	hero->setPosition(ROLENODE_POSITION_X, ROLENODE_POSITION_Y);//�Զ�������ص�
	hero->bindSprite(Sprite::create("Colt.PNG"));
	hero->addBulletBar();
	hero->addHealthBar();
	hero->heroSetAction(hero->direction, 1);
	this->heroIsDead = false;

	_tilemap->addChild(hero, 1);
	//�ӵ��ָ�
	schedule(CC_SCHEDULE_SELECTOR(Game::bulletBackUpdate), 2, 10000, 2.0f);

	//��������
	listener = EventListenerTouchOneByOne::create();
	//�󶨼����¼�
	listener->onTouchBegan = CC_CALLBACK_2(Game::onTouchBegan, this);

	listener->setSwallowTouches(true);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//����

=======

	FHero = Sprite::create("Nita.png");/*Fhero ���㴦����ײ���� ΪHero����ʾ������*/
	FHero->setScale(2);
	FHero->setPosition(Mysize.width/2,Mysize.height);
	FHero->setVisible(false);
	_tilemap->addChild(FHero, 1);
	Hero = Sprite::create("Nita.png");
	Hero->setScale(1);
	Hero->setPosition(Mysize.width / 2, Mysize.height);
	_tilemap->addChild(Hero, 1);
>>>>>>> Stashed changes




	ObstacleCreate();/*���ڲ��Ե�obstacles*/



    auto keyListener = EventListenerKeyboard::create();/*���̲���*/




    keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keyMap[keyCode] = true;
        switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_SPACE:
        {
            //�½�jumpָ��,ָ��JumpBy::create()����һ��Action��ָ�����
            Action* jump = JumpBy::create(.5, Vec2(0, 0), 20, 1);
            //ִ��,������һ��
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

void Game::EnterSoundSet(Ref* p)/*�л�����*/
{
    Director::getInstance()->pushScene( SoundSet::createScene());
}
void Game::set1ViewPoint(const Point& point)/*�ӽ��϶�*/
{
	Size winSize = Director::getInstance()->getWinSize();

	int x = point.x;
	int y = point.y;
	

	Point actualPoint(x, y);
	Point centerOfView(winSize.width / 2, winSize.height / 2);
	Point viewPoint = centerOfView - actualPoint;
	_tilemap->setPosition(viewPoint);
}

//���������
bool Game::onTouchBegan(Touch* touch, Event* event)
{
	//�õ�����������
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

Point Game::getHeroPositionInMap()
{
	return Point(hero->getRoleSprite()->getPosition() + hero->getPosition());
}

void Game::thingsRectOnMove() {
	hero->getRoleSprite()->setPosition(Vec2(hero->getRoleSprite()->getPosition().x - offsetx, hero->getRoleSprite()->getPosition().y - offsety));
}


void Game::thingsRectOn(Rect cr1,int action)
{
	Rect cr2 = obs1->getBoundingBox();
	Rect cr3 = obs2->getBoundingBox();
	Rect cr4 = obs3->getBoundingBox();
	Rect cr5 = obs4->getBoundingBox();
	Rect cr6 = obs5->getBoundingBox();
	Rect cr7 = obs6->getBoundingBox();
	Rect cr8 = obs7->getBoundingBox();
	Rect cr9 = obs8->getBoundingBox();
	Rect cr10= obs9->getBoundingBox();
	Rect cr11 = obs10->getBoundingBox();
	Rect cr12 = obs11->getBoundingBox();
	Rect cr13 = obs12->getBoundingBox();
	Rect cr14 = obs13->getBoundingBox();

	if (cr1.intersectsRect(cr2)
		|| cr1.intersectsRect(cr3)
		|| cr1.intersectsRect(cr4)
		|| cr1.intersectsRect(cr5)
		|| cr1.intersectsRect(cr6)
		|| cr1.intersectsRect(cr7)
		|| cr1.intersectsRect(cr8)
		|| cr1.intersectsRect(cr9)
		|| cr1.intersectsRect(cr10)
		|| cr1.intersectsRect(cr11)
		|| cr1.intersectsRect(cr12)
		|| cr1.intersectsRect(cr13)
		|| cr1.intersectsRect(cr14))	//�Ƿ���ڽ���
	{
		switch (action) {
			case 1:
				thingsRectOnMove();
				break;
			case 2:

				break;
		}
		return;
	}
}



void Game::update(float dt)/*ʵʱ�����ƶ� �����ײ�Ȳ���*/
{
	log("1");
	auto w = EventKeyboard::KeyCode::KEY_W;
	auto s = EventKeyboard::KeyCode::KEY_S;
	auto a = EventKeyboard::KeyCode::KEY_A;
	auto d = EventKeyboard::KeyCode::KEY_D;
	offsetx = 0;
	offsety = 0;
	if (keyMap[a])
	{
		offsetx = -1;
	}
	if (keyMap[d])
	{
		offsetx = 1;
	}
	if (keyMap[w])
	{
		offsety = 1;
	}
	if (keyMap[s])
	{
		offsety = -1;
	}
	//�����ƶ�
	if (offsetx == 0 && offsety == 0) {
		this->set1ViewPoint(getHeroPositionInMap());
		hero->isRun = false;
		hero->heroSetAction(hero->direction, 1);
		return;
	}
	heroMoveDirection(offsetx, offsety);

	//�ж��Ƿ����ʰȡbuff
	
	for (int i = 0; i < powerInTheWorld.size(); i++) {
		Sprite* power = powerInTheWorld.at(i);
		if (power->getPosition() == hero->getPosition()) {
			//��ʰȡ
			hero->setPower(hero->getPower() + 1);
			hero->setHealthPointMax(hero->getHealthPointMax() + 500);
			hero->setHealth(hero->healthBar, hero->getHealthPointNow() + 500);
			powerInTheWorld.erase(i);
			removeChild(power, true);
			continue;
		}
	}
	
	
	FHero->setPosition(getHeroPositionInMap());
	auto moveto = MoveTo::create(0.1f, Vec2(FHero->getPosition().x + offsetx, FHero->getPosition().y + offsety));
	FHero->runAction(moveto);
	Rect cr1 = FHero->getBoundingBox();
	thingsRectOn(cr1, 1);
	/*
	for (int i = 0; i < hero->bulletHasBeenShot.size(); i++) {
		Bullet* bullet = hero->bulletHasBeenShot.at(i);
		Sprite* Fbullet= Sprite::create("sword_light.png");
		Fbullet->setScale(1);
		Fbullet->setPosition(bullet->getBulletSprite()->getPosition() + getHeroPositionInMap());
		Fbullet->setVisible(false);
		_tilemap->addChild(Fbullet, 1);

		if (Fbullet->getPosition() == bullet->getBulletTerminal()) {
			hero->bulletHasBeenShot.erase(i);
			removeChild(bullet, true);
			continue;
		}
	}
*/
	this->set1ViewPoint(getHeroPositionInMap());

}

Point Game::tileCoordForPosition(Point position)
{
	//�������Ŀ�ĵ������x������ת������Ƭ��ͼ�е�x�������

	int x = position.x / _tilemap->getTileSize().width;
	//�������Ŀ�ĵ������y������ת������Ƭ��ͼ�е�y�������

	int y = ((_tilemap->getMapSize().height * _tilemap->getTileSize().height) - position.y) / _tilemap->getTileSize().height;
	return Vec2(x, y);
}





void Game::ObstacleCreate()
{
	Size Mysize = Director::getInstance()->getVisibleSize();
	obs1 = Sprite::create("bigtree.png");
	obs1->setPosition(ROLENODE_POSITION_X-100, ROLENODE_POSITION_Y+100);
	_tilemap->addChild(obs1);
	obs2 = Sprite::create("bigtree.png");
	obs2->setPosition(ROLENODE_POSITION_X-200, ROLENODE_POSITION_Y);
	_tilemap->addChild(obs2);
	obs3 = Sprite::create("bigtree.png");
	obs3->setPosition(ROLENODE_POSITION_X+50, ROLENODE_POSITION_Y+120);
	_tilemap->addChild(obs3);
	obs4 = Sprite::create("bigtree.png");
	obs4->setPosition(ROLENODE_POSITION_X+100, ROLENODE_POSITION_Y+78);
	_tilemap->addChild(obs4);
	obs5 = Sprite::create("bigstone.png");
	obs5->setPosition(ROLENODE_POSITION_X+123, ROLENODE_POSITION_Y+66);
	_tilemap->addChild(obs5);
	obs6 = Sprite::create("bigstone.png");
	obs6->setPosition(ROLENODE_POSITION_X-77, ROLENODE_POSITION_Y+99);
	_tilemap->addChild(obs6);
	obs7 = Sprite::create("bigstone.png");
	obs7->setPosition(ROLENODE_POSITION_X-24, ROLENODE_POSITION_Y-67);
	_tilemap->addChild(obs7);
	obs8 = Sprite::create("bigstone.png");
	obs8->setPosition(ROLENODE_POSITION_X-55, ROLENODE_POSITION_Y);
	_tilemap->addChild(obs8);
	obs9 = Sprite::create("bigstone.png");
	obs9->setPosition(ROLENODE_POSITION_X+88, ROLENODE_POSITION_Y-12);
	_tilemap->addChild(obs9);
	obs10 = Sprite::create("treelinex.png");
<<<<<<< Updated upstream
	obs10->setPosition(17 * 32 - 10, 9 * 32 + 20);
	_tilemap->addChild(obs10);
	obs11 = Sprite::create("treeliney.png");
	obs11->setPosition(9 * 32 + 20, 16 * 32 + 15);
	_tilemap->addChild(obs11);
	obs12 = Sprite::create("treeliney.png");
	obs12->setPosition(23 * 32 + 20, 16 * 32 + 15);
	_tilemap->addChild(obs12);
	obs13 = Sprite::create("treelinex.png");
	obs13->setPosition(17 * 32 - 10, 23 * 32 + 20);
=======
	obs10->setPosition(17*32-10, 9*32+20);
	_tilemap->addChild(obs10);
	obs11 = Sprite::create("treeliney.png");
	obs11->setPosition(9*32+20, 16*32+15);
	_tilemap->addChild(obs11);
	obs12 = Sprite::create("treeliney.png");
	obs12->setPosition(23 * 32+20, 16 * 32 +15);
	_tilemap->addChild(obs12);
	obs13 = Sprite::create("treelinex.png");
	obs13->setPosition(17 * 32 - 10,  23* 32+20);
>>>>>>> Stashed changes
	_tilemap->addChild(obs13);

}
void Game::bulletBackUpdate(float dt)
{
	hero->setBullet(hero->bulletBar, hero->getBulletNow() + 1);
}

void Game::attackCDUpdate(float dt)
{
	hero->setAttackIsColding(false);
}