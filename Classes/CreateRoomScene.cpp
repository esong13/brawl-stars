#include "CreateRoomScene.h"

Scene* CreateRoom::createScene()
{
    return CreateRoom::create();
}

bool CreateRoom::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto coltItem = MenuItemImage::create(
        "Colt.PNG",
        "Colt.PNG",
        CC_CALLBACK_1(CreateRoom::menuColtCallback, this));
    coltItem->setAnchorPoint(Vec2(0.5, 0.5));
    coltItem->setPosition(Vec2(origin.x + visibleSize.width * 0.15, origin.y + visibleSize.height * 0.8));
    auto menuColt = Menu::create(coltItem, NULL);
    menuColt->setPosition(Vec2::ZERO);
    this->addChild(menuColt);

    auto nitaItem = MenuItemImage::create(
        "Nita.png",
        "Nita.png",
        CC_CALLBACK_1(CreateRoom::menuNitaCallback, this));
    nitaItem->setAnchorPoint(Vec2(0.5, 0.5));
    nitaItem->setPosition(Vec2(origin.x + visibleSize.width * 0.15, origin.y + visibleSize.height * 0.6));
    auto menuNita = Menu::create(nitaItem, NULL);
    menuNita->setPosition(Vec2::ZERO);
    this->addChild(menuNita);

    auto rosaItem = MenuItemImage::create(
        "Rosa.png",
        "Rosa.png",
        CC_CALLBACK_1(CreateRoom::menuRosaCallback, this));
    rosaItem->setAnchorPoint(Vec2(0.5, 0.5));
    rosaItem->setPosition(Vec2(origin.x + visibleSize.width * 0.15, origin.y + visibleSize.height * 0.4));
    auto menuRosa = Menu::create(rosaItem, NULL);
    menuRosa->setPosition(Vec2::ZERO);
    this->addChild(menuRosa);

    auto shellyItem = MenuItemImage::create(
        "Shelly.png",
        "Shelly.png",
        CC_CALLBACK_1(CreateRoom::menuShellyCallback, this));
    shellyItem->setAnchorPoint(Vec2(0.5, 0.5));
    shellyItem->setPosition(Vec2(origin.x + visibleSize.width * 0.15, origin.y + visibleSize.height * 0.2));
    auto menuShelly = Menu::create(shellyItem, NULL);
    menuShelly->setPosition(Vec2::ZERO);
    this->addChild(menuShelly);

    auto playerLabel = Label::createWithTTF("Player", "fonts/arial.ttf", 16);
    playerLabel->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.85));
    this->addChild(playerLabel);

    auto ai_1Label = Label::createWithTTF("AI#1", "fonts/arial.ttf", 16);
    ai_1Label->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.85));
    this->addChild(ai_1Label);

    auto ai_2Label = Label::createWithTTF("AI#2", "fonts/arial.ttf", 16);
    ai_2Label->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.45));
    this->addChild(ai_2Label);

    auto ai_3Label = Label::createWithTTF("AI#3", "fonts/arial.ttf", 16);
    ai_3Label->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.45));
    this->addChild(ai_3Label);

    auto playLabel = Label::createWithTTF("PLAY", "fonts/Marker Felt.ttf", 20);
    auto playItem = MenuItemLabel::create(playLabel, CC_CALLBACK_1(CreateRoom::menuPlayCallback, this));
    playItem->setPosition(Vec2(origin.x + visibleSize.width * 0.85, origin.y + visibleSize.height * 0.5));
    auto menuPlay = Menu::create(playItem, NULL);
    menuPlay->setPosition(Vec2::ZERO);
    this->addChild(menuPlay);

    return true;
}

