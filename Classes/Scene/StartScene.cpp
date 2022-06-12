#include "StartScene.h"

Scene* Start::createScene()
{
    return Start::create();
}

bool Start::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto background = Sprite::create("Background.png");

    //set the window size 2x the original background picture
    GLViewImpl* view = (GLViewImpl*)Director::getInstance()->getOpenGLView();
    view->setWindowed(background->getContentSize().width * 3, background->getContentSize().height * 3);

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // position the background on the center of the window and let it fit the full window
    background->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    background->setScale(1.15f);
    // add the background as a child to this layer
    this->addChild(background, 0);

    auto createRoomItem = MenuItemImage::create(
        "CreateRoom.png",
        "CreateRoom.png",
        CC_CALLBACK_1(Start::menuCreateRoomCallback, this));
    //position the createRoomItem on the right upper side of the window
    createRoomItem->setAnchorPoint(Vec2(1, 0.5));
    createRoomItem->setPosition(Vec2(origin.x + visibleSize.width * 0.9, origin.y + visibleSize.height * 0.7));
    auto menuCreateRoom = Menu::create(createRoomItem, NULL);
    menuCreateRoom->setPosition(Vec2::ZERO);
    this->addChild(menuCreateRoom, 1);

    auto joinRoomItem = MenuItemImage::create(
        "JoinRoom.png",
        "JoinRoom.png",
        CC_CALLBACK_1(Start::menuJoinRoomCallback, this));
    //position the joinRoomItem on the right side of the window
    joinRoomItem->setAnchorPoint(Vec2(1, 0.5));
    joinRoomItem->setPosition(Vec2(origin.x + visibleSize.width * 0.9, origin.y + visibleSize.height * 0.5));
    auto menuJoinRoom = Menu::create(joinRoomItem, NULL);
    menuJoinRoom->setPosition(Vec2::ZERO);
    this->addChild(menuJoinRoom, 1);

    auto settingsItem = MenuItemImage::create(
        "Settings.png",
        "Settings.png",
        CC_CALLBACK_1(Start::menuSettingsCallback, this));
    //position the settingsItem on the right lower side of the window
    settingsItem->setAnchorPoint(Vec2(1, 0.5));
    settingsItem->setPosition(Vec2(origin.x + visibleSize.width * 0.9, origin.y + visibleSize.height * 0.3));
    auto menuSettings = Menu::create(settingsItem, NULL);
    menuSettings->setPosition(Vec2::ZERO);
    this->addChild(menuSettings, 1);

    auto backgroundAudioID = AudioEngine::play2d("StartScene.mp3", true);

    return true;
}

void Start::menuCreateRoomCallback(Ref* pSender)
{
    Director::getInstance()->replaceScene(CreateRoom::createScene());
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void Start::menuJoinRoomCallback(Ref* pSender)
{
    Director::getInstance()->pushScene(JoinRoom::createScene());

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

void Start::menuSettingsCallback(Ref* pSender)
{
    Director::getInstance()->pushScene(Settings::createScene());

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}