# include<stdio.h>

/*
 *for代码范例
 * */
int main(void){

	//1,跟if一样，不加大括号默认只包括一行
	int i;
	
	//for(int i = 0; i < 5; i++) 
	//这种写法下，i就只属于for循环的内部变量了，循环结束，内存就会被释放。
	//c99标准的C语言才可以在括号内声明变量，现在编译器使用的是C89标准。
	//编译时在gcc命令后加: -std=c99
	for(i = 0; i < 5; i++)
		printf("for loop\n");

	printf("the second line\n");

	//2,求1~100的和
	int j;
	int sum = 0;
	for(j = 0; j <= 100; j++){
		sum += j;
	}
	printf("sum = %d\n",sum);

	//3,求100内所有奇数的和
	int m;
	int sum2 = 0;
	for(m = 1; m < 100; m += 2){ //奇数求和是+=2
		sum2 += m;
	}
	printf("奇数和 = %d \n",sum2);

	
	
	return 0;
}
