### 1, gcc commands

##### 1.1) Basic Commands

```shell
gcc  Hello.c : 编译Hello.c，默认输出a.out
gcc  Test.c  -o  Test : Linux环境下指定生成名称为Test的文件，无后缀。Windows下生成Test.exe(Linux下无后缀,无影响)

-o 选项表示自定义生成的名称，不一定是生成xxx.o后缀的文件才用的，生成.s, .c, .out, .o都可以用
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

5, Optimising

```shell
#The first captitalised O stands for "optimise".
gcc -O test.c -o test.out 
```

6, Generate Assembly Code in a x86-64 machine that is compatible with any IA32 machine. Sometimes it is NOT necessary to add `-O1` to the command so that generated assembly code is easy to understand. 

```shell
# O1: capital "O" which indicates that the gcc compiler generates the code 
# at O1(optimise 1) level. The option "-o" and "O1" are optional.
gcc -O1 -S -m32 code.c  -o code_32.s 
```

Generate assembly code in a x86-64 machine that is compatible with any IA64 machine. As a matter of fact,  it is the default operation. 

```shell
gcc -O1 -S -m64 code.c -o code_64.s
```



##### 1.2) Preprocessing and so forth

The following commands illustrate the whole process from a source to an executable object. 

```shell
# 1, preprocessing
gcc -E hello.c / cpp hello.c  # List preprocessed code on CLI
# Or generate a preprocessed file with ".i" as its suffix.
gcc -E hello.c -o hello.i / cpp hello.c -o hello.i 

# 2, hello.s (assembly)
gcc -S hello.i  # automatically create an assembly file named helo.s
# Or
gcc -S hello.c # skip the preprocess

# 3, hello.o
gcc -c hello.s -o hello.o  # relocatable object programs
# Or
as hello.s -o hello.o
# Or
gcc -c hello.c  # automatically generate a file named hello.o from hello.c 

# 4, hello  
gcc hello.o -o hello # executable object program
```



##### 1.3) 链接选项

使用math.h库的时候需要在gcc命令后加`-lm`表示使用libm.so这个库，

##### 1.4) 查看编译过程

可查看引用了哪些外部文件，进行了哪些链接等。因为编译成可执行文件不止是程序员写的代码，还需要引入其它库文件等。

```shell
gcc -v Test.c -o Test.out  
```

##### 1.5) Compile multiples files

```shell
gcc foo.c bar.c -o test.out
#OR
gcc -c foo.c # automatically generate foo.o
gcc -c bar.c
gcc foo.o bar.o -o test.out
```



#### 4, Assembly Commands

1）Basic

```shell
as test.s -o test.o  # 生成目标文件
ld test.o -o test.out #生成可执行文件
# execute
./test.out
echo $? #shell命令获取上一条命令的退出状态
```

**命令解释：**参考18.1 (One-stop Programming in Linux)

as表示使用汇编器(Assembler)把汇编中的助记符编译成机器指令，并生成目标文件。

ld表示把目标文件xxx.o链接成可执行文件。为什么要链接文件？一，链接是为了修改目标文件中的信息，对地址做重定位(跟CPU虚拟内存相关)；二，是为了把多个目标文件合并成一个可执行文件。

3）打印目标文件的全部字节

```shell
hexdump -C Test.o  # 显示的都是16进制
```

4）反汇编：目标文件，可执行文件都可以反编译。

```shell
objdump -d Test.o  # --disassemble is an alternative option. N.B. There are two hyphens.
objdump -d Test
```

#### 5, C & Assembly

1, 查看C编译后生成的汇编代码

```shell
# 第一种：
gcc -g Test.c -o Test.out
objdump -dS Test.out
objdump -dS test.out | less # combined with "less" to display the result.

# 第二种
gcc -S Test.c  #自动生成Test.s文件，然后vi编辑器打开即可查看
#后续生成可执行文件步骤
gcc -c Test.s -o Test.o  #生成目标文件
gcc Test.o -o Test.out   #生成可执行文件
```

> -d [--disassemble]
> Display the assembler mnemonics for the machine instructions from the input file.
>
> -S [--source]
> Display source code intermixed with disassembly, if possible. Implies `-d`

2, 汇编相关断点调试命令

gdb执行后使用以下命令

```shell
disassemble  function_name/address(optional)  #反汇编当前的函数，也可指定函数名或地址
si  #执行单条CPU指令调试，而step是单行代码调试，注意区别

#查看寄存器(registers)信息， 个人输入此命令后，64位CentOS系统的寄存器名称都是%rbp,不是%ebp
info registers  
#得到结果：
(gdb) info registers 
...
esp            0xbff1c3f4	0xbff1c3f4
####
x/20 %esp  #以上面结果为例，查看内存中从地址0xbff1c3f4开始的20个32位数的值
```

3，在`gdb`中表示寄存器时在名称前面要加个`$`，例如`p $esp`可以打印`esp`寄存器的值 

```shell
(gdb)p $esp
```

4,  List symbols from object files

```shell
nm test.out 
# or 
readelf -s test.out
```

Elaboration of the output

```shell
# command
nm /usr/lib64/crt1.o
# man nm : to see the full specification.
# U: undefined
# T: text
# D/d: The symbol is in the initialized data section.
# R/r: The symbol is in the read only data section.
# W/w : a weak object.
0000000000000000 D __data_start
0000000000000000 W data_start
0000000000000000 R _IO_stdin_used
                 U __libc_csu_fini
                 U __libc_csu_init
                 U __libc_start_main
                 U main
0000000000000000 T _start
```

- Combine C code and assembly code by a linker

  ```bash
  # 
  gcc -o p p1.c p2.c 
  ```

  

#### 6, ELF相关

```shell
readelf -a -W Test.o  #读取目标文件，显示相关编译信息等
readelf -a -W Test.out #读取可执行文件
# -W表示不自动换行打印结果，因为默认显示80个字符宽，超过就自动换行。可能是早期屏幕不够宽，但是有的结果换行了就不易阅读。
```

