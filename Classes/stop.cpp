#include"stop.h"
Scene* Stop::createScene()
{
	auto scene = Scene::create();
	auto layer = Stop::create();
	scene->addChild(layer);
	return scene;
}

bool Stop::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size Mysize = Director::getInstance()->getVisibleSize();

	auto menuitem = MenuItemImage::create("Play.png", "Play.png", CC_CALLBACK_1(Stop::EnterMyscene, this));
	menuitem->setPosition(Vec2(Mysize.width / 2, Mysize.height / 2));
	auto Stop = Menu::create(menuitem, NULL);
	Stop->setScale(0.5);
	Stop->setPosition(Vec2::ZERO);
	this->addChild(Stop);
}

void Stop::EnterMyscene(Ref* p)
{
	Director::getInstance()->popScene();
}