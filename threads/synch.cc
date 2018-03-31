// synch.cc 
//	Routines for synchronizing threads.  Three kinds of
//	synchronization routines are defined here: semaphores, locks 
//   	and condition variables (the implementation of the last two
//	are left to the reader).
//
// Any implementation of a synchronization routine needs some
// primitive atomic operation.  We assume Nachos is running on
// a uniprocessor, and thus atomicity can be provided by
// turning off interrupts.  While interrupts are disabled, no
// context switch can occur, and thus the current thread is guaranteed
// to hold the CPU throughout, until interrupts are reenabled.
//
// Because some of these routines might be called with interrupts
// already disabled (Semaphore::V for one), instead of turning
// on interrupts at the end of the atomic operation, we always simply
// re-set the interrupt state back to its original value (whether
// that be disabled or enabled).
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "synch.h"
#include "system.h"

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	Initialize a semaphore, so that it can be used for synchronization.
//
//	"debugName" is an arbitrary name, useful for debugging.
//	"initialValue" is the initial value of the semaphore.
//----------------------------------------------------------------------

Semaphore::Semaphore(char* debugName, int initialValue)
{
    name = debugName;
    value = initialValue;
    queue = new List;
}

//----------------------------------------------------------------------
// Semaphore::Semaphore
// 	De-allocate semaphore, when no longer needed.  Assume no one
//	is still waiting on the semaphore!
//----------------------------------------------------------------------

Semaphore::~Semaphore()
{
    delete queue;
}

//----------------------------------------------------------------------
// Semaphore::P
// 	Wait until semaphore value > 0, then decrement.  Checking the
//	value and decrementing must be done atomically, so we
//	need to disable interrupts before checking the value.
//
//	Note that Thread::Sleep assumes that interrupts are disabled
//	when it is called.
//----------------------------------------------------------------------

