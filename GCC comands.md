### 1, gcc常用命令

##### 1.1) 基础命令

```shell
gcc  Hello.c : 编译Hello.c，默认输出a.out
gcc  Test.c  -o  Test : Linux环境下指定生成名称为Test的文件，无后缀。Windows下生成Test.exe(Linux下无后缀,无影响)
```

2, 执行编译的文件

```shell
./Hello  : Linux
Hello.exe : Windows2,执行编译的文件
```

3, 打印报警信息，报警信息不是报错，但建议每次都使用，可使程序更健壮。
```gcc -Wall Hello.c -o Hello```

4, C99语法加编译选项
  ```gcc -std=c99 ForTest.c -o ForTest.out```

##### 1.2) 预处理

查看预处理后的数据的命令

```shell
gcc -E Hello.c : 后面什么都不要加，因为还没开始编译
cpp Hello.c : 作用相同
```

下面的代码就是表示指示编译器进行预处理。

### 2, gdb的debug步骤

具体参照[LinuxC](./C语言资料/Linux C编程一站式学习.pdf) 章节10.1

#### 1, 生成可调试文件：

```shell
gcc -g GDB_Test.c -o test.out
```

注意：-g 选项的作用是在可执行文件中加入源码的信息，并非把源码文件全部嵌入到编译后的可执行文件里，所以生成之后，源码的名字和位置都不要动了，否则找不到。

#### 2,  gdb命令

##### 1) 使用gdb命令执行可调试文件

```shell
gdb test.out
```

然后CLI界面会出现gdb的命令界面：

##### 2) help命令

```shell
$ gdb test.out
GNU gdb 6.8-debian
Copyright (C) 2008 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i486-linux-gnu"...
(gdb)   # 这里可以输入相关命令
(gdb) help # 查看帮助文件
(gdb) help files  # 查看files命令帮助
```

**指重复上一条的命令**

```shell
（gdb） \<Enter\>  # 指重复上一条的命令。
```



##### 3) 查看源码：

```shell
(gdb) list 1 / list # 从第一行列出源码，或者不写1，一次默认列出10行（不包括注释），
(gdb) list  # 继续输入list，再回车则展示下面的10行
(gdb) <Enter> # 或者什么都不输直接Enter回车，默认展示后10行
```

如果修改源码的名字或者位置，再执行list命令就会报：No such file or directory 错误。

##### 4)  退出调试：

```shell
(gdb) quit
```

##### 5) 开始执行程序：

```shell
gdb test.out # 退出后需要重新启动
(gdb) start # 开始执行
(gdb) next / n / Enter # 执行下一行，或直接按回车Enter也可以，每次执行一步
```

**5.1 重新执行程序**

```shell
(gdb) run # 执行了部分程序后，从开头重新执行程序
```

##### 6) 进入某个函数

```shell
# 当执行到某个函数时可使用如下命令进入函数
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
(gdb) frame /f 1  # 调出一号栈帧
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
(gdb) print / p sum  #显示变量的值
(gdb) print / p result[2] = 25  # 随意修改当前栈帧的变量
# 修改后会把值存储在一个编号序号的临时变量里如 $5 25
# 也可以调用函数，实际这里可以随意写个已有的函数如printf(..)
(gdb) print / p printf("%d\n",result[2])
$ 6 4  # 这里接受的是printf(..)函数的返回值。printf(..)函数返回值就是其打印的字符数。
```

##### 8)  始终展示局部变量的值

进入函数后才能使用此命令，否则找不到该局部变量。

```shell
(gdb) display sum  # 每次程序走一步就显示当前sum的值。可展示多个，执行多次命令即可。
(gdb) display sum2 # ...

(gdb) undisplay  1 # 指定序号取消展示（序号在最左边展示）。
```

##### 9) 断点调试相关

- 设置断点 ，查看，删除，禁用断点

  首先得使用 ```(gdb) list 1```命令查看代码，选好行号。

```shell
(gdb) break / b 15  # 在15行设置断点,程序每次走到这里就会停

(gdb) info / i breakpoints  # 查看断点，执行后会有一个列表展示出来，注意观察相关信息

(gdb) disable breakpoints 1 # 禁用1号断点
(gdb) enable breakpoints 3 # 启用3号断点

(gdb) delete breakpoints 5 # 删除指定号码的断点
(gdb) delete breakpoints  # 不指定号码则删除所有断点
```

- 连续运行，不是一步步走，而是走到断点才停

```shell
(gdb) continue / c  # 连续运行
```

- 指定条件激活断点

```shell
(gdb) break 15 if sum != 0  # 当sum != 0时才打断，布尔表达式可以写==,<，>等。
```

**10) 设置观察点**

观察点是是指当程序访问某一个存储单元时中断。跟断点作用相同，只是触发机制不同。
一般有观察点则不设置其它断点，防止干扰，也可以需要根据实际情况两者都设置。

```shell
(gdb) watch input[8]  # 设置当input[8]对应的存储空间变化时则暂停
					  # 设置好后，输入：(gdb)continute 执行
(gdb) info watchpoints #查看观察点 
```

**11) 指定打印存储单元的内容**

```shell
(gdb) x/8b input # 打印出input变量内存储的内容，根据系统不同，有时展示16进制，例如x31,有时10进制。
 				 # 8：表示打印8组，b表示每个字节一组
```

注意：```x/10b```命令在使用```watchpoint```之后不起作用，使用```break```的时候管用。

#### 3, gdb调试时scanf(...)入参

scanf(...)仍然可以接收参数

```shell
(gdb) n   # 这里执行下一步的scanf()
123       #这里既可以输入参数
```



#### 4, Assembly汇编常用命令

基本：

```shell
as Test.c -o Test.o  # 生成目标文件
ld Test.o -o Test #生成可执行文件
```

ELF相关

```shell
readelf -a Test.o  #读取目标文件，显示相关编译信息等
readelf -a Test #粗去可执行文件
```

打印目标文件的全部字节

```shell
hexdump -C Test.o  # 显示的都是16进制
```

反编译：目标文件，可执行文件都可以反编译。

```shell
objdump -d Test.o
objdump -d Test
```

#### 5, C, 汇编相关命令

1, 查看C编译后生成的汇编代码

```shell
# 第一种：
gcc -g Test.c -o Test.out
objdump -dS Test.out
# 第二种
gcc -S Test.c  #自动生成Test.s文件，然后vi编辑器打开即可查看
```

2, 汇编相关断点调试命令

gdb执行后使用以下命令

```shell
disassemble  function_name/address(optional)  #反汇编当前的函数，也可指定函数名或地址
si  #执行单条CPU指令调试，而step是单行代码调试，注意区别

#查看寄存器(registers)信息， 个人输入此命令后，CentOS系统的寄存器名称都是%rbp,不是%ebp，原因待分析
info registers  
#得到结果：
(gdb) info registers 
...
esp            0xbff1c3f4	0xbff1c3f4
####
x/20 %esp  #以上面结果为例，查看内存中从地址0xbff1c3f4开始的20个32位数的值
```

