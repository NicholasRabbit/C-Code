## GDB 

### 1, Some tutorials

 Prof. Norm Matloff's  [GDB tutorial](http://heather.cs.ucdavis.edu/~matloff/UnixAndC/CLanguage/Debug.html) .

[CSAPP Student Guide on GDB](http://csapp.cs.cmu.edu/public/students.html)



### 2, gdb debugging

Refer to [LinuxC](./C语言资料/Linux C编程一站式学习.pdf) Chapter 10.1

#### 1, Add `-g` to `gcc` 

```shell
gcc -g GDB_Test.c -o test.out
```

Note: the option `-g` is to bind the source code, but doesn't embedded the source code to the compiled file. Thus, the source code should not be removed when it is bound. 

#### 2,  gdb commands

##### 1) Debug Begins

```shell
gdb test.out
```

The interface of GDB will be shown up after entering this command. 

##### 2) help and repeat

```shell
$ gdb test.out
GNU gdb 6.8-debian
....
(gdb)   # 这里可以输入相关命令
(gdb) help # 查看帮助文件
(gdb) help files  # 查看files命令帮助
```

**repeat the last command **

```shell
（gdb） \<Enter\>  # repeat the last command
```

##### 3) list specified function or line

3.1) List lines

```shell
# List 10 lines of source code. If the second option is ommitted, it is 10 by default.
(gdb) list 10 / list 
# Keep on listing. 
(gdb) list  
# Or type "Enter"
(gdb) <Enter> 
# We can show 10 lines of code around a specific line after the above comands.
(gdb)list 15 # To show code from line 10 to 19.
```

如果修改源码的名字或者位置，再执行list命令就会报：No such file or directory 错误。

3.2) List functions

```shell
(gdb)list do_some  # list 10 lines around a function named "do_some"

# list the add method in stack.c when mulitple sources are compiled simultaneously.
# Or list 10 lines of code around the twelfth line in stack.c
# See c-code/src/31_Linked/1_linked_basic
(gdb)list stack.c:add or stack.c:12
```

3.3) To know more about `list` 

```shell
(gdb)help list
```

##### 4) start debugging

```shell
> gdb test.out 
(gdb) start 
(gdb) next / n / Enter # execute next line
```

**4.1 `run` restart debugging**

```shell
(gdb) run # Start it from the beginning when you miss something during debugging. 
```

##### 5) quit debugging

```c
(gdb) quit
```

##### 6) Enter into a function

```shell
# When a function is going to be executed, we can step into it. 
(gdb) step / s # 进入函数
```

###### 	 6.4.1 进入之后可查看栈帧：

```shell
(gdb) backtrace / bt  # 查看栈帧
```

######       6.4.2 可看到如下信息：

```shell
(gdb) backtrace
#0  add_range (begin=1, end=10) at GDB_Test.c:12
#1  0x000000000040056d in main () at GDB_Test.c:23
- 说明：add_range(..)是被main()函数调用的，传进的参数是：begin=1, end=10
```

######       6.4.3可以使用命令查看当前栈帧局部变量的值：

```shell
(gdb) info / i  locals  # 查看局部变量的值
```

######      6.4.4 也可以调出 #1号栈帧，进行查看

```shell
(gdb) frame /f 1  # 调出一号栈帧，查看局部变量
(gdb) info / i locals  # 进行查看
```

######     6.4.5 从当前函数返回，

本例中是返回了调用函数main，在 main里接着向下执行了。

```shell
(gdb) finish  # 从当前函数返回	
```

##### 7)  显示，改变某局部变量

例如上面可以看到由于sum没有初始化导致的错误，可以在step进入add_range()函数后，设置sum=0，来继续往下走验证结果是否正确。

```shell
(gdb) step # 首先进入add_range(..)函数
(gdb) set var sum=0  # 改变变量的值，继续往下走
(gdb) next / n # 继续往下走
```

也可以使用print / p 来修改变量的值，print还可以调用函数。

```shell
(gdb) print / p result[2] = 25  # 随意修改当前栈帧的变量
# 修改后会把值存储在一个编号序号的临时变量里如 $5 25
# 也可以调用函数，实际这里可以随意写个已有的函数如printf(..)
(gdb) print / p printf("%d\n",result[2])
$ 6 4  # 这里接受的是printf(..)函数的返回值。printf(..)函数返回值就是其打印的字符数。
```

##### 8)  display

进入函数后才能使用此命令，否则找不到该局部变量。

```shell
(gdb) info display # 查看已设置的显示点
(gdb) display sum  # 每次程序走一步就显示当前sum的值。可展示多个，执行多次命令即可。
(gdb) display sum2 # ...display the decimal value by default.

(gdb) display # 显示所有设置好的变量值

(gdb) undisplay  1 # 指定序号取消展示（序号在最左边展示）。
(gdb) disable diaplay 2 # 禁用显示点2
(gdb) enable display 2  # 启用显示点2

# display the hexadecimal value
(gdb) display/x sum
# display the binary value
(gdb) display/t sum
```

##### 9) breakpoints

- `break, info, disable, enable, delete`

  First of all, show the source code by `(gdb) list 10` and decide where to set a break point.

