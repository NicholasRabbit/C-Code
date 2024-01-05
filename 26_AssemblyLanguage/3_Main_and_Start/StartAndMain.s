
# Chapter 19.2# Chapter 19.2# Chapter 19.2
# 研究汇编中"_start"指令和main函数的关系
# C语言代码中main函数执行时，实际也是由编译器gcc默认给链接了crt1.o的目标文件，此文件中有"_start"命令。
# 因此用gcc替代ld命令，生成可执行文件的话会报错，因为本代码里已经有一个"_start"了。

# as Test.s -o Test.o
# gcc Test.o -o Test.out  #这里报错, multiple definition of '_start'

.section .data #.data段下面保存数据，类似于声明变量赋值。

.section .text #.text段保存代码，是只读且能执行的。下面的指令都属于.text段的

.globl _start

# eax,ebx都是CPU中的寄存器(register)，详见17.2

_start:
movl $1, %eax # mov：移动命令, l是long,这里表示把数值1保存到eax寄存器


movl $4, %ebx


#A segmentatioin error would occur if the following code were commented out.
int $0x80  # int: interupt,中断命令,指示CPU从用户模式跳转到特权模式从而去执行内核程序。参考：17.4:MMU

