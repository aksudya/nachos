#pragma once
#include "system.h"
#include "dllist.h"
//#include "../machine/timer.h"



class Alarm
{
public:
	Alarm();
	~Alarm();
	void Pause(int howLong);
	void timerhandler(int dummy);

private:
	DLList * queue;
	Timer *timer;
	int waiters;
};
