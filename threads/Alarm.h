#pragma once
#include "system.h"
#include "dllist.h"
//#include "../machine/timer.h"
void timerhandler(int dummy);
void check(int which);

class Alarm
{
public:
	Alarm();
	~Alarm();
	void Pause(int howLong);

	//对不起我放弃private,太tm麻烦了
	DLList * queue;
	Timer *timer;
	int waiters;
	
};
