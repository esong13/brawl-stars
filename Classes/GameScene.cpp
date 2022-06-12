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



    /*��������*/
    auto menuitem = MenuItemImage::create("SoundSet.png", "SoundSet.png", CC_CALLBACK_1(Game::EnterSoundSet, this));/*�˵�������*/
    menuitem->setPosition(Vec2(Mysize.width / 2, Mysize.height / 2));
    auto SoundSet = Menu::create(menuitem, NULL);
    SoundSet->setScale(0.2);
    SoundSet->setPosition(Vec2(-150,-100));
    this->addChild(SoundSet,10);




	FHero = Sprite::create("Nita.png");/*Fhero ���㴦����ײ���� ΪHero����ʾ������*/
	FHero->setScale(0.1);
	FHero->setPosition(Mysize.width/2,Mysize.height/2);
	FHero->setVisible(false);
	_tilemap->addChild(FHero, 1);
	Hero = Sprite::create("Nita.png");
	Hero->setScale(0.05);
	Hero->setPosition(Mysize.width / 2, Mysize.height / 2);
	_tilemap->addChild(Hero, 1);




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
    Director::getInstance()->pushScene(TransitionSlideInL::create(1, SoundSet::createScene()));
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

void Game::update(float dt)/*ʵʱ�����ƶ� �����ײ�Ȳ���*/
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
	if (offsetx == 0 && offsety == 0)
		return;
	/*����Ϊ��ײ����demoʵ��*/
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
		
	if (cr1.intersectsRect(cr2))	//�Ƿ���ڽ���
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr3))	//�Ƿ���ڽ���
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr4))	//�Ƿ���ڽ���
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr5))	//�Ƿ���ڽ���
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr6))	//�Ƿ���ڽ���
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr7))	//�Ƿ���ڽ���
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	if (cr1.intersectsRect(cr11))	//�Ƿ���ڽ���
	{
		moveto = MoveTo::create(0.1f, Vec2(Hero->getPosition().x - offsetx, Hero->getPosition().y - offsety));
		Hero->runAction(moveto);
		return;
	}
	Hero->runAction(moveto);
	this->set1ViewPoint(Hero->getPosition());
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
	obs10 = Sprite::create("weilan.png");
	obs10->setPosition(0, 0);
	_tilemap->addChild(obs10);



}
