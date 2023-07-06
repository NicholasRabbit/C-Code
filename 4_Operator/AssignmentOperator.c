#include<stdio.h>

/*
 *Assignment Operators: 赋值运算符。
 * */
int main(void){

	int i = 10;
	int k = 3;
	int l = 35;
	int m = 13;
	int n = 27;
	int x = 7;

	//注意：进行 +=这些运算时，原来的变量要初始话。
	int j = i;
	k += i;
	l -= i;
	m *= i;
	n /= i;
	x %= i;
	printf("j=%d,k=%d,l=%d,m=%d,n=%d,x=%d\n",j,k,l,m,n,x);


	return 0;
}
