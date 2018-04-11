
#include "dllist.h"


void InsertList(int N, DLList *list)
{
    for (int i = 0; i < N; i++)
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

void RemoveList(int N, DLList *list)
{
    for (int i = 0; i < N; i++)
    {
        int key;
        void *item;
        item=list->Remove(&key);
        printf("%s out:%d %d\n",currentThread->getName(),key,*(int*)item);
        //currentThread->Yield();
    }
}

