#include"SoundSet.h"/*ÉùÒôÉèÖÃ½çÃæ*/
#include"Myscene.h"
Scene* SoundSet::createScene()
{
	auto scene = Scene::create();
	auto layer = SoundSet::create();
	scene->addChild(layer);
	return scene;
}

bool SoundSet::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size Mysize = Director::getInstance()->getVisibleSize();

	auto menuitem = MenuItemImage::create("SoundSet.png", "SoundSet.png", CC_CALLBACK_1(SoundSet::EnterMyscene, this));
	menuitem->setPosition(Vec2(Mysize.width / 2, Mysize.height / 2));
	auto SoundSet = Menu::create(menuitem, NULL);
	SoundSet->setScale(0.5);
	SoundSet->setPosition(Vec2::ZERO);
	this->addChild(SoundSet);
}

void SoundSet::EnterMyscene(Ref* p)
{
	Director::getInstance()->popScene();
}