#include "Box.h"

bool Box::init()
{
	if (!Item::init()) return false;

	setHealthPointMax (5000);
	setHealthPointNow (5000);
	return true;
}
