#include<stdio.h>

/*
 * Arithmetic Operators:C语言算数运算符
 * 跟Java中一样用法
 * */
int main(void){

	int i = 10;
	int j = 33;

	int m = i + j;
	int n = i - j;
	int k = i * j;
	int h = i / j;

	//取余运算%只能用于整数类型，浮点类型使用会报错。
	int z = j % i;

	double d = 12.3 % 4.1; //报错

	printf("m=%d,n=%d,k=%d,h=%d,z=%d\n",m,n,k,h,z);

	printf("d=%d\n",d);



	return 0;
}
