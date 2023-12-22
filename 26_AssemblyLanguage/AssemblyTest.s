
# Chapter 18.1

# A simple assembly program which returns 4.
# 
# CLI commands:
# as test.s -o test.o
# ld test.o -o test
# 
# run:
# ./test
# echo$?


.section .data #.data段下面保存数据，类似于声明变量赋值。

.section .text #.text段保存代码，是只读且能执行的。下面的指令都属于.text段的

.globl _start

# eax,ebx都是CPU中的寄存器(register)，详见17.2

_start:
movl $1, %eax # mov：移动命令, l是long,这里表示把数值1保存到eax寄存器


movl $4, %ebx


#A segmentatioin error would occur if the following code were commented out.
int $0x80  # int: interupt,中断命令,指示CPU从用户模式跳转到特权模式从而去执行内核程序。参考：17.4:MMU

