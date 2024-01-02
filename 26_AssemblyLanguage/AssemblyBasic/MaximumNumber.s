
# Find the maximum number in an array

.section .data

data_items:
.long 1,23,45,65,236,97,397,0  #最后一个数是0，在循环的时候遇到0就终止，如果数组中有0这个值怎么办？

.section .text
.globl _start
_start:

# 寄存器说明:
# %edi: 数组下标
# %eax: 存储获取数组中的值
# %ebx: 存储最大值

#1, 因为声明数组后，数组中的元素在存储中是连续的，内存地址编号是连续的。
#   汇编器会把第一个元素的地址当作数组地址
#   data_items(,%edi,4)表达式进行 %edi * 4的运算，因为long的长度是4,
movl $0, %edi  #初始化下标为0
movl data_items(,%edi,4), %eax	 #这里表示从下标 %edi * 4开始获取4byte个数值存入%edx寄存器。

movl %eax, %ebx  # 由于是第一次比较，%eax肯定是最大值，直接放入%ebx

# 开始循环
start_loop:

	# 注意,cmpl这个函数求得是%eax(后) - %0(前)的结果，保存在eflags寄存器中的ZF位置上,这个寄存器不用声明
	# 如果计算结果是0，ZF就是0,je这个函数再判断ZF值，0=continue, 1=break
	# 函数名称是cmp不是comp !!!
	cmpl $0, %eax  #当%eax存储的是0的时候就终止循环
	je loop_exit   #je: jump if equal, loop_exit表示退出循环

    # 下面开始比较，因为第一个值已经比较了，所以下标后移一位, incl: increment long
	incl %edi 
    # 先把下个值放入寄存器%eax
	movl data_items(,%edi,4), %eax
	# 进行比较
	cmpl %ebx, %eax  
	jle start_loop  # if(%eax - %ebx) < 0,(jump less equal)则继续循环

	# 走到这里相当于else，即 %eax > %ebx,则把最大值存入%ebx
	movl %eax, %ebx
	jmp start_loop  # jmp表示无条件跳转

loop_exit:  # 退出循环，已找到最大值

movl $1, %eax   # 1 is the _exit() which is called by system to exit
int $0x80

