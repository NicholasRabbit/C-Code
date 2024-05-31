#### 1, 汇编寄存器含义

Unix中汇编使用的是AT&T的语法，还有 intel语法。

register:  寄存器

```txt
x86的通用寄存器有eax、ebx、ecx、edx、edi、esi。这些寄存器在大多数指令中是可以任意选用的，比如movl指令可以把一个立即数传送到eax中，也可传送到ebx中。但也有一些指令规定只能用其中某个寄存器做某种用途，例如除法指令idivl要求被除数在eax寄存器中，edx寄存器必须是0，而除数可以在任意寄存器中，计算结果的商数保存在eax寄存器中（覆盖原来的被除数），余数保存在edx寄存器中。也就是说，通用寄存器对于某些特殊指令来说也不是通用的。

(AT&T语法下)x86的特殊寄存器有ebp、esp、eip、eflags。eip是程序计数器，eflags保存着计算过程中产生的标志位，其中包括第 3 节 “整数的加减运算”讲过的进位标志、溢出标志、零标志和负数标志，在intel的手册中这几个标志位分别称为CF、OF、ZF、SF。ebp和esp用于维护函数调用的栈帧，在第 1 节 “函数调用”详细讨论。
```

##### 1,  %eax

![1717122563960](E:/My Private Files/Computer/C-Code/note-images/1717122563960.png)

Each register is 4 bytes. `al` represents the least significant byte, `ah` represents the second least significant byte while `ax` represents the least significant two bytes.

For `%ecx` and `%edx`, the representation are `cl/ch/cx` and `dl/dh/dx`,  respectively.

