#include "Alarm.h"

extern Alarm *alarm;

Alarm::Alarm()
{
	queue = new DLList;
	timer = new Timer(timerhandler, 0, false);
	waiters = 0;
}

Alarm::~Alarm()
{
	delete queue;
	delete timer;
}

void Alarm::Pause(int howLong)
{
	IntStatus oldLevel = interrupt->SetLevel(IntOff);	//必须关中断

	waiters++;
	queue->SortedInsert((void *)currentThread,
		stats->totalTicks + howLong);	//按结束时间依序插入链表

	//queue->Append((void *)currentThread);
	currentThread->Sleep();

	(void)interrupt->SetLevel(oldLevel);
}


void timerhandler(int dummy)		//dummy 仅为占位，不需要用到这个参数
{
	int duetime;
	Thread *thread=NULL;

	IntStatus oldLevel = interrupt->SetLevel(IntOff);	//必须关中断

	thread = (Thread *)alarm->queue->Remove(&duetime);
	while (thread!= NULL)
	{
		if (duetime - stats->totalTicks <= 0)
		{
			alarm->waiters--;
			scheduler->ReadyToRun(thread);
			printf("%s wake up!\n",thread->getName());
		}
		else
		{
			queue->SortedInsert((void *)thread,duetime);
			printf("%d Ticks remains\n%d threads remains\n\n",
				stats->totalTicks - duetime, alarm->waiters);
		}
	}

	(void)interrupt->SetLevel(oldLevel);
}
