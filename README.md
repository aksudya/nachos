# nachos

## 操作系统课程实验

## 实验三代码
lab3_beta分支处代码实验三已更新完毕</br>
lab3分支处代码为另外一种电梯调度算法,仅实现了单个容量有限的电梯,没实现多个电梯</br>

使用方法：编译后cd到threads目录下使用

#### 1. 测试eventbarrier

```bash
./nachos -e
```
#### 2. 测试alarm

```bash
./nachos -g
```
#### 3. 测试bridge

```bash
./nachos -h
```

切换算法方法：

在Bridge.h头文件中修改宏定义
```c++
#define FCFS                  //先来先服务算法
#define ONE_DIRECTION         //同方向优化算法
#define BASIC_TRAFFIC_LIGHT   //基础版红绿灯算法
#define ADV_TRAFFIC_LIGHT     //改进版红绿灯算法（动态调节）
```
将除你想测试的算法之外的宏定义注释掉即可

在threadtest.cc文件中可以修改对应的测试参数
```c++
int Total_num=100;            //总测试的车辆数
int direc_0_percent=3;        //0方向来的车占的比例，	x/10
int random_come_time = 10;    //车辆生成的随机时间间隔 即random()%x
```
可对bridge进行不同测试

#### 4. 测试elevator

```bash
./nachos -i
```

切换算法方法：

所有宏全部注释掉时默认为一个无限容量的电梯

可在Elevator.h文件中修改宏定义
```c++
#define BOUNDED_ONE_ELEVATOR	//一个有限容量的电梯
```
在Elevator.h文件中可以修改对应的测试参数
```c++
#define OPEN_AND_CLOSE_DOOR     20		//电梯开关门的时间
#define RIDER_ENTER_OUT         10		//一个乘客进出电梯的时间
#define ELEVATOR_MOVE_ONE_FLOOR 40		//电梯移动一层楼的时间
#define ELEVATOR_CAPACITY		5		//电梯容量
```
在threadtest.cc文件中可以修改对应的测试参数
```c++
int num_floors = 5;						//楼层数
int total_riders = 50;					//生成的总乘客数
int E_random_come_time = 5;				//乘客生成的随机时间间隔 即random()%x
```
可对bridge进行不同测试


### 2018/4/16 更新
开始做实验三

### 2018/4/17 更新
实现eventbarrier并进行了测试

### 2018/4/23更新
实现alarm并测试

### 2018/4/27更新
实现bridge的先来先服务算法及同方向优化算法并进行了测试

### 2018/5/1更新
使用instance单例对alarm及bridge进行了重构

### 2018/5/6更新
实现并测试了bridge的基本红绿灯算法以及动态调度的红绿灯算法

### 2018/5/19更新
实现并测试了Elevator的使用SCAN算法的单个无限容量电梯和单个有限容量电梯的调度策略

