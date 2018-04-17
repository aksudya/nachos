#include "EventBarrier.h"

EventBarrier::EventBarrier()
{
	waiternum = 0;
	lock = new Lock("EventBarrier Lock");
	event = new Condition("Event come cond");
	comp = new Condition("Event complete cond");
	signaled = false;
}

EventBarrier::~EventBarrier()
{
	delete lock;
	delete event;
	delete comp;
}

void EventBarrier::Signal()
{
	lock->Acquire();
	signaled = true;
	if(waiternum!=0)
	{
		comp->Wait(lock);		
	}
	event->Broadcast(lock);	
	signaled = false;
	//this->Wait();
	//comp->Wait(lock);	
	lock->Release();
}

void EventBarrier::Wait()
{
	lock->Acquire();
	if(signaled)
	{
		lock->Release();
		return;
	}
	waiternum++;
	event->Wait(lock);	
	lock->Release();
}

void EventBarrier::Complete()
{
	lock->Acquire();
	waiternum--;
	if(waiternum==0)
	{
		comp->Broadcast(lock);
	}
	else
	{
		comp->Wait(lock);
	}
	lock->Release();
}

int EventBarrier::Waiters()
{
	return waiternum;
}
