#pragma once
#include "system.h"
#include "synch.h"
#define CROSS_BRIDGE_TIME 10

#define FCFS

#ifdef FCFS

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