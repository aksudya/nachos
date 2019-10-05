# nachos

## 操作系统课程实验

此处为实验三代码
=======
[lab1分支](https://github.com/aksudya/nachos/tree/lab1)为实验一代码

[lab2分支](https://github.com/aksudya/nachos/tree/lab2)为实验二代码

[lab3_beta分支](https://github.com/aksudya/nachos/tree/lab3_beta)为完整版实验三代码

此代码为code文件夹中的内容

因为存在符号链接的问题，直接下载后替换code文件夹中的内容可能会导致编译错误。

建议参考此代码对你的原文件直接进行修改

所有代码均在ubuntu 18.04上编译测试

**在每次实验做完后会将代码合并到master**

**要查看其它实验请切换分支或点击上面的链接查看**

**实验三已合并**

**如果有其他问题或者需要详细实验报告的可以邮件联系我**

- - - - - - -

实验三代码</br>
lab3_beta分支处代码实验三已更新完毕</br>
lab3分支处代码为另外一种电梯调度算法,仅实现了单个容量有限的电梯,没实现多个电梯</br>

### 两种算法区别如下:

#### lab3_beta算法:
	电梯获取当前方向要去的最高(或最低)楼层,然后在上升(或下降)过程中检测当前楼层是否有请求,若有请求则停下。

#### lab3算法:
	电梯实时(每上升或下降一层)检测并计算下一个要去的楼层,然后向那个楼层移动。

对于单个电梯,两种算法的运行效果相同,但是对于多个电梯,lab3分支所使用的算法不好实现运行也不直观,故采用lab3_beta所使用的算法

------

使用方法：编译后cd到threads目录下使用

### 1. 测试eventbarrier

```bash
./nachos -e
```
### 2. 测试alarm

```bash
./nachos -g
```
### 3. 测试bridge

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

### 4. 测试elevator

```bash
./nachos -i
```

切换算法方法：

选择你想要测试的算法并注释掉其他的宏定义即可

可在Elevator.h文件中修改宏定义选择运行模式
```c++
#define SINGLE_ELEVATOR
#define MULTIPLE_ELEVATOR				//选择单个或多个电梯

#define BOUNDED_ELEVATOR
#define UNBOUNDED_ELEVATOR				//选择电梯容量是否有限
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
int elevator_num=5;						//电梯个数(测试单个电梯时此参数无效)
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

### 2018/5/22更新
简化电梯的调度算法

### 2018/6/9更新
完成并测试多个电梯调度算法

### 2018/6/15更新
修改电梯调度算法的错误
