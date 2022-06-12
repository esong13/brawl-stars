#include"My2scene.h"/*开始界面*/
#include"Myscene.h"
Scene* My2scene::createScene()
{
	auto scene = Scene::create();
	auto layer = My2scene::create();
	scene->addChild(layer);
	return scene;
}

bool My2scene::init() 
{
	if (!Layer::init())
	{
		return false;
	}
	Size My2size = Director::getInstance()->getVisibleSize();

	auto menuitem = MenuItemImage::create("start.png", "start.png",CC_CALLBACK_1(My2scene::EnterMyscene, this));
	menuitem->setPosition(My2size.width / 2, My2size.height / 2);
	auto menu = Menu::create(menuitem, NULL);
	menu->setScale(0.3);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
}
void My2scene::EnterMyscene(Ref* p) 
{
	Director::getInstance()->replaceScene(TransitionSlideInL::create(1, Myscene::createScene()));


}