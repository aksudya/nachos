#pragma once
#include "Elevator.h"
#include "Alarm.h"

Building *Building::instance;

Elevator * Building::getElevator()
{
	return elevator;
}

void Building::new_instance(char *debugname, int numFloors, int numElevators)
{
	instance = new Building(debugname,numFloors,numElevators);
}

Building::Building(char* debugname, int numFloors, int numElevators)
{
	name = debugname;
	this->numFloors = numFloors;
	this->numElevators = numElevators;
	elevator =new Elevator("elevator", numFloors,1);
	BuildingLock = new Lock("Building lock");
}

Building::~Building()
{
	delete elevator;
	delete BuildingLock;
}

Elevator* Building::AwaitDown(int fromFloor)
{
	elevator->ElevatorDownBarrier[fromFloor]->Wait();
	return elevator;
}

Elevator* Building::AwaitUp(int fromFloor)
{
	elevator->ElevatorUpBarrier[fromFloor]->Wait();
	return elevator;
}

void Building::CallDown(int fromFloor)
{
	elevator->ElevatorLock->Acquire();
	elevator->HaveRequest->Signal(elevator->ElevatorLock);
	elevator->ElevatorLock->Release();
}

void Building::CallUp(int fromFloor)
{
	elevator->ElevatorLock->Acquire();
	elevator->HaveRequest->Signal(elevator->ElevatorLock);
	elevator->ElevatorLock->Release();
}

Elevator::Elevator(char* debugName, int numFloors, int myID)
{
	name = debugName;
	this->numFloors = numFloors;
	ElevatorID = myID;
	ElevatorUpBarrier = new EventBarrier*[numFloors];
	ElevatorDownBarrier = new EventBarrier*[numFloors];
	ElevatorOutBarrier = new EventBarrier*[numFloors];
	for (int i = 0; i < numFloors; ++i)
	{
		ElevatorUpBarrier[i] = new EventBarrier;
		ElevatorDownBarrier[i] = new EventBarrier;
		ElevatorOutBarrier[i] = new EventBarrier;
	}
	
	ElevatorLock = new Lock("Elevator lock");
	state = STOP;
	currentfloor = 0;

	HaveRequest = new Condition("have a elevator requset");
	occupancy=0;
}

Elevator::~Elevator()
{
	for (int i = 0; i < numFloors; ++i)
	{
		delete ElevatorUpBarrier[i];
		delete ElevatorDownBarrier[i];
		delete ElevatorOutBarrier[i];
	}
	delete[] ElevatorUpBarrier;
	delete[] ElevatorDownBarrier;
	delete[] ElevatorOutBarrier;
	delete[] ElevatorLock;
	delete HaveRequest;
}

void Elevator::OpenDoors()
{
	Alarm::instance->Pause(OPEN_AND_CLOSE_DOOR);
	printf("now elevator open door\n");
	if(ElevatorOutBarrier[currentfloor]->Waiters()!=0)
	{
		ElevatorOutBarrier[currentfloor]->Signal();
	}
	if (state == UP)
	{
		if (ElevatorUpBarrier[currentfloor]->Waiters() != 0)
		{
			ElevatorUpBarrier[currentfloor]->Signal();
		}		
	}
	else if (state == DOWN)
	{
		if (ElevatorDownBarrier[currentfloor]->Waiters() != 0)
		{
			ElevatorDownBarrier[currentfloor]->Signal();
		}
	}

}

void Elevator::CloseDoors()
{
	Alarm::instance->Pause(OPEN_AND_CLOSE_DOOR);
}

void Elevator::VisitFloor(int floor)
{
	Alarm::instance->Pause(ELEVATOR_MOVE_ONE_FLOOR);
	currentfloor = floor;
}


bool Elevator::Enter()
{
	Alarm::instance->Pause(RIDER_ENTER_OUT);
	if(state==UP)
	{
		ElevatorUpBarrier[currentfloor]->Complete();
	}
	else if(state==DOWN)
	{
		ElevatorDownBarrier[currentfloor]->Complete();
	}
	occupancy++;
	if(occupancy<=ELEVATOR_CAPACITY)
	{
		return true;
	}
	else
	{
		occupancy--;
		return false;
	}

}

void Elevator::Exit()
{
	Alarm::instance->Pause(RIDER_ENTER_OUT);
	ElevatorOutBarrier[currentfloor]->Complete();
	occupancy--;
}

void Elevator::RequestFloor(int floor)
{
	ElevatorOutBarrier[floor]->Wait();
}

