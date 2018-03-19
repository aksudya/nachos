// threadtest.cc 
//	Simple test case for the threads assignment.
//
//	Create two threads, and have them context switch
//	back and forth between themselves by calling Thread::Yield, 
//	to illustratethe inner workings of the thread system.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "dllist.h"

// testnum is set in main.cc
int testnum = 1;
int T=2;
int N=2;
DLList *list;

void InsertList(int N, DLList *list);
void RemoveList(int N, DLList *list);
//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//----------------------------------------------------------------------

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
	printf("*** thread %d looped %d times\n", which, num);
        currentThread->Yield();
    }
}

void
TestDllist(int which)
{
	//printf("*** thread %d ***\n",which);
	InsertList(N,list);
	//currentThread->Yield();
	//printf("*** thread %d ***\n",which);
	RemoveList(N,list);
	//printf("*** thread %d ***\n",which);
	if(list->IsEmpty())
	{
		printf("*** thread %d :empty ***\n",which);
	}
	else
	{
		printf("*** thread %d :not empty ***\n",which);
	}

}

//----------------------------------------------------------------------
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//----------------------------------------------------------------------

void
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1 ");

    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

void
ThreadTest2()
{
	DEBUG('t', "Entering ThreadTest2 ");
	list=new DLList();
	for (int var = 0; var < T; var++)
	{
		char No[4]="1";
		sprintf(No, "%d", var);
		//char name[18]="forked thread ";	//error
		char *name=new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
		name[0]='\0';
		strcat(name,"forked thread ");
		strcat(name,No);

		Thread *t = new Thread(name);
		t->Fork(TestDllist,var);
		//TestDllist(0);
	}

}

//----------------------------------------------------------------------
// ThreadTest
// 	Invoke a test routine.
//----------------------------------------------------------------------

void
ThreadTest()
{
    switch (testnum) {
    case 1:
	ThreadTest1();
	break;
    case 2:
    ThreadTest2();
    break;
    default:
	printf("No test specified.\n");
	break;
    }
}

