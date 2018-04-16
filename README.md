# nachos

## 操作系统课程实验

实验二代码

此处版本包括实验二附加题

[不包括附加题的版本](https://github.com/aksudya/nachos/tree/a062b3aa5994e5e0ccb91331e23af3ff3ebdcfe4)

使用方法：编译后cd到threads目录下使用

#### 1. Dllist实现的无限缓存的生产者消费者模型

```bash
./nachos -rs [random seed] -m [producersnum] [consumersnum]
```

例如
```bash
./nachos -rs 5 -m 10 10 
```
即为以5为种子进行随机中断，10个生产者进程，10个消费者进程

#### 2. Table实现的生产者消费者模型

```bash
./nachos -rs [random seed] -a [producersnum] [consumersnum]
```

例如
```bash
./nachos -rs 5 -a 10 10 
```
即为以5为种子进行随机中断，10个生产者进程，10个消费者进程


#### 3. Buffer实现的有限缓存的生产者消费者模型

```bash
./nachos -rs [random seed] -b [producersnum] [consumersnum]
```

例如
```bash
./nachos -rs 5 -b 10 10 
```
即为以5为种子进行随机中断，10个生产者进程，10个消费者进程


#### 4. 实现带优先级的进程规划器（附加题）

```bash
./nachos -i
```
根据题目要求，开了两个生产者进程，一个消费者进程，生产并消费10个字节
可在threadtest5()函数中更改进程优先级，1为一般优先级，0为优先进程。

### 2018/3/24 更新

完成实验二第一部分：使用thread:sleep实现互斥并修改dlllist.cc进行了测试

### 2018/3/27 更新
完成实验二第一部分的使用信号量实现互斥;以及第二部分实现table

并使用dllist建立了一个无限缓存的生产者消费者模型进行了测试

### 2018/3/28 更新
完成实验二第三部分使用Buffer实现有限缓存的生产者消费者模型并进行了测试

### 2018/3/31 更新
完成实验二附加题部分，实现带优先级的进程规划器并使用生产者消费者模型进行了测试
