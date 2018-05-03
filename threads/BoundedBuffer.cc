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
	while (maxsize-UsedSize<size)	//满等待
	{
		NotFull->Wait(lock);
	}

	for(int i=0;i<size;i++)
	{
		*((char*)buffer+(FrontPlace+i)%maxsize)=*((char*)data+i);
		//计算写入位置并把字节写入buffer
	}
	FrontPlace = (FrontPlace + size) % maxsize;//将前指针向前移动
	UsedSize += size;
	NotEmpty->Signal(lock);
	lock->Release();
}

void BoundedBuffer::Read(void* data, int size)
{
	lock->Acquire();
	while (UsedSize-size<0)			//空等待
	{
		NotEmpty->Wait(lock);
	}

	for(int i=0;i<size;i++)
	{
		*((char*)data+i)=*((char*)buffer+(BackPlace+i)%maxsize);
		//计算移出位置并把字节读出buffer
	}
	BackPlace = (BackPlace + size) % maxsize;//将后部指针向前移动
	UsedSize -= size;
	NotFull->Signal(lock);
	lock->Release();
}