void CreateRoom::menuColtCallback(Ref* pSender)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    switch (_chosenPlayer.size())
    {
    case 0:
    {
        _chosenPlayer.push_back(Colt);
        auto colt = Sprite::create("Colt.PNG");
        colt->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.65));
        this->addChild(colt);
        break;
    }
    case 1:
    {
        _chosenPlayer.push_back(Colt);
        auto colt = Sprite::create("Colt.PNG");
        colt->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.65));
        this->addChild(colt);
        break;
    }
    case 2:
    {
        _chosenPlayer.push_back(Colt);
        auto colt = Sprite::create("Colt.PNG");
        colt->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.25));
        this->addChild(colt);
        break;
    }
    case 3:
    {
        _chosenPlayer.push_back(Colt);
        auto colt = Sprite::create("Colt.PNG");
        colt->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.25));
        this->addChild(colt);
        break;
    }
    default:
        break;
    }
}

void CreateRoom::menuNitaCallback(Ref* pSender)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    switch (_chosenPlayer.size())
    {
    case 0:
    {
        _chosenPlayer.push_back(Nita);
        auto nita = Sprite::create("Nita.png");
        nita->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.65));
        this->addChild(nita);
        break;
    }
    case 1:
    {
        _chosenPlayer.push_back(Nita);
        auto nita = Sprite::create("Nita.png");
        nita->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.65));
        this->addChild(nita);
        break;
    }
    case 2:
    {
        _chosenPlayer.push_back(Nita);
        auto nita = Sprite::create("Nita.png");
        nita->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.25));
        this->addChild(nita);
        break;
    }
    case 3:
    {
        _chosenPlayer.push_back(Nita);
        auto nita = Sprite::create("Nita.png");
        nita->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.25));
        this->addChild(nita);
        break;
    }
    default:
        break;
    }
}

void CreateRoom::menuRosaCallback(Ref* pSender)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    switch (_chosenPlayer.size())
    {
    case 0:
    {
        _chosenPlayer.push_back(Rosa);
        auto rosa = Sprite::create("Rosa.png");
        rosa->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.65));
        this->addChild(rosa);
        break;
    }
    case 1:
    {
        _chosenPlayer.push_back(Rosa);
        auto rosa = Sprite::create("Rosa.png");
        rosa->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.65));
        this->addChild(rosa);
        break;
    }
    case 2:
    {
        _chosenPlayer.push_back(Rosa);
        auto rosa = Sprite::create("Rosa.png");
        rosa->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.25));
        this->addChild(rosa);
        break;
    }
    case 3:
    {
        _chosenPlayer.push_back(Rosa);
        auto rosa = Sprite::create("Rosa.png");
        rosa->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.25));
        this->addChild(rosa);
        break;
    }
    default:
        break;
    }
}

void CreateRoom::menuShellyCallback(Ref* pSender)
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    switch (_chosenPlayer.size())
    {
    case 0:
    {
        _chosenPlayer.push_back(Shelly);
        auto shelly = Sprite::create("Shelly.png");
        shelly->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.65));
        this->addChild(shelly);
        break;
    }
    case 1:
    {
        _chosenPlayer.push_back(Shelly);
        auto shelly = Sprite::create("Shelly.png");
        shelly->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.65));
        this->addChild(shelly);
        break;
    }
    case 2:
    {
        _chosenPlayer.push_back(Shelly);
        auto shelly = Sprite::create("Shelly.png");
        shelly->setPosition(Vec2(origin.x + visibleSize.width * 0.4, origin.y + visibleSize.height * 0.25));
        this->addChild(shelly);
        break;
    }
    case 3:
    {
        _chosenPlayer.push_back(Shelly);
        auto shelly = Sprite::create("Shelly.png");
        shelly->setPosition(Vec2(origin.x + visibleSize.width * 0.6, origin.y + visibleSize.height * 0.25));
        this->addChild(shelly);
        break;
    }
    default:
        break;
    }
}

void CreateRoom::menuPlayCallback(Ref* pSender)
{
    if (_chosenPlayer.size() == 4)
    {
        AudioEngine::stopAll();
        Director::getInstance()->replaceScene(Game::createScene(_chosenPlayer));
    }
}