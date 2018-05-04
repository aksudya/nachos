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
#include "Table.h"
#include "BoundedBuffer.h"
#include "EventBarrier.h"
#include "Alarm.h"
#include "Bridge.h"

#define TABLESIZE 100000
#define BOUNDEDBUFFERSIZE 1000
// testnum is set in main.cc
int testnum = 1;
int T=2;
int N=2;

int producersnum=2;
int consumersnum=2;

DLList *list;
Table *table;
BoundedBuffer *boundedbuffer;
EventBarrier *barrier;
//Alarm *alarm;
//Bridge *bridge;

void InsertList(int N, DLList *list);
void RemoveList(int N, DLList *list);

//----------------------------------------------------------------------
// ThreadTest1 -q
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
//
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
ThreadTest1()
{
    DEBUG('t', "Entering ThreadTest1 ");

    Thread *t = new Thread("forked thread");

    t->Fork(SimpleThread, 1);
    SimpleThread(0);
}

//----------------------------------------------------------------------
// ThreadTest2 -m
//  test Dllist with producer-consumer
//----------------------------------------------------------------------

void
TestDllist_producer(int which)
{

	while (true)
	{
		 void *item;
		 int key=Random()%10;
		 //int key=i;
		 int *items=new int[1];
		 items[0]=-key;
		 item=items;
		 printf("%s in:%d %d\n",currentThread->getName(),key,*(int*)item);
		 //currentThread->Yield();
		 list->SortedInsert(item,key);
		 //currentThread->Yield();
	}

}

void
TestDllist_consumer(int which)
{
	while (true)
	{
		 int key;
		 void *item;
		 item=list->Remove(&key);
		 printf("%s out:%d %d\n",currentThread->getName(),key,*(int*)item);
	}
}

void
ThreadTest2()
{
	DEBUG('t', "Entering ThreadTest2 ");
	list=new DLList();
	for (int var = 0; var < producersnum; var++)
		{
			char No[4]="1";
			sprintf(No, "%d", var);
			//char name[18]="forked thread ";	//error
			char *name=new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址 
			name[0]='\0';
			strcat(name,"producer thread ");
			strcat(name,No);

			Thread *t = new Thread(name);
			t->Fork(TestDllist_producer,var);
		}
		for (int var = 0; var < consumersnum; var++)
		{
			char No[4] = "1";
			sprintf(No, "%d", var);
			//char name[18]="forked thread ";	//error
			char *name = new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
			name[0] = '\0';
			strcat(name, "consumer thread ");
			strcat(name, No);

			Thread *t = new Thread(name);
			t->Fork(TestDllist_consumer, var);
		}
}

//----------------------------------------------------------------------
// ThreadTest3 -a
//  test Table with producer-consumer
//----------------------------------------------------------------------

void
TestTable_producer(int which)
{

	while (true)
	{
		void *item;
		int key = Random() % 100;		
		int *items = new int[1];
		items[0] = key;
		item = items;		
		printf("%s in:%d %d\n", currentThread->getName(), table->Alloc(item), *(int*)item);
		//currentThread->Yield();
	}

}

void
TestTable_consumer(int which)
{
	while (true)
	{
		void *item;
		int index;
		for (int i = 0; i < TABLESIZE; ++i)
		{
			item = table->Get(i);
			if(item != NULL)
			{
				index = i;
				break;
			}
		}		
		table->Release(index);
		printf("%s out:%d %d\n", currentThread->getName(), index, *(int*)item);
		//currentThread->Yield();
	}
}

void
ThreadTest3()
{
	DEBUG('t', "Entering ThreadTest3 ");
	//list=new DLList();
	table = new Table(TABLESIZE);
	for (int var = 0; var < producersnum; var++)
	{
		char No[4]="1";
		sprintf(No, "%d", var);
		//char name[18]="forked thread ";	//error
		char *name=new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
		name[0]='\0';
		strcat(name,"producer thread ");
		strcat(name,No);

		Thread *t = new Thread(name);
		t->Fork(TestTable_producer,var);
	}
	for (int var = 0; var < consumersnum; var++)
	{
		char No[4] = "1";
		sprintf(No, "%d", var);
		//char name[18]="forked thread ";	//error
		char *name = new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
		name[0] = '\0';
		strcat(name, "consumer thread ");
		strcat(name, No);

		Thread *t = new Thread(name);
		t->Fork(TestTable_consumer, var);
	}
}

//----------------------------------------------------------------------
// ThreadTest4 -b
//  test BoundedBuffer with producer-consumer
//----------------------------------------------------------------------

void
TestBuffer_producer(int which)
{

	while (true)
	{
		int size = Random() % 20+1;
		//int key=i;
		char *items = new char[size+1];
		for (int i = 0; i < size; ++i)
		{
			items[i] = 65 + i;
		}
		items[size] = '\0';
		boundedbuffer->Write(items, size);
		printf("%s in:%s\n size:%d usedsize:%d\n", currentThread->getName(), items,size,boundedbuffer->UsedSize );
		//currentThread->Yield();

		//currentThread->Yield();
	}

}

void
TestBuffer_consumer(int which)
{
	while (true)
	{
		int size= Random() % 10+1;
		char *item= new char[size + 1];
		boundedbuffer->Read(item, size);
		item[size] = '\0';
		printf("%s out:%s\n size:%d usedsize:%d\n", currentThread->getName(),  (char*)item,size,boundedbuffer->UsedSize);
	}
}

