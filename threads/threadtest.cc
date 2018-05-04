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
#include "../userprog/syscall.h"

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

void InsertList(int N, DLList *list);
void RemoveList(int N, DLList *list);
//----------------------------------------------------------------------
// SimpleThread
// 	Loop 5 times, yielding the CPU to another ready thread 
//	each iteration.
//
//	"which" is simply a number identifying the thread, for debugging
//	purposes.
//
// ThreadTest1
// 	Set up a ping-pong between two threads, by forking a thread 
//	to call SimpleThread, and then calling SimpleThread ourselves.
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
// ThreadTest2
//  -m [P] [C]
// 	testDllist with producer-consumer model
//----------------------------------------------------------------------

void
TestDllist_producer(int which)
{

	while (true)
	{
		 void *item;
		 int key=Random()%10;
		 int *items=new int[1];
		 items[0]=-key;
		 item=items;
		 printf("%s in:%d %d\n",currentThread->getName(),key,*(int*)item);
		 list->SortedInsert(item,key);
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
		 ASSERT(item != NULL);
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
			char *name=new char[25];			
			strcat(name,"producer thread ");
			strcat(name,No);
			//给thread命名

			Thread *t = new Thread(name);
			t->Fork(TestDllist_producer,var);
		}
		for (int var = 0; var < consumersnum; var++)
		{
			char No[4] = "1";
			sprintf(No, "%d", var);
			char *name = new char[25];			
			name[0] = '\0';
			strcat(name, "consumer thread ");
			strcat(name, No);

			Thread *t = new Thread(name);
			t->Fork(TestDllist_consumer, var);
		}
}


//----------------------------------------------------------------------
// ThreadTest3
//  -a [P] [C]
// 	testTable with producer-consumer model
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
		printf("%s in:%d %d\n", currentThread->getName(), 
			table->Alloc(item), *(int*)item);
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
		table->Release(index);			//取出并释放第一个非NULL元素
		printf("%s out:%d %d\n", currentThread->getName(), 
			index, *(int*)item);
	}
}

void
ThreadTest3()
{
	DEBUG('t', "Entering ThreadTest3 ");
	table = new Table(TABLESIZE);
	for (int var = 0; var < producersnum; var++)
	{
		char No[4]="1";
		sprintf(No, "%d", var);
		char *name=new char[25];			
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
		char *name = new char[25];			
		name[0] = '\0';
		strcat(name, "consumer thread ");
		strcat(name, No);

		Thread *t = new Thread(name);
		t->Fork(TestTable_consumer, var);
	}
}

//----------------------------------------------------------------------
// ThreadTest4
//  -b [P] [C]
// 	test boundedbuffer with producer-consumer model
//----------------------------------------------------------------------

void
TestBuffer_producer(int which)
{

	while (true)
	{
		int size = Random() % 20+1;
		char *items = new char[size+1];
		for (int i = 0; i < size; ++i)
		{
			items[i] = 65 + i;
		}
		items[size] = '\0';
		boundedbuffer->Write(items, size);
		printf("%s in:%s\n size:%d usedsize:%d\n", 
			currentThread->getName(), items,size,boundedbuffer->UsedSize );
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
		printf("%s out:%s\n size:%d usedsize:%d\n", 
			currentThread->getName(),  (char*)item,size,boundedbuffer->UsedSize);
	}
}


void
ThreadTest4()
{
	DEBUG('t', "Entering ThreadTest4 ");
	boundedbuffer = new BoundedBuffer(BOUNDEDBUFFERSIZE);
	for (int var = 0; var < producersnum; var++)
	{
		char No[4] = "1";
		sprintf(No, "%d", var);
		char *name = new char[25];			
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
		char *name = new char[25];			
		name[0] = '\0';
		strcat(name, "consumer thread ");
		strcat(name, No);

		Thread *t = new Thread(name);
		t->Fork(TestBuffer_consumer, var);
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
    default:
	printf("No test specified.\n");
	break;
    }
}