int Elevator::GetNextFloor()
{
	ElevatorLock->Acquire();
	int return_value=-1;
	if(state==STOP)
	{
		for (int i = 0; i < numFloors; ++i)
		{
			if(ElevatorUpBarrier[i]->Waiters() != 0 || ElevatorDownBarrier[i]->Waiters() != 0)
			{
				return_value=i;
				break;
			}
		}
		if(return_value!=-1)
		{
			if(return_value>currentfloor)
			{
				state=UP;
			}
			else if(return_value<=currentfloor)
			{
				state=DOWN;
			}
		}
	}
	else if(state==UP)
	{
		for (int i = currentfloor; i < numFloors; ++i)
		{
			if (ElevatorUpBarrier[i]->Waiters() != 0)
			{
				return_value = i;
				break;
			}
			if(ElevatorOutBarrier[i]->Waiters() != 0)
			{
				return_value = i;
				break;
			}
		}
		if(return_value==-1)
		{
			for (int i = numFloors-1; i >= currentfloor; --i)
			{
				if (ElevatorDownBarrier[i]->Waiters() != 0)
				{
					return_value = i;
					if(return_value==currentfloor)
					{
						state = DOWN;
					}
					break;
				}
			}
			if(return_value==-1)
			{
				state = DOWN;
			}
		}
	}
	else
	{
		for (int i = currentfloor; i >= 0; --i)
		{
			if (ElevatorDownBarrier[i]->Waiters() != 0)
			{
				return_value = i;
				break;
			}
			if (ElevatorOutBarrier[i]->Waiters() != 0)
			{
				return_value = i;
				break;
			}
		}
		if(return_value==-1)
		{
			for (int i = 0; i <= currentfloor; ++i)
			{
				if (ElevatorUpBarrier[i]->Waiters() != 0)
				{
					return_value = i;
					if(return_value==currentfloor)
					{
						state = UP;
					}
					break;
				}
			}
			if(return_value==-1)
			{
				state = UP;
			}
		}
	}
	ElevatorLock->Release();
	return return_value;
}

void Elevator::ElevatorControl()
{
	bool no_requset_flag = false;
	while (true)
	{
		int next_floor = GetNextFloor();
		if(state==STOP)
		{
			ElevatorLock->Acquire();
			HaveRequest->Wait(ElevatorLock);
			ElevatorLock->Release();
			printf("now elevator at %d floor\n",currentfloor);
		}
		else if(state==UP)
		{			
			//int next_floor = GetNextFloor();
			while (currentfloor != next_floor && next_floor !=-1)
			{			
				VisitFloor(currentfloor + 1);
				next_floor = GetNextFloor();
				printf("now elevator at %d floor\n",currentfloor);
			}
			if(next_floor==-1)
			{
				if (no_requset_flag)
				{
					state = STOP;
					continue;
				}
				no_requset_flag = true;
				continue;
			}
			else
			{
				no_requset_flag = false;
				OpenDoors();
				CloseDoors();
			}			
		}
		else if (state == DOWN)
		{
			//int next_floor = GetNextFloor();
			while (currentfloor != next_floor && next_floor != -1)
			{
				VisitFloor(currentfloor - 1);
				next_floor = GetNextFloor();
				printf("now elevator at %d floor\n",currentfloor);
			}
			if (next_floor == -1)
			{
				if (no_requset_flag)
				{
					state = STOP;
					continue;
				}
				no_requset_flag = true;
				continue;
			}
			else
			{
				no_requset_flag = false;
				OpenDoors();
				CloseDoors();
			}
		}
	currentThread->Yield();
	}

}

void rider(int id, int srcFloor, int dstFloor)
{
	Elevator *e;

	if (srcFloor == dstFloor)
		return;

	printf("Rider %d travelling from %d to %d\n", id, srcFloor, dstFloor);
	do {
		if (srcFloor < dstFloor) {
			printf("Rider %d CallUp(%d)\n", id, srcFloor);
			Building::instance->CallUp(srcFloor);
			printf("Rider %d AwaitUp(%d)\n", id, srcFloor);
			e = Building::instance->AwaitUp(srcFloor);
		}
		else {
			printf("Rider %d CallDown(%d)\n", id, srcFloor);
			Building::instance->CallDown(srcFloor);
			printf("Rider %d AwaitDown(%d)\n", id, srcFloor);
			e = Building::instance->AwaitDown(srcFloor);
		}
		printf("Rider %d Enter()\n", id);
	} while (!e->Enter()); // elevator might be full!

	printf("Rider %d RequestFloor(%d)\n", id, dstFloor);
	e->RequestFloor(dstFloor); // doesn't return until arrival
	printf("Rider %d Exit()\n", id);
	e->Exit();
	printf("Rider %d finished\n", id);
}
