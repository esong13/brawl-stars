

#include "SpriteDemo.h"




Scene* MyWorld::createScene(){
    auto scene = Scene::create();
    auto layer = MyWorld::create();
    scene->addChild(layer);
    return scene;
}

bool MyWorld::init()
{
	if (!Layer::init()) return false;

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto* layer1 = Layer::create();
    auto* pBackground = Sprite::create("firstmap.png");
    pBackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    pBackground->setScale(0.8f);
    layer1->addChild(pBackground);
    this->addChild(layer1);

    //auto* layer2 = Layer::create();
    //rocker = HRocker::createHRocker("rocker.png", "rockerBG.png", Point(100, 100));
    //layer2->addChild(rocker);
    //rocker->startRocker(true);
    //this->addChild(layer2);
    //addChild(rocker);
    //rocker->startRocker(true);

    hero = SwordMan::create();
    hero->setPosition(100, 100);
    hero->bindSprite(Sprite::create("SpirtOne/sword_man/sword_man1-1.png"));
    addChild(hero);
    hero->heroSetAction(hero->direction, 1);
    
    /*
	//创建一个精灵
	Sprite* sprite = Sprite::create("barn-owl.png");
    sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    this->addChild(sprite, 0);
    sprite->setVisible(false);

    //通过图集创建金币精灵
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("coin_gold/HDR/coin_gold.plist");
    Sprite* coin_goldSprite = Sprite::createWithSpriteFrameName("coin_gold-0.png");
    coin_goldSprite->setScale(2.0f);
    this->addChild(coin_goldSprite);
    coin_goldSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

    //创建金币动画
    auto coin_goldcahce = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> coin_goldAnimFrames;
    char coin_goldString[100];
    for (int i = 0; i <= 7; i++) {
        sprintf(coin_goldString, "coin_gold-%d.png", i);
        coin_goldAnimFrames.pushBack(coin_goldcahce->getSpriteFrameByName(coin_goldString));
    }
    Animation* _animation = Animation::createWithSpriteFrames(coin_goldAnimFrames, 1.f / 8);
    coin_goldSprite->runAction(RepeatForever::create(Animate::create(_animation)));
    //AnimationCache::destroyInstance();
    //SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
    */



    //hero->Dead();



    hero->createHealthBar();
    this->scheduleUpdate();
    auto keyListener = EventListenerKeyboard::create();

    keyListener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode, Event* event) {
        keyMap[keyCode] = true;
        switch (keyCode) {
            case EventKeyboard::KeyCode::KEY_SPACE:
            {
                //新建jump指针,指向JumpBy::create()返回一个Action的指针对象
                Action* jump = JumpBy::create(.5, Vec2(0, 0), 20, 1);
                //执行,让它跳一下
                hero->runAction(jump); break;
            }
        }

    };
    keyListener->onKeyReleased = [=](EventKeyboard::KeyCode keyCode, Event* event) {

        keyMap[keyCode] = false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyListener, this);

	return true;
}


void MyWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
    keyMap[keyCode] = true;
    switch (keyCode) {
        case EventKeyboard::KeyCode::KEY_SPACE:
        {
            //新建jump指针,指向JumpBy::create()返回一个Action的指针对象
            Action* jump = JumpBy::create(.5, Vec2(0, 0), 20, 1);
            //执行,让它跳一下
            hero->runAction(jump); break;
        }
    }
}

void MyWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
    keyMap[keyCode] = false;
}


void MyWorld::update(float dt)
{

    log("1");
    if (hero->getIsDead()) {
        return;
    }
    auto w = EventKeyboard::KeyCode::KEY_W;
    auto s = EventKeyboard::KeyCode::KEY_S;
    auto a = EventKeyboard::KeyCode::KEY_A;
    auto d = EventKeyboard::KeyCode::KEY_D;
    int offsetx = 0;
    int offsety = 0;
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
    if (offsetx == 0 && offsety == 0) {
        hero->isRun = false;
        hero->heroSetAction(hero->direction, 1);
        return;
    }
    
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
    hero->heroMoveTo(offsetx, offsety);
}