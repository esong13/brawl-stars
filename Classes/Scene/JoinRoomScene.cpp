#include "JoinRoomScene.h"

Scene* JoinRoom::createScene()
{
    return JoinRoom::create();
}

bool JoinRoom::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backLabel = Label::createWithTTF("<Back", "fonts/arial.ttf", 20);
    auto backItem = MenuItemLabel::create(backLabel, CC_CALLBACK_1(JoinRoom::menuBackCallback, this));
    backItem->setPosition(Vec2(
        origin.x + backItem->getContentSize().width / 2,
        origin.y - backItem->getContentSize().height / 2 + visibleSize.height));
    auto menuBack = Menu::create(backItem, NULL);
    menuBack->setPosition(Vec2::ZERO);
    this->addChild(menuBack);

    auto joinRoomInfoLabel = Label::createWithTTF(JoinRoomInfo, "fonts/Marker Felt.ttf", 16);
    joinRoomInfoLabel->setPosition(Vec2(
        origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height / 2));
    this->addChild(joinRoomInfoLabel);

    return true;
}

void JoinRoom::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}