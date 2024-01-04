# include<stdio.h>

/*
 * 本代码仅用于gdb观察栈帧stack frame的入栈出战操作。
 * 只写两个方法，先从简单的开始理解。
 * */

int foo(int a, int b)
{
	int c = a + b;
	return c;
}

int main(void){
	
	foo(2,3);

	return 0;

}
