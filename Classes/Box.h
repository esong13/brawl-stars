#pragma once
#ifndef _BOX_H_
#define _BOX_H_

#include "cocos2d.h"
#include "Item.h"
USING_NS_CC;


class Box :public Item {
	//�����ͳ�ʼ��
	CREATE_FUNC(Box);
	virtual bool init();

};

#endif