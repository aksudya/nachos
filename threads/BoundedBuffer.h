#include "list.h"
#include "synch.h"

class BoundedBuffer {
   public:
     // create a bounded buffer with a limit of 'maxsize' bytes
     BoundedBuffer(int maxsize);
     ~BoundedBuffer();
     // read 'size' bytes from the bounded buffer, storing into 'data'.
     // ('size' may be greater than 'maxsize')
     void Read(void *data, int size);
     
     // write 'size' bytes from 'data' into the bounded buffer.
     // ('size' may be greater than 'maxsize')
     void Write(void *data, int size);
     
    
   private:
	void *buffer;
    int maxsize;   
	int FrontPlace,BackPlace;		//标志被填充数据区域的前后位置
	int UsedSize;					//buffer已被使用的大小
	Lock *lock;
	Condition *NotFull, *NotEmpty;
};

