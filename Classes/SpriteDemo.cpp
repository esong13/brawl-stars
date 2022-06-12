

#include "SpriteDemo.h"
#include "StartScene.h"



Scene* MyWorld::createScene(){
    auto scene = Scene::create();
    auto layer = MyWorld::create();
    scene->addChild(layer);
    return scene;
}

bool MyWorld::init()
{
	if (!Layer::init()) return false;


    //来自GameScene的合并
    //set the background music and it volume
    auto backgroundAudioID = AudioEngine::play2d("GameScene.mp3", true);
    AudioEngine::setVolume(backgroundAudioID, 0.3);

    //initialize the map
    auto map = TMXTiledMap::create("Map.tmx");

    //sync the window size with the map
    GLViewImpl* view = (GLViewImpl*)Director::getInstance()->getOpenGLView();
    view->setWindowed(map->getContentSize().width * 3, map->getContentSize().height * 3);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //add the map to the center of the window
    map->setAnchorPoint(Vec2(0.5, 0.5));
    map->setPosition(Vec2(
        origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2));
    this->addChild(map);

    //auto visibleSize = Director::getInstance()->getVisibleSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto* layer1 = Layer::create();
    auto* pBackground = Sprite::create("firstmap.png");
    pBackground->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    pBackground->setScale(0.8f);
    layer1->addChild(pBackground,-10);
    this->addChild(layer1,-1);
    
    //auto* layer2 = Layer::create();
    //rocker = HRocker::createHRocker("rocker.png", "rockerBG.png", Point(100, 100));
    //layer2->addChild(rocker);
    //rocker->startRocker(true);
    //this->addChild(layer2);
    //addChild(rocker);
    //rocker->startRocker(true);

    hero = SwordMan::create();
    hero->bindSprite(Sprite::create("SpirtOne/sword_man/sword_man1-1.png"));
    hero->setPosition(ROLENODE_POSITION_X, ROLENODE_POSITION_X);
    addChild(hero);
    hero->addBulletBar();
    hero->addHealthBar();
    hero->heroSetAction(hero->direction, 1);
    this->heroIsDead = false;
    //test

    //box
    /**/
    box1 = Box::create();
    box1->bindSprite(Sprite::create("box.png"));
    box1->setPosition(200, 200);
    box1->addHealthBar();
    box1->healthBar->setPosition(box1->healthBar->getPosition() - Point(3, 14));
    isBox1Dead = false;
    addChild(box1,-1);


    schedule(CC_SCHEDULE_SELECTOR(MyWorld::bulletBackUpdate), 2, 2000, 2.0f);

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
    


    this->scheduleUpdate();

    //键盘监听器
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

    //鼠标监听器
    listener = EventListenerTouchOneByOne::create();
    //绑定监听事件
    listener->onTouchBegan = CC_CALLBACK_2(MyWorld::onTouchBegan, this);
    //listener->onTouchMoved = CC_CALLBACK_2(MyWorld::onTouchMoved, this);
    //listener->onTouchEnded = CC_CALLBACK_2(MyWorld::onTouchEnded, this);
    listener->setSwallowTouches(true);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

//鼠标点击攻击
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


bool MyWorld::onTouchBegan(Touch* touch, Event* event)
{
    //得到触屏点坐标
    Point point = touch->getLocation();
    if (!hero->getAttackIsColding()) {
        scheduleOnce(CC_SCHEDULE_SELECTOR(MyWorld::attackCDUpdate), hero->getAttackCDTime());
    }
    hero->attack(point);
    return true;
}

void MyWorld::update(float dt)
{
    log("1");
    if (heroIsDead) {
        return;
    }
    auto w = EventKeyboard::KeyCode::KEY_W;
    auto s = EventKeyboard::KeyCode::KEY_S;
    auto a = EventKeyboard::KeyCode::KEY_A;
    auto d = EventKeyboard::KeyCode::KEY_D;
    auto j = EventKeyboard::KeyCode::KEY_J;
    auto q = EventKeyboard::KeyCode::KEY_Q;
    auto b = EventKeyboard::KeyCode::KEY_B;

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
    if (keyMap[q])//主动死亡
    {
        //通过能量多少判断掉落多少能量
        for (int i = 1; i <= (hero->getPower() - 1) / 2 + 1; ++i) {
            Sprite* powerFalled = Sprite::create("power.png");
            powerFalled->setPosition(hero->getPosition() + hero->getRoleSprite()->getPosition());
            this->addChild(powerFalled);
            powerInTheWorld.pushBack(powerFalled);
        }
        unschedule(CC_SCHEDULE_SELECTOR(MyWorld::bulletBackUpdate));
        hero->Dead();
        heroIsDead = true;
        this->unscheduleUpdate();
        return;
    }
    if (keyMap[b])//箱子死亡
    {
        if (isBox1Dead) {
            return;
        }
        for (int i = 1; i <= (box1->getPower() - 1) / 2 + 1; ++i) {
            Sprite* powerFalled = Sprite::create("power.png");
            powerFalled->setPosition(box1->getPosition() + box1->getRoleSprite()->getPosition());
            this->addChild(powerFalled);
            powerInTheWorld.pushBack(powerFalled);
        }
        box1->Dead();
        isBox1Dead = true;
        return;
    }
    if (offsetx == 0 && offsety == 0) {
        hero->isRun = false;
        hero->heroSetAction(hero->direction, 1);
        return;
    }

    //判断是否可能拾取buff
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

void MyWorld::bulletBackUpdate(float dt)
{
    hero->setBullet(hero->bulletBar, hero->getBulletNow() + 1);
}

void MyWorld::attackCDUpdate(float dt)
{
    hero->setAttackIsColding(false);
}