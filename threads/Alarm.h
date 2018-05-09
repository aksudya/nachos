#pragma once
#include "system.h"
#include "dllist.h"
//#include "../machine/timer.h"
//void timerhandler(int dummy);
void check(int which);

class Alarm
{
public:			
	Alarm();
	~Alarm();
	void Pause(int howLong);
	DLList * queue;
	//Timer *timer;
	int waiters;
	void CheckIfDue(int dummy);	//dummy仅为占位
	
	static void new_instance();
	static Alarm *instance;
};