void
ThreadTest4()
{
	DEBUG('t', "Entering ThreadTest4 ");
	//list=new DLList();
	boundedbuffer = new BoundedBuffer(BOUNDEDBUFFERSIZE);
	for (int var = 0; var < producersnum; var++)
	{
		char No[4] = "1";
		sprintf(No, "%d", var);
		//char name[18]="forked thread ";	//error
		char *name = new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
		name[0] = '\0';
		strcat(name, "producer thread ");
		strcat(name, No);

		Thread *t = new Thread(name);
		t->Fork(TestBuffer_producer, var);
	}
	for (int var = 0; var < consumersnum; var++)
	{
		char No[4] = "1";
		sprintf(No, "%d", var);
		//char name[18]="forked thread ";	//error
		char *name = new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
		name[0] = '\0';
		strcat(name, "consumer thread ");
		strcat(name, No);

		Thread *t = new Thread(name);
		t->Fork(TestBuffer_consumer, var);
	}
}

//----------------------------------------------------------------------
// ThreadTest5 -e 
//  test EventBarrier
//----------------------------------------------------------------------

void
TestEventBarrier_runing(int whitch)
{
	barrier->Wait();
	for (int i = 0; i < 1000; ++i)
	{
		for (int i = 0; i < 1000; ++i)
		{
			currentThread->Yield();
//thread runing;
		}
	}
    printf("%s complete\n", currentThread->getName());
    printf("waiters:%d\n", barrier->Waiters());
    
	barrier->Complete();
	printf("%s finished\n", currentThread->getName());
	printf("waiters:%d\n", barrier->Waiters());
}

void
TestEventBarrier_signal(int whitch)
{
	printf("----%s signaled-----\n", currentThread->getName());
	barrier->Signal();
}

void
ThreadTest5()
{

	Thread *tthread[4];
	barrier = new EventBarrier();
	tthread[0] = new Thread("thread 0");
	tthread[1] = new Thread("thread 1");
	tthread[0]->Fork(TestEventBarrier_runing, 0);
	tthread[1]->Fork(TestEventBarrier_runing, 1);

	tthread[2] = new Thread("thread 2");
	tthread[2]->Fork(TestEventBarrier_signal, 2);
}

//----------------------------------------------------------------------
// ThreadTest6 -g 
//  test Alarm
//----------------------------------------------------------------------

void TestAlarm1(int time)
{
	printf("set %s %d\n", currentThread->getName(), time);
	Alarm::instance->Pause(time);
	printf("%s wake up at %d ticks\n", currentThread->getName(), stats->totalTicks);
}

void TestAlarm(int time)
{
	printf("set %s %d\n", currentThread->getName(), time);
	Alarm::instance->Pause(time);
	printf("%s wake up at %d ticks\n", currentThread->getName(), stats->totalTicks);
	if(time==3)
	{
		Thread *tthread = new Thread("thread 3");
		tthread->Fork(TestAlarm1, 2);
	}
}


/*
void Loop(int which)
{
	while (true)
	{
		currentThread->Yield();
	}
}
*/
void
ThreadTest6()
{

	Thread *tthread[4];
	Alarm::new_instance();
	//alarm = new Alarm;
	tthread[0] = new Thread("thread 0");
	tthread[1] = new Thread("thread 1");
	tthread[2] = new Thread("thread 2");

	tthread[0]->Fork(TestAlarm, 1);
	tthread[1]->Fork(TestAlarm, 2);
	tthread[2]->Fork(TestAlarm, 3);


	//tthread[2] = new Thread("thread 2");
	//tthread[2]->Fork(Loop, 3);

}

//----------------------------------------------------------------------
// ThreadTest7 -h 
//  test bridge
//----------------------------------------------------------------------
int Total_num=10;
int sumtime=0;
int End_num=0;
int should_start_time = 0;    //当前进程应当开始的时间

void
TestBridge(int whitch)
{
	int rand_time = Random() % 10;   //随机时间间隔
	should_start_time += rand_time;
	Alarm::instance->Pause(should_start_time);
	int start_time = stats->totalTicks;
	int direc=Random() % 2;
	printf("%s start at %d ticks in %d direction\n",currentThread->getName(),start_time,direc);
	Bridge::instance->OneVehicle(direc);
	printf("%s costs %d\n\n", currentThread->getName(), stats->totalTicks - start_time);
	sumtime+=stats->totalTicks - start_time;
	End_num++;
	if(End_num==Total_num)
	{
		printf("\n------avg turnaround time %.2f------\n\n",(float)sumtime/Total_num);

	}
}


void
ThreadTest7()
{
	Bridge::new_instance();
	Alarm::new_instance();
	//alarm = new Alarm;
	for (int i = 0; i < Total_num; ++i)
	{
		char No[4] = "1";
		sprintf(No, "%d", i);
		char *name = new char[25]; 
		name[0] = '\0';
		strcat(name, "car ");
		strcat(name, No);

		Thread *t = new Thread(name);
		t->Fork(TestBridge, i);
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
	case 3:
	ThreadTest3();
	break;
	case 4:
	ThreadTest4();
	break;
	case 5:
	ThreadTest5();
	break;
	case 6:
	ThreadTest6();
	break;
	case 7:
	ThreadTest7();
	break;
    default:
	printf("No test specified.\n");
	break;
    }
}

