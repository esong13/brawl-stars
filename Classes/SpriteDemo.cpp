

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
    layer1->addChild(pBackground);
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

    //hero->attack(hero->getPosition() + Point(20, 20)+ hero->getRoleSprite()->getPosition());//测试

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
    if (heroIsDead) {
        return;
    }
    auto w = EventKeyboard::KeyCode::KEY_W;
    auto s = EventKeyboard::KeyCode::KEY_S;
    auto a = EventKeyboard::KeyCode::KEY_A;
    auto d = EventKeyboard::KeyCode::KEY_D;
    auto j = EventKeyboard::KeyCode::KEY_J;
    auto q = EventKeyboard::KeyCode::KEY_Q;
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
    if (keyMap[j])//攻击，attack里面本应填写鼠标点击的地图坐标，类型为Point
    {
        if (!hero->getAttackIsColding()) {
            scheduleOnce(CC_SCHEDULE_SELECTOR(MyWorld::attackCDUpdate), hero->getAttackCDTime());
        }
        hero->attack(hero->getPosition()+Point(offsetx, offsety)+hero->getRoleSprite()->getPosition());
        
    }
    if (keyMap[q])//主动死亡
    {
        hero->Dead();
        heroIsDead = true;
        return;
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