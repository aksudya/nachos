# nachos

## 操作系统课程实验

在每次实验做完后会将代码合并到master


[lab1分支](https://github.com/aksudya/nachos/tree/lab1)为实验一代码

[lab2分支](https://github.com/aksudya/nachos/tree/lab2)为实验二代码

此代码为code文件夹中的内容

因为存在符号链接的问题，直接下载后替换code文件夹中的内容可能会导致编译错误。

建议参考此代码对你的原文件直接进行修改

所有代码均在ubuntu 17.10上编译测试

## 实验一

使用方法：编译后cd到threads目录下使用
```bash
./nachos -m [T] [N]
```

例如
```bash
./nachos -m 10 10 
```
即为开10个线程，每个线程在链表中插入和删除10个元素

