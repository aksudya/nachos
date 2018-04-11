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

	for(int i=0;i<size;i++)
	{
		*((char*)buffer+(FrontPlace+i)%maxsize)=*((char*)data+i);
	}
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

	for(int i=0;i<size;i++)
	{
		*((char*)data+i)=*((char*)buffer+(BackPlace+i)%maxsize);
	}
	BackPlace = (BackPlace + size) % maxsize;
	UsedSize -= size;
	NotFull->Signal(lock);
	lock->Release();
}
