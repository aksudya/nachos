#include "Table.h"

Table::Table(int size)
{
	TableSize=size;
	lock = new Lock("Table lock");
	base = new void*[size];
	for (int i = 0; i < size; ++i)
	{
		base[i] = NULL;
	}
	
}

Table::~Table()
{
	delete base;
	delete lock;
}

int Table::Alloc(void* object)
{
	int re;	
	lock->Acquire();
	int NowIndex=0;
	while (base[NowIndex]!=NULL
		&&NowIndex<TableSize)
	{
		NowIndex++;
	}
	if (NowIndex >= TableSize)
		re = -1;
	else
	{
		base[NowIndex] = object;
		re = NowIndex;
	}
	ASSERT(re!=-1);
	lock->Release();
	return re;
}

void* Table::Get(int index)
{
	lock->Acquire();
	void* item;
	ASSERT(index<TableSize);
	if(index>=TableSize)
	{
		item=NULL;
	}
	item = base[index];
	lock->Release();
	return item;

}

void Table::Release(int index)
{
	lock->Acquire();
	ASSERT(index<TableSize);
	base[index] = NULL;
	lock->Release();
}