void
Semaphore::P()
{
    IntStatus oldLevel = interrupt->SetLevel(IntOff);	// disable interrupts
    
    while (value == 0) { 			// semaphore not available
	//queue->Append((void *)currentThread);	// so go to sleep
	queue->SortedInsert((void *)currentThread, currentThread->getpriority());	// so go to sleep
	currentThread->Sleep();
    } 
    value--; 					// semaphore available, 
						// consume its value
    
    (void) interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

//----------------------------------------------------------------------
// Semaphore::V
// 	Increment semaphore value, waking up a waiter if necessary.
//	As with P(), this operation must be atomic, so we need to disable
//	interrupts.  Scheduler::ReadyToRun() assumes that threads
//	are disabled when it is called.
//----------------------------------------------------------------------

void
Semaphore::V()
{
    Thread *thread;
    IntStatus oldLevel = interrupt->SetLevel(IntOff);

    thread = (Thread *)queue->Remove();
    if (thread != NULL)	   // make thread ready, consuming the V immediately
	scheduler->ReadyToRun(thread);
    value++;
    (void) interrupt->SetLevel(oldLevel);
}


#ifdef SEM_VERSION
// Dummy functions -- so we can compile our later assignments 
// Note -- without a correct implementation of Condition::Wait(), 
// the test case in the network assignment won't work!
Lock::Lock(char* debugName)
{
	name = debugName;
	LockHoder = NULL;
	sem = new Semaphore("LockSemaphore",1);
	inte = new Semaphore("InterruptSemaphore", 1);
}

Lock::~Lock()
{
	delete (LockHoder);
	delete (sem);
	delete (inte);
}

void Lock::Acquire()
{
	//inte->P();		// 用来替代关中断  	

	ASSERT(!isHeldByCurrentThread());

	sem->P();

	LockHoder = currentThread;


	//inte->V();		// 用来替代开中断
}

void Lock::Release()
{

	inte->P();

	ASSERT(isHeldByCurrentThread());
	
	LockHoder = NULL;
	//currentThread->Yield();
	sem->V();
	

	inte->V();


	
}

bool Lock::isHeldByCurrentThread()
{
	return currentThread == LockHoder;
}

Condition::Condition(char* debugName)
{
	name = debugName;
	sem = new Semaphore("LockSemaphore", 1);
	inte = new Semaphore("InterruptSemaphore", 1);
	blockNum = 0;
}

Condition::~Condition()
{
	delete (inte);
	delete (sem);
}
void Condition::Wait(Lock* conditionLock)
{
	
	//inte->P();

	ASSERT(conditionLock->isHeldByCurrentThread());
	conditionLock->Release();
	blockNum++;
	//currentThread->Yield();
	sem->P();
	conditionLock->Acquire();

	//inte->V();
}

void Condition::Signal(Lock* conditionLock)
{
	//inte->P();

	ASSERT(conditionLock->isHeldByCurrentThread());

	if(blockNum>0)		//防止wait之前调用signal导致的累积
	{
		blockNum--;
		sem->V();
	}

	//inte->V();
}

void Condition::Broadcast(Lock* conditionLock)
{
	//inte->P();
	ASSERT(conditionLock->isHeldByCurrentThread());

	while (blockNum>0)
	{
		blockNum--;
		sem->V();
	}

	//inte->V();
}
#endif

#ifdef SLEEP_VERSION
Lock::Lock(char* debugName)
{
	name = debugName;
	LockHoder = NULL;
	LockQune = new List;
	//IsBusy = false;
}

Lock::~Lock()
{
	delete (LockHoder);
	delete (LockQune);
}

void Lock::Acquire()
{
	IntStatus oldLevel = interrupt->SetLevel(IntOff);	


	ASSERT(!isHeldByCurrentThread());

	while (LockHoder!=NULL)
	{
		queue->SortedInsert((void *)currentThread, currentThread->getpriority());	// so go to sleep
		currentThread->Sleep();
	}
	LockHoder = currentThread;


	(void)interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

void Lock::Release()
{
	Thread *thread;

	IntStatus oldLevel = interrupt->SetLevel(IntOff);

	ASSERT(isHeldByCurrentThread());

	thread = (Thread *)LockQune->Remove();
	if (thread != NULL)
		scheduler->ReadyToRun(thread);
	LockHoder = NULL;

	(void)interrupt->SetLevel(oldLevel);


}

bool Lock::isHeldByCurrentThread()
{
	return currentThread == LockHoder;
}

Condition::Condition(char* debugName)
{
	name = debugName;
	ConditionQueue = new List;
}

Condition::~Condition()
{
	delete (ConditionQueue);
}
void Condition::Wait(Lock* conditionLock)
{
	IntStatus oldLevel = interrupt->SetLevel(IntOff);

	//ASSERT(FALSE);

	conditionLock->Release();
	queue->SortedInsert((void *)currentThread, currentThread->getpriority());	// so go to sleep
	currentThread->Sleep();

	conditionLock->Acquire();

	(void)interrupt->SetLevel(oldLevel);	// re-enable interrupts
}

void Condition::Signal(Lock* conditionLock)
{

	Thread *thread;
	IntStatus oldLevel = interrupt->SetLevel(IntOff);
	ASSERT(conditionLock->isHeldByCurrentThread());

	thread = (Thread *)ConditionQueue->Remove();
	if (thread != NULL)
		scheduler->ReadyToRun(thread);
	//LockHoder = NULL;

	(void)interrupt->SetLevel(oldLevel);
}

void Condition::Broadcast(Lock* conditionLock)
{
	Thread *thread;
	IntStatus oldLevel = interrupt->SetLevel(IntOff);
	ASSERT(conditionLock->isHeldByCurrentThread());

	while (!ConditionQueue->IsEmpty())
	{
		thread = (Thread *)ConditionQueue->Remove();
		if (thread != NULL)
			scheduler->ReadyToRun(thread);
	}

	(void)interrupt->SetLevel(oldLevel);
}
#endif
