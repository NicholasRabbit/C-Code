# include<stdio.h>


/*
 * scanf()会忽略接收到的空白字符，例如"space, \t, \n"等。
 * 如果输出控制符里有这三个字符，那么控制台用户按这三个字符对应的按键也不管用，
 * scanf()会一直等直到收到一个非空字符才会结束执行过程。
 *
 * 例：本例中先输入12再按"\n"对应的Enter，scanf()还是等待，直到输入一个非空字符才会结束。
 *
 * */
int main(void){
	
	printf("input:");

	int i;
	scanf("%d\n",&i);

	printf("Your num is:%d\n", i);

	return 0;
}
