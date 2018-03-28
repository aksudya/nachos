# nachos

## 操作系统课程实验

实验二代码

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

#### 2. Table实现的生产者消费者模型(目前还有点小问题）

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

### 2018/3/24 更新

完成实验二第一部分：使用thread:sleep实现互斥并修改dlllist.cc进行了测试

### 2018/3/27 更新
完成实验二第一部分的使用信号量实现互斥;以及第二部分实现table

并使用dllist建立了一个无限缓存的生产者消费者模型进行了测试

### 2018/3/28 更新
完成实验二第三部分使用Buffer实现有限缓存的生产者消费者模型并进行了测试
