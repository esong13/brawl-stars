#include "GameScene.h"

Scene* Game::createScene()
{
    return Game::create();
}

bool Game::init()
{
    if (!Scene::init())
    {
        return false;
    }

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

    return true;
}