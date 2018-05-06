#pragma once
#include "system.h"
#include "synch.h"
#define CROSS_BRIDGE_TIME 10
#define BASE_GREEN_LIGHT_TIME (10*CROSS_BRIDGE_TIME)		//基准绿灯时间,为服务时间的十倍

//#define FCFS					//先来先服务算法
//#define ONE_DIRECTION			//同方向优化算法
//#define BASIC_TRAFFIC_LIGHT	//基础版红绿灯算法
#define ADV_TRAFFIC_LIGHT		//改进版红绿灯算法（动态调节）

#if (defined BASIC_TRAFFIC_LIGHT )||(defined ADV_TRAFFIC_LIGHT )
void TrafficLightManager(int whitch);
#endif


class Bridge
{
public:
	Bridge();
	~Bridge();
	void OneVehicle(int direc)
	{
		ArriveBridge(direc);
		CrossBridge(direc);
		ExitBridge(direc);
	};

	static void new_instance();
	static Bridge *instance;
private:
	void ArriveBridge(int direc);
	void CrossBridge(int direc);
	void ExitBridge(int direc);

#ifdef FCFS            				//先来先服务算法
	int on_bridge_num;
	int current_direc;

	bool pre_is_wait;
	Lock *lock;
	Condition *con;
#endif

#ifdef ONE_DIRECTION				//同方向优化算法
	int on_bridge_num;
	int current_direc;

	Lock *lock;
	Condition *con;
#endif

#ifdef BASIC_TRAFFIC_LIGHT					//基础版红绿灯算法
	
public:	
	int on_bridge_num;
	int current_direc;
  int next_switch_time;
	
	bool yellow_light_on;	

	Lock *lock;
	Condition *direc_con[2];

	int direc_car_num[2];

	void switch_status();

	void CheckIfDue();

	bool finished;
	Thread *manager;                  //红绿灯管理进程
#endif

#ifdef ADV_TRAFFIC_LIGHT
public:
	Thread * manager;

	int on_bridge_num;
	int current_direc;
	int next_switch_time;

	bool yellow_light_on;

	Lock *lock;
	Condition *direc_con[2];

	int direc_car_num[2];			//用来记录某个方向有多少车
	int direc_car_can_go[2];		//用来记录还剩多少可以放行的车

	void switch_status();

	void CheckIfDue();

	int switchCount;				//循环次数
	bool finished;
#endif

};


