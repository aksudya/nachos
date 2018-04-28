//#include <cstdlib>
//#include <cstdio>
//#include<ctime>
#include "system.h"
#include "synch.h"

#define START_KEY 100

class DLLElement {
public:
    DLLElement( void *itemPtr, int sortKey );   // initialize a list element
    DLLElement *next;
    DLLElement *prev;
    int key;
    void *item;
};

class DLList {
public:
    DLList();
    ~DLList();

    void Prepend(void *item);
    void Append(void *item);
    void *Remove(int *keyPtr);


    bool IsEmpty();

    void SortedInsert(void *item, int sortKey);
    void *SortedRemove(int sortKey);

private:
    DLLElement *first;
    DLLElement *last;

	Lock *lock;				// enforce mutual exclusive access to the list
	//Condition *listEmpty;	// wait in Remove if the list is empty
};
