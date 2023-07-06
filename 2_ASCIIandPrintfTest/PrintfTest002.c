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

	//%p : 这个输出控制符表示输出指针，即变量的地址，注意打印时在变量前加“&”表示取地址。
	int k = 25;
	printf("k's address==> %p\n",&k);

	return 0;
}
