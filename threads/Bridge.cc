#include "Bridge.h"
#include "Alarm.h"

//extern Alarm *alarm;

Bridge * Bridge::instance;

void Bridge::new_instance()
{
	instance=new Bridge();
}

#ifdef FCFS				//先来先服务算法

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

	while (direc != current_direc || on_bridge_num>=3 || pre_is_wait)
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
	Alarm::instance->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	on_bridge_num--;
	printf("%s car leave the bridge\n", currentThread->getName());
	con->Broadcast(lock);


	lock->Release();

}

#endif


#ifdef ONE_DIRECTION		//同方向优化算法

Bridge::Bridge()
{
	lock = new Lock("bridge lock");
	con = new Condition("ONE_DIRECTION condition");
	on_bridge_num = 0;
	current_direc=0;
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

	while(direc != current_direc || on_bridge_num>=3)
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
	Alarm::instance->Pause(CROSS_BRIDGE_TIME);
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

void TrafficLightManager(int whitch)
{
	Bridge::instance->lock->Acquire();
	if (stats->totalTicks >= Bridge::instance->next_switch_time)
	{
		Bridge::instance->yellow_light_on = true;
		if(Bridge::instance->on_bridge_num==0)
		{
			Bridge::instance->yellow_light_on = false;
			Bridge::instance->switch_status();
		}	
	}
	Bridge::instance->lock->Release();

	currentThread->Yield();
}


Bridge::Bridge()
{
	lock = new Lock("bridge lock");
	direc_con[0] = new Condition("direc 0 condition");
	direc_con[1] = new Condition("direc 1 condition");

	on_bridge_num = 0;
	current_direc = 1;		//默认0方向先行,由于最开始要切换一次方向，故先设成1

	next_switch_time = 0;

	yellow_light_on = false;

	direc_time[0] = BASE_GREEN_LIGHT_TIME;
	direc_time[1] = BASE_GREEN_LIGHT_TIME;

	direc_car_num[0] = 0;
	direc_car_num[1] = 0;

	manager = new Thread("traffic light manager thread");
	manager->Fork(TrafficLightManager, 0);
}



Bridge::~Bridge()
{
	delete lock;
	delete direc_con[0];
	delete direc_con[1];
}

void Bridge::ArriveBridge(int direc)
{
	lock->Acquire();	

	while (direc != current_direc || on_bridge_num >= 3 || yellow_light_on)
	{

		direc_car_num[direc]++;
		direc_con[direc]->Wait(lock);
		direc_car_num[direc]--;
		
	}

	on_bridge_num++;

	lock->Release();
}

void Bridge::CrossBridge(int direc)
{
	printf("%s car is crossing the bridge in %d direc\n%d cars on the bridge\n"
		, currentThread->getName(), direc, on_bridge_num);
	Alarm::instance->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	on_bridge_num--;
	printf("%s car leave the bridge\n", currentThread->getName());
	direc_con[direc]->Broadcast(lock);

	lock->Release();
}

void Bridge::switch_status()
{
	current_direc = (current_direc + 1) % 2;      //切换方向
	
	if(current_direc==0)
	{
		direc_time[0] = (direc_car_num[0] / 3 + 1)*CROSS_BRIDGE_TIME;
		direc_time[1] = (direc_car_num[1] / 3 + 1)*CROSS_BRIDGE_TIME;
		if(direc_car_num[0] ==0 && direc_car_num[1]==0)
		{
			direc_time[0] = BASE_GREEN_LIGHT_TIME;
			direc_time[1] = BASE_GREEN_LIGHT_TIME;
		}
	}
    next_switch_time = stats->totalTicks + direc_time[current_direc];
	printf("now switch the direc to %d\n%d ticks to next switch\n\n", 
		current_direc, direc_time[current_direc]);

	direc_con[current_direc]->Broadcast(lock);

}



#endif
