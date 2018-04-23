#include "Bridge.h"
#include "Alarm.h"

extern Alarm *alarm;

#ifdef FCFS

Bridge::Bridge()
{
	lock = new Lock("bridge lock");
	con = new Condition("FCFS condition");
	on_bridge_num = 0;
}

Bridge::~Bridge()
{
	delete lock;
	delete con;
}

void Bridge::ArriveBridge(int direc)
{
	lock->Acquire();

	if(on_bridge_num==0)
	{
		current_direc = direc;
	}

	while((direc==0 && ( current_direc==1 || on_bridge_num>=3))
		&& (direc == 1 && (current_direc == 0 || on_bridge_num >= 3)))
	{
		con->Wait(lock);
	}
	
	on_bridge_num++;

	lock->Release();
}

void Bridge::CrossBridge(int direc)
{
	printf("%s car is crossing the bridge in %d direc\n%d cars on the bridge\n\n"
		,currentThread->getName(), direc,on_bridge_num);
	alarm->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	on_bridge_num--;
	con->Broadcast(lock);

	lock->Release();
}



#endif
