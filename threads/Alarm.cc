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

void Alarm::Pause(int howLong)	//howlong单位为中断次数
{
	IntStatus oldLevel = interrupt->SetLevel(IntOff);	//必须关中断
	int Ticks = TimerTicks * howLong;
	waiters++;
	Thread *loop_t;
	if(waiters==1)
	{
		loop_t = new Thread("loop thread");
		loop_t->Fork(check, 0);			//使至少有一个线程在运行，防止系统终止
	}
	queue->SortedInsert((void *)currentThread,
		stats->totalTicks + Ticks);	//按结束时间依序插入链表

	currentThread->Sleep();

	(void)interrupt->SetLevel(oldLevel);
}

void check(int which)
{
	while (alarm->waiters!=0)
	{
		currentThread->Yield();
	}
	currentThread->Finish();
}


void timerhandler(int dummy)		//dummy 仅为占位，不需要用到这个参数
{
	int duetime;
	Thread *thread=NULL;

	IntStatus oldLevel = interrupt->SetLevel(IntOff);	//必须关中断

	thread = (Thread *)alarm->queue->Remove(&duetime);
	if (thread!= NULL)
	{
		if (duetime - stats->totalTicks <= 0)
		{
			alarm->waiters--;
			scheduler->ReadyToRun(thread);
			printf("%s wake up!\n",thread->getName());
		}
		else
		{
			alarm->queue->SortedInsert((void *)thread,duetime);
			//printf("%d Ticks remains\n%d threads remains\n\n",
				duetime-stats->totalTicks, alarm->waiters);
		}
	}

	(void)interrupt->SetLevel(oldLevel);
}
