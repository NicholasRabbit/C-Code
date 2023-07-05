#include<stdio.h>

/*
 * printf()用法
 * 可以写多个输出控制符，每个输出控制符对应一个变量
 * */
int main(void){

	int i = 10;
	int j = 20;
	char c = 68;
	int m = 14;

	printf("%d\n%d\n%c\n%X\n",i,j,c,m);

	return 0;
}
