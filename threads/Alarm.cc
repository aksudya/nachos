#include "Alarm.h"

Alarm::Alarm()
{
	queue = new DLList;
	timer = new Timer(this->timerhandler, 0, false);
	waiters = 0;
}

Alarm::~Alarm()
{
	delete queue;
	delete timer;
}

void Alarm::Pause(int howLong)
{
	waiters++;
	queue->SortedInsert((void *)currentThread,
		stats->totalTicks + howLong);	//按结束时间依序插入链表

	//queue->Append((void *)currentThread);
	currentThread->Sleep();
}



void Alarm::timerhandler(int dummy)		//dummy 仅为占位，不需要用到这个参数
{
	int duetime;
	Thread *thread;
	thread = (Thread *)queue->Remove(&duetime);
	while (thread!= NULL)
	{
		if (stats->totalTicks - duetime <= 0)
		{
			waiters--;
			scheduler->ReadyToRun(thread);
			printf("%s wake up!\n",thread->getName());
		}
		else
		{
			printf("%d Ticks remains\n%d threads remains\n\n",
				stats->totalTicks - duetime,waiters);
		}
	}
	
}
