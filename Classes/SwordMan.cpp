#include "SwordMan.h"

bool SwordMan::init()
{
	if (!HeroSprite::init()) return false;
	setAttackNum(600);

	return true;
}

void SwordMan::heroSetAction(int direction, int num)
{
	setAction(direction, "sword_man", num);
}

void SwordMan::attack(Point targetPosition)
{
	
}

