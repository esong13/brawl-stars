#pragma once
#ifndef _BOX_H_
#define _BOX_H_

#include "cocos2d.h"
#include "Item.h"
USING_NS_CC;


class Box :public Item {
	//创建和初始化
	CREATE_FUNC(Box);
	virtual bool init();

};

#endif