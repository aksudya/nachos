#pragma once
#include "system.h"
#include "synch.h"
#define CROSS_BRIDGE_TIME 10

#define FCFS            //先来先服务算法
//#define ONE_DIRECTION	//同方向优化算法
//#define TRAFFIC_LIGHT	//红绿灯算法


#ifdef FCFS            //先来先服务算法
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
private:
	void ArriveBridge(int direc);
	void CrossBridge(int direc);
	void ExitBridge(int direc);

	int on_bridge_num;
	int current_direc;

	Lock *lock;
	Condition *con;

};
#endif

#ifdef ONE_DIRECTION				//同方向优化算法

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
private:
	void ArriveBridge(int direc);
	void CrossBridge(int direc);
	void ExitBridge(int direc);

	int on_bridge_num;
	int current_direc;

	Lock *lock;
	Condition *con;

};

#endif

#ifdef TRAFFIC_LIGHT	//红绿灯算法

#define BASE_RED_LIGHT_TIME (10*CROSS_BRIDGE_TIME)		//基准红灯时间,为服务时间的十倍

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
private:
	void ArriveBridge(int direc);
	void CrossBridge(int direc);
	void ExitBridge(int direc);

	int on_bridge_num;
	int current_direc;

	Lock *lock;
	Condition *direc_0_con;
	Condition *direc_1_con;

	int direc_0_time;
	int direc_1_time;

	int direc_0_car_num;
	int direc_1_car_num;
};


#endif