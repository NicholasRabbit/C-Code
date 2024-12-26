
# Chapter 18.1

# A simple assembly program which returns 4 in %ebx.
# 
# CLI commands:
# as assembly_test.s -o assembly_test.o
# ld assembly_test.o -o assembly_test.out 
# 
# Then execute the :
# ./assembly_test.out
# echo $? // to get the return value of the last programmme.


.section .data #.data段下面保存数据，类似于声明变量赋值。

.section .text #.text段保存代码，是只读且能执行的。下面的指令都属于.text段的

.globl _start

# eax,ebx都是CPU中的寄存器(register)，详见17.2

_start:

xorl %edx, %edx

movl $1, %eax # $1: it is an immidiate.  mov：to move an immidiate into a register. 'l' means 2 words(namely 4 bytes).


movl $4, %ebx


#A segmentatioin error would occur if the following code were commented out.
int $0x80  # int: interupt,中断命令,指示CPU从用户模式跳转到特权模式从而去执行内核程序。参考：17.4:MMU