```shell
(gdb) break / b 15  # Set a break point in the fifteenth line.
(gdb) bread do_some # Pause at the first line of a function named "do_some"

(gdb) info / i breakpoints  # Show the infomation of breakpoints

(gdb) disable breakpoints 1 # disable a break point
(gdb) enable breakpoints 3 # enable one

(gdb) delete breakpoints 5 # delete a specific break point
(gdb) delete breakpoints  # delete all breakpoints
```

- `continue` executing until to the first break point.

```shell
(gdb) continue / c  # continue
```

- invoked by a specific break point

```shell
# When sum != 0 it will break here. Other operators like ==,<，> are valid.
(gdb) break 15 if sum != 0  
```

##### **10) watch**

观察点是是指当程序访问某一个存储单元时中断。跟断点作用相同，只是触发机制不同。
一般有观察点则不设置其它断点，防止干扰，也可以需要根据实际情况两者都设置。

```shell
(gdb) watch input[8]  # 设置当input[8]对应的存储空间变化时则暂停
					  # 设置好后，输入：(gdb)continute 执行
(gdb) info watchpoints #查看观察点 
```

##### **11) `print` and `x`**

```shell
 # print the decimal value of "sum" by default
(gdb) print / p sum 
# print the hexadecimal representation of a variable.
(gdb) print/x var1  # p/x
# print the binary numbers of a variable
(gdb) print/t var1  # p/t
(gdb) x/8b input # 打印出input变量内存储的内容，根据系统不同，有时展示16进制，例如x31,有时10进制。
 				 # 8：表示打印8组，b表示每个字节一组		 
```

注意：```x/10b```命令在使用```watchpoint```之后不起作用，使用```break```的时候管用。

gdb以二进制形式打印一个byte的值

```shell
(gdb)x/1tb &i  #i is a variable
```

- `x`: This is the command to examine memory.
- `/1`: This specifies the number of units to display. In this case, we're specifying 1 unit.
- `tb`: These are format specifiers. `t` specifies that the memory should be interpreted as text, and `b` specifies that the output should be in byte format.
- `&i`: This is the address of the variable `i`. The `&` operator gives the address of a variable.

#####   12) Run `gdb` only.

```shell
$root>gdb  # Only input "gdb" in CLI
(gdb)print 200*300*400*500  # call print.
```

##### 13) `disassemble` , `stepi` and `nexti`

 Disassemble a specified section of memory.

```shell
# By default, it disassemble the function which surrounds the PC(program counter) of 
# the selected frame.
(gdb)disassemble  
```

To disassemble a specified function in a source code. Note that the address is interpreted as an expression, but not as a location as that in the `break` command. So if you want to disassemble a function name `pop` in `stack.c` , you should write as follows

```shell
(gdb)disassemble 'stack.c'::pop # Note there quotation marks around 'stack.c'.
```

After disassembling, we can move a single instruction, namely to process one line of assembly code.

```shell
(gdb)stepi  # Execute one instruction
(gdb)stepi 3 # Execute 4 instructions
# It is like 'stepi', but proceeds through different function calls without stopping.
(gdb)nexti 
```



#### 3, gdb调试时scanf(...)入参

scanf(...)仍然可以接收参数

```shell
(gdb) n   # call scanf()
123       # input variables
```

#### 4, segment fault and `gdb`

segmentation_fault.c (see this code in `c-code/src/19_GDB`)  

```c
# include<stdio.h>
int main(void){	
	int i = 0;
    //segmentatioin falut, The '&' should be added before tha variable. Error occurs here.
	scanf("%d",i);  
	return 0;
}
```

`gdb` can help us to locate where an error, such as 'segment fault', happens when it is impossible to pinpoint it if an executable object is run. To illustrate, when the above is executed, there is only one message: Segmentation fault(cor dumped). It is implausible to where the error is from because in this case the error occurs in a system call. Whereas, we can run it in `gdb` without any breakpoints and use `bt(backtrace)` to find it. 

```shell
(gdb)run
# The "segmentation fault" occurs.
Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7a69341 in __GI__IO_vfscanf () from /lib64/libc.so.6
# Then we input 'bt(backtrace)' and find where it occurs in our source code.
(gdb)bt
#0  0x00007ffff7a69341 in __GI__IO_vfscanf () from /lib64/libc.so.6
#1  0x00007ffff7a790b9 in __isoc99_scanf () from /lib64/libc.so.6  
#2  0x00000000004005cf in main () at segmentation_fault.c:11
#######
# We can find that a system call named "vfscanf()" is called by "scanf()" in our code. 
# Subsequently, the error is located. 
```

#### 5, command-line arguments

If there are command-line arguments to input when we run an executable object. For instance, `test.out abc`. We can input these arguments in `gdb` as follows.

```shell
(gdb)r/run abc
```

N.B. If we apply `r`  more than once in the same debugging session, there is no need to input these arguments once more; they are the default arguments next time. 

See the chapter 4.3.2 in [Guide to Faster, Less Frustrating Debugging.](https://heather.cs.ucdavis.edu/matloff/public_html/UnixAndC/CLanguage/Debug.html) 

