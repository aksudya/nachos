#include  "BoundedBuffer.h"

BoundedBuffer::BoundedBuffer(int maxsize)
{
	this->maxsize = maxsize;
	lock = new Lock("Buffer lock");
	NotFull = new Condition("Buffer not full cond");
	NotEmpty = new Condition("Buffer not empty cond");
	FrontPlace = 0;
	BackPlace = 0;
	UsedSize = 0;
	buffer = new char[maxsize];
}

BoundedBuffer::~BoundedBuffer()
{
	delete lock;
	delete NotFull;
	delete NotEmpty;
	delete buffer;
}

void BoundedBuffer::Write(void* data, int size)
{
	lock->Acquire();	
	while (maxsize-UsedSize<size)
	{
		NotFull->Wait(lock);
	}
	void *ptr = buffer + FrontPlace;
	ptr = data;
	FrontPlace = (FrontPlace + size) % maxsize;
	UsedSize += size;
	NotEmpty->Signal(lock);
	lock->Release();
}

void BoundedBuffer::Read(void* data, int size)
{
	lock->Acquire();
	while (UsedSize-size<0)
	{
		NotEmpty->Wait(lock);
	}
	void *ptr = buffer + BackPlace;
	data = ptr;
	BackPlace = (FrontPlace + size) % maxsize;
	UsedSize -= size;
	NotFull->Signal(lock);
	lock->Release();
}
