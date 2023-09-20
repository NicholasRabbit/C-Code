# include<stdio.h>

/*
 * 左值右值研究；
 * 结合++的运算演示
 * */

int main(void){

	int a = 1;
	a = a++ ++ + b; //此行报错:lvalue required as incremnt operand
	printf("i=%d\n",i);

	return 0;
}
