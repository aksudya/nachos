#pragma once
#include "synch.h"
#include "system.h"

class EventBarrier
{
public:
	EventBarrier();
	~EventBarrier();

	void Wait();	// Wait until the event is signaled. 
					// Return immediately if already in the signaled state.
	
	void Signal();	// Signal the event and block until all threads 
					// that wait for this event have responded.
					// The EventBarrier reverts to the unsignaled state when Signal() returns.
	
	void Complete();// indicate that the calling thread 
					// has finished responding to a signaled event, and block
					// until all other threads that wait for this event have also responded.
	
	int	Waiters();	// Return a count of threads that are waiting 
					// for the event or that have not yet responded to it.
private:
	int waiternum;
	Lock *lock;
	Condition *event, *comp;	//two conditions
	bool signaled;
};