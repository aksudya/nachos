#include "Bridge.h"
#include "Alarm.h"
#include "../machine/stats.h"

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
	printf(">>>%s car is crossing the bridge in %d direc\n", currentThread->getName(), direc);
	printf(">>>%d cars on the bridge\n\n", on_bridge_num);
	Alarm::instance->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	on_bridge_num--;
	printf("---%s car leave the bridge\n", currentThread->getName());
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
	printf(">>>%s car is crossing the bridge in %d direc\n", currentThread->getName(), direc);
	printf(">>>%d cars on the bridge\n\n", on_bridge_num);
	Alarm::instance->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{
	lock->Acquire();

	on_bridge_num--;
    printf("---%s car leave the bridge\n",currentThread->getName());
	con->Broadcast(lock);


	lock->Release();

}



#endif


#ifdef BASIC_TRAFFIC_LIGHT		//基础版红绿灯算法

void TrafficLightManager(int whitch)
{
	while (!Bridge::instance->finished)
	{
		Bridge::instance->CheckIfDue();
		currentThread->Yield();
	}	
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

	direc_car_num[0] = 0;
	direc_car_num[1] = 0;

	manager = new Thread("traffic light manager thread");
	manager->Fork(TrafficLightManager, 0);
	finished=false;
}



Bridge::~Bridge()
{
	delete lock;
	delete direc_con[0];
	delete direc_con[1];
}

void Bridge::ArriveBridge(int direc)
{
	CheckIfDue();
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
	printf(">>>%s car is crossing the bridge in %d direc\n", currentThread->getName(), direc);
	printf(">>>%d cars on the bridge\n\n", on_bridge_num);
	Alarm::instance->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{

	lock->Acquire();

	on_bridge_num--;
	printf("---%s car leave the bridge at %d\n", currentThread->getName(), stats->totalTicks);
	direc_con[direc]->Broadcast(lock);

	lock->Release();
	CheckIfDue();
}

void Bridge::CheckIfDue()
{
	lock->Acquire();
	if (stats->totalTicks >= next_switch_time)
	{
		yellow_light_on = true;
		if (on_bridge_num == 0)
		{
			yellow_light_on = false;
			switch_status();
		}
	}
	lock->Release();
}

void Bridge::switch_status()
{
	current_direc = (current_direc + 1) % 2;      //切换方向
  next_switch_time = stats->totalTicks + BASE_GREEN_LIGHT_TIME* TimerTicks;
	printf("\n**************************************\n");
	printf("now switch the direc to %d\n",current_direc);
	printf("next switch at %d ticks\n", next_switch_time);
	printf("0 wait cars %d\t1 wait cars %d", direc_car_num[0],direc_car_num[1]);
	printf("\n**************************************\n\n");

	direc_con[current_direc]->Broadcast(lock);

}

#endif

#ifdef ADV_TRAFFIC_LIGHT		//改进版红绿灯算法（动态调节）

void TrafficLightManager(int whitch)
{
	while (!Bridge::instance->finished)
	{
		Bridge::instance->lock->Acquire();
		Bridge::instance->CheckIfDue();
		Bridge::instance->lock->Release();
		currentThread->Yield();
	}
}

Bridge::Bridge()
{
	lock = new Lock("bridge lock");
	direc_con[0] = new Condition("direc 0 condition");
	direc_con[1] = new Condition("direc 1 condition");

	on_bridge_num = 0;
	current_direc = 1;		//默认0方向先行,由于最开始要切换一次方向，故先设成1

	yellow_light_on = false;
	next_switch_time = 0;

	direc_car_num[0] = 0;
	direc_car_num[1] = 0;

	direc_car_can_go[0] = 0;
	direc_car_can_go[1] = 0;

	finished = false;
	switchCount = 0;

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
	direc_car_num[direc]++;
	//CheckIfDue();
	while (direc != current_direc || on_bridge_num >= 3 || yellow_light_on ||(direc_car_can_go[direc]<=0 && switchCount>1))
	{
		CheckIfDue();
		direc_con[direc]->Wait(lock);
	}
	if(switchCount<=1)
	{
		direc_car_num[direc]--;
	}
	direc_car_can_go[direc]--;
	
	on_bridge_num++;

	lock->Release();
}

void Bridge::CrossBridge(int direc)
{
	printf(">>>%s car is crossing the bridge in %d direc\n", currentThread->getName(), direc);
	printf(">>>%d cars on the bridge\n\n", on_bridge_num);

	Alarm::instance->Pause(CROSS_BRIDGE_TIME);
}

void Bridge::ExitBridge(int direc)
{

	lock->Acquire();

	on_bridge_num--;
	printf("---%s car leave the bridge at %d\n", currentThread->getName(), stats->totalTicks);
	direc_con[direc]->Broadcast(lock);
	CheckIfDue();
	lock->Release();

}

void Bridge::CheckIfDue()
{
	//lock->Acquire();
	if (switchCount<=1)
	{
		if (stats->totalTicks >= next_switch_time)
		{
			yellow_light_on = true;
			if (on_bridge_num == 0)
			{
				yellow_light_on = false;
				switch_status();
			}
		}
	}
	else if (direc_car_can_go[current_direc]<=0)
	{
		yellow_light_on = true;
		if (on_bridge_num == 0)
		{
			yellow_light_on = false;
			switch_status();
		}
	}
	//lock->Release();
}

void Bridge::switch_status()
{
	current_direc = (current_direc + 1) % 2;      //切换方向

	if (current_direc == 0)
	{
		switchCount++;
		direc_car_can_go[0] = direc_car_num[0];
		direc_car_can_go[1] = direc_car_num[1];
		direc_car_num[0] = 0;
		direc_car_num[1] = 0;
	}
	next_switch_time = stats->totalTicks + BASE_GREEN_LIGHT_TIME * TimerTicks;
	printf("\n**********************\n");
	printf("now switch the direc to %d\n",current_direc);
	printf("%d cars to next switch\n",direc_car_can_go[current_direc]);
	printf("0 come cars %d\t1 come cars %d", direc_car_can_go[0], direc_car_can_go[1]);
	printf("\n**********************\n\n");
	direc_con[current_direc]->Broadcast(lock);
}

#endif
