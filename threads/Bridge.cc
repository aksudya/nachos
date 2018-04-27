#include "Bridge.h"
#include "Alarm.h"

extern Alarm *alarm;
#ifdef FCFS

Bridge::Bridge()
{
	lock = new Lock("bridge lock");
	con = new Condition("FCFS condition");
	on_bridge_num = 0;
	current_direc = 0;
	pre_is_wait = false;

}

Bridge::~Bridge()
{
	delete lock;
	delete con;
}

void Bridge::ArriveBridge(int direc)
{
	lock->Acquire();

	if (on_bridge_num == 0)
	{
		current_direc = direc;
	}

	while (direc != current_direc || on_bridge_num>3 || pre_is_wait)
	{
		pre_is_wait = true;
		con->Wait(lock);
		pre_is_wait = false;
		if (on_bridge_num == 0)
		{
			current_direc = direc;
		}
	}

	on_bridge_num++;

	lock->Release();
}

void Bridge::CrossBridge(int direc)
{
	printf("%s car is crossing the bridge in %d direc\n%d cars on the bridge\n"
		, currentThread->getName(), direc, on_bridge_num);
	alarm->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	on_bridge_num--;
	printf("%s car leave the bridge\n", currentThread->getName());
	con->Signal(lock);


	lock->Release();

}

#endif


#ifdef ONE_DIRECTION		//同方向优化算法

Bridge::Bridge()
{
	lock = new Lock("bridge lock");
	con = new Condition("ONE_DIRECTION condition");
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
		|| (direc == 1 && (current_direc == 0 || on_bridge_num >= 3)))
	{
		con->Wait(lock);
		if(on_bridge_num==0)
		{
			current_direc = direc;
		}
	}
	
	on_bridge_num++;

	lock->Release();
}

void Bridge::CrossBridge(int direc)
{
	printf("%s car is crossing the bridge in %d direc\n%d cars on the bridge\n"
		,currentThread->getName(), direc,on_bridge_num);
	alarm->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	on_bridge_num--;
    printf("%s car leave the bridge\n",currentThread->getName());
	con->Broadcast(lock);


	lock->Release();

}



#endif


#ifdef TRAFFIC_LIGHT	//红绿灯算法
Bridge::Bridge()
{
	lock = new Lock("bridge lock");
	direc_0_con = new Condition("direc 0 condition");
	direc_1_con = new Condition("direc 1 condition");

	on_bridge_num = 0;
	current_direc = 0;		//默认0方向先行

	direc_0_time = 0;
	direc_1_time = BASE_RED_LIGHT_TIME;

	direc_0_car_num = 0;
	direc_1_car_num = 0;
}



Bridge::~Bridge()
{
	delete lock;
	delete direc_0_con;
	delete direc_1_con;
}

void Bridge::ArriveBridge(int direc)
{
	lock->Acquire();



	lock->Release();
}

void Bridge::CrossBridge(int direc)
{
	printf("%s car is crossing the bridge in %d direc\n%d cars on the bridge\n"
		, currentThread->getName(), direc, on_bridge_num);
	alarm->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	lock->Release();
}



#endif
