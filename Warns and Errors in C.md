#### 1,  Segmentation fault 

段错误

代码：19_GDB/BreakPointsAndOthers.c

报错：Program received signal SIGSEGV

原因： printf("input = %d\n" + sum);   写成加号"+"了。…………

**Segmentation fault 的具体分析**

参照: [Linux C编程一站式学习](./C语言资料/Linux C编程一站式学习.pdf) :  17.4

段错误我们已经遇到过很多次了，它是这样产生的：

1. 用户程序要访问的一个VA，经MMU检查无权访问。
2. MMU产生一个异常，CPU从用户模式切换到特权模式，跳转到内核代码中执行异常服务程序。
3. 内核把这个异常解释为段错误，把引发异常的进程终止掉。

#### 2, gdd warn

```txt
Missing separate debuginfos, use: debuginfo-install glibc-2.12-1.47.el6_2.9.i686 libgcc-4.4.6-3.el6.i686 libstdc++-4.4.6-3.el6.i68
```

Solution:

`debuginfo-install` is a command of `yum-utils`, so

1. `yum install yum-utils`
2. `debuginfo-install glibc`
3. if the warning's still there, edit `/etc/yum.repos.d/CentOS-Debuginfo.repo`, set `enabled=1`

#### 3,  error: multiple definition of `_start'

The difference between `as` and `gcc`.

See chapter 19.2  `main`函数和启动例程 

