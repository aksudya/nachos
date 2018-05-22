/*

Here are the method signatures for the Elevator and Building classes.
You should feel free to add to these classes, but do not change the
existing interfaces.

*/
#pragma once
#include "EventBarrier.h"
#include "system.h"
#include "synch.h"

//#define SINGLE_ELEVATOR					
#define MULTIPLE_ELEVATOR				//单个或多个电梯	

#define BOUNDED_ELEVATOR
//#define UNBOUNDED_ELEVATOR				//电梯容量是否有限

#define OPEN_AND_CLOSE_DOOR     20		//电梯开关门的时间
#define RIDER_ENTER_OUT           10	//一个乘客进出电梯的时间
#define ELEVATOR_MOVE_ONE_FLOOR 40		//电梯移动一层楼的时间

#ifdef BOUNDED_ELEVATOR
#define ELEVATOR_CAPACITY		5		//电梯容量
#endif



enum ElevatorState {UP,DOWN,STOP};
void rider(int id, int srcFloor, int dstFloor);

class Elevator {
public:
	friend class Building;
	Elevator(char *debugName, int numFloors, int myID);
	~Elevator();
	char *getName() { return name; }

	// elevator control interface: called by Elevator thread
	void OpenDoors();                //   signal exiters and enterers to action
	void CloseDoors();               //   after exiters are out and enterers are in
	void VisitFloor(int floor);      //   go to a particular floor

	// elevator rider interface (part 1): called by rider threads.
	bool Enter();                    //   get in
	void Exit();                     //   get out (iff destinationFloor)
	void RequestFloor(int floor);    //   tell the elevator our destinationFloor

								// insert your methods here, if needed
	void ElevatorControl();			//控制电梯运行

	int GetNextFloor();
private:
	char *name;

	int currentfloor;           // floor where currently stopped
	int occupancy;              // how many riders currently onboard

	 							// insert your data structures here, if needed
	int numFloors, ElevatorID;
	
	enum ElevatorState state;

	EventBarrier **ElevatorOutBarrier;		//出电梯栅栏

	Lock *ElevatorLock;
	
	Condition *HaveRequest;

#ifdef BOUNDED_ELEVATOR
	Condition *ElevatorNotFull;
#endif

};

class Building {
public:
	friend class Elevator;
	Building(char *debugname, int numFloors, int numElevators);
	~Building();
	char *getName() { return name; }


	// elevator rider interface (part 2): called by rider threads
	void CallUp(int fromFloor);      //   signal an elevator we want to go up
	void CallDown(int fromFloor);    //   ... down
	Elevator *AwaitUp(int fromFloor); // wait for elevator arrival & going up
	Elevator *AwaitDown(int fromFloor); // ... down

#ifdef SINGLE_ELEVATOR
	Elevator *getElevator();
#endif

#ifdef MULTIPLE_ELEVATOR
	Elevator *getElevator(int id);
	int ChooseElevator(int fromfloor);
#endif

	static void new_instance(char *debugname, int numFloors, int numElevators);
	static Building *instance;
private:
	char *name;

#ifdef SINGLE_ELEVATOR
	Elevator *elevator;         // the elevators in the building (array)
#endif

#ifdef MULTIPLE_ELEVATOR
	Elevator **elevator;
#endif

	EventBarrier **ElevatorUpBarrier;		//上行栅栏
	EventBarrier **ElevatorDownBarrier;		//下行栅栏
								// insert your data structures here, if needed
	int numFloors;
	int numElevators;

	Lock *BuildingLock;
	
};

// here's a sample portion of a rider thread body showing how we
// expect things to be called.
//
// void rider(int id, int srcFloor, int dstFloor) {
//    Elevator *e;
//  
//    if (srcFloor == dstFloor)
//       return;
//  
//    DEBUG('t',"Rider %d travelling from %d to %d\n",id,srcFloor,dstFloor);
//    do {
//       if (srcFloor < dstFloor) {
//          DEBUG('t', "Rider %d CallUp(%d)\n", id, srcFloor);
//          building->CallUp(srcFloor);
//          DEBUG('t', "Rider %d AwaitUp(%d)\n", id, srcFloor);
//          e = building->AwaitUp(srcFloor);
//       } else {
//          DEBUG('t', "Rider %d CallDown(%d)\n", id, srcFloor);
//          building->CallDown(srcFloor);
//          DEBUG('t', "Rider %d AwaitDown(%d)\n", id, srcFloor);
//          e = building->AwaitDown(srcFloor);
//       }
//       DEBUG('t', "Rider %d Enter()\n", id);
//    } while (!e->Enter()); // elevator might be full!
//  
//    DEBUG('t', "Rider %d RequestFloor(%d)\n", id, dstFloor);
//    e->RequestFloor(dstFloor); // doesn't return until arrival
//    DEBUG('t', "Rider %d Exit()\n", id);
//    e->Exit();
//    DEBUG('t', "Rider %d finished\n", id);
// }

