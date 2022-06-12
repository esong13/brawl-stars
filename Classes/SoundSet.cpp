#include"SoundSet.h"/*�������ý���*/
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

	/*������*/
	Slider* slider = Slider::create();
	slider->loadBarTexture("sliderTrack.png");//��������������
	slider->loadSlidBallTextures("sliderThumb.png", "sliderThumb.png");//������ť������һ��Ϊ�������ڶ���Ϊ�����ʱ
	slider->loadProgressBarTexture("sliderProgress.png");//��������
	slider->setPosition(Vec2(Mysize.width / 2, 100));
	slider->setScale(1.5f);
	slider->setPercent(100);
		slider->addEventListener([&](Ref* sender, Slider::EventType type)
			{
				auto s = dynamic_cast<Slider*>(sender);
				auto volum = 1.0f * s->getPercent() / s->getMaxPercent();//����������ֵ��������ֵӦΪ��0~1֮��
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