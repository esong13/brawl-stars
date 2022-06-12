#include"SoundSet.h"/*声音设置界面*/
Scene* SoundSet::createScene(int audioID)
{
	auto scene = Scene::create();
	auto layer = SoundSet::create();
	scene->addChild(layer);
	_audioID = audioID;
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

	/*音量条*/
	Slider* slider = Slider::create();
	slider->loadBarTexture("sliderTrack.png");//滑动条背景纹理
	slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png");//滑动按钮纹理，第一个为正常，第二个为被点击时
	slider->loadProgressBarTexture("sliderProgress.png");//进度纹理
	slider->setPosition(Vec2(Mysize.width / 2, 100));
	slider->setScale(1.5f);
	slider->setPercent(100);
		slider->addEventListener([&](Ref* sender, Slider::EventType type)
			{
				auto s = dynamic_cast<Slider*>(sender);
				auto volum = 1.0f * s->getPercent() / s->getMaxPercent();//计算音量的值，音量的值应为：0~1之间
				if (_audioID != AudioEngine::INVALID_AUDIO_ID) {
					AudioEngine::setVolume(_audioID, volum);
				}
			});
	addChild(slider);
	
}

void SoundSet::EnterMyscene(Ref* p)
{
	Director::getInstance()->popScene();
}