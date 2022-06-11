#include "SettingsScene.h"

Scene* Settings::createScene()
{
    return Settings::create();
}

bool Settings::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backLabel = Label::createWithTTF("<Back", "fonts/arial.ttf", 20); 
    auto backItem = MenuItemLabel::create(backLabel, CC_CALLBACK_1(Settings::menuBackCallback, this));
    backItem->setPosition(Vec2(
        origin.x + backItem->getContentSize().width / 2,
        origin.y - backItem->getContentSize().height / 2 + visibleSize.height));
    auto menuBack = Menu::create(backItem, NULL);
    menuBack->setPosition(Vec2::ZERO);
    this->addChild(menuBack);

    auto creditsTitle = Sprite::create("Credits.png");
    creditsTitle->setAnchorPoint(Vec2(0.5, 1));
    creditsTitle->setPosition(Vec2(
        origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - backItem->getContentSize().height));
    this->addChild(creditsTitle);

    // Create the scrollview by vertical
    ScrollView* scrollView = ScrollView::create(); 
    scrollView->setContentSize(Size(
        visibleSize.width,
        visibleSize.height - backItem->getContentSize().height - creditsTitle->getContentSize().height));
    scrollView->setInnerContainerSize(Size(
        visibleSize.width,
        visibleSize.height));
    scrollView->setAnchorPoint(Vec2(0.5, 1));
    scrollView->setPosition(Vec2(
        origin.x + visibleSize.width / 2,
        origin.y + visibleSize.height - backItem->getContentSize().height - creditsTitle->getContentSize().height));
    scrollView->setBounceEnabled(true);
    scrollView->setScrollBarWidth(4);
    scrollView->setScrollBarColor(Color3B::WHITE);
   
    auto creditsContent = Sprite::create("CreditsContent.png");
    creditsContent->setScale(0.3f, 0.3f);
    creditsContent->setAnchorPoint(Vec2(0.5, 1));
    creditsContent->setPosition(Vec2(scrollView->getInnerContainerSize().width / 2, scrollView->getInnerContainerSize().height));
    scrollView->addChild(creditsContent);

    this->addChild(scrollView);

    return true;
}

void Settings::menuBackCallback(Ref* pSender)
{
    Director::getInstance()->popScene();
}