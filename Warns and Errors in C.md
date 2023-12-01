#### 1,  Segmentation fault 

代码：19_GDB/BreakPointsAndOthers.c

报错：Program received signal SIGSEGV

原因： printf("input = %d\n" + sum);   写成加号"+"了。…………

#### 2, gdd warn

```txt
Missing separate debuginfos, use: debuginfo-install glibc-2.12-1.47.el6_2.9.i686 libgcc-4.4.6-3.el6.i686 libstdc++-4.4.6-3.el6.i68
```

Solution:

`debuginfo-install` is a command of `yum-utils`, so

1. `yum install yum-utils`
2. `debuginfo-install glibc`
3. if the warning's still there, edit `/etc/yum.repos.d/CentOS-Debuginfo.repo`, set `enabled=1`

