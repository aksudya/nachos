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

		//int size = 1;
		//char *items = new char[size + 1];
		//items[0]= Random() % 20 + 1+65;
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
		//int size = 1;
		char *item= new char[size + 1];
		boundedbuffer->Read(item, size);
		item[size] = '\0';
		printf("%s out:%s\n size:%d usedsize:%d\n", currentThread->getName(),  (char*)item,size,boundedbuffer->UsedSize);
	}
}

void
TestBuffer_producer_1(int which)
{

	for (int i = 0; i < 5; ++i)
	{
		//int size = Random() % 20 + 1;
		////int key=i;
		//char *items = new char[size + 1];
		//for (int i = 0; i < size; ++i)
		//{
		//	items[i] = 65 + i;
		//}

		int size = 1;
		char *items = new char[size + 1];
		items[0]= Random() % 20 + 1+65;
		items[size] = '\0';
		boundedbuffer->Write(items, size);
		printf("%s in:%s\n size:%d usedsize:%d\n", currentThread->getName(), items, size, boundedbuffer->UsedSize);
		currentThread->Yield();

		//currentThread->Yield();
	}

}

void
TestBuffer_consumer_1(int which)
{
	for (int i = 0; i < 10; ++i)
	{
		//int size = Random() % 10 + 1;
		int size = 1;
		char *item = new char[size + 1];
		boundedbuffer->Read(item, size);
		item[size] = '\0';
		printf("%s out:%s\n size:%d usedsize:%d\n", currentThread->getName(), (char*)item, size, boundedbuffer->UsedSize);
		currentThread->Yield();
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

void
ThreadTest5()
{
	DEBUG('t', "Entering ThreadTest5 ");
	//list=new DLList();
	boundedbuffer = new BoundedBuffer(BOUNDEDBUFFERSIZE);
	for (int var = 0; var < 2; var++)
	{
		char No[4] = "1";
		sprintf(No, "%d", var);
		//char name[18]="forked thread ";	//error
		char *name = new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
		name[0] = '\0';
		strcat(name, "producer thread ");
		strcat(name, No);
		if(var==0)
		{
			Thread *t = new Thread(name,1);
			t->Fork(TestBuffer_producer_1, var);
		}
		else if(var==1)
		{
			Thread *t = new Thread(name,0);
			t->Fork(TestBuffer_producer_1, var);
		}

	}
	for (int var = 0; var < 1; var++)
	{
		char No[4] = "1";
		sprintf(No, "%d", var);
		//char name[18]="forked thread ";	//error
		char *name = new char[25];			//必须分配新空间，否则新进程会覆盖掉原有name地址
		name[0] = '\0';
		strcat(name, "consumer thread ");
		strcat(name, No);

		Thread *t = new Thread(name,1);
		t->Fork(TestBuffer_consumer_1, var);
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
    default:
	printf("No test specified.\n");
	break;
    }
}

