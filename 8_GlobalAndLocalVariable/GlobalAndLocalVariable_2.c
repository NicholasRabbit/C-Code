# include <stdio.h>

/*
 * 全局变量范例
 * 1,全局变量在使用时必须初始化赋值；
 * 跟Java中对象的实例变量同理，Java是系统默认给赋值，也是初始化赋值了。
 * 2,全局变量的赋值不能用变量表达式或方法的形式；
 * 原因：在C语言中，全局变量在编译时就要计算出来。而局部变量则不需要。
 * */

//错误写法1, 编译报警:implicit...
//int x = asin(1.0);  不可用方法或函数给全局变量赋值

//错误写法2, 报错：error:initialize element is not constant
//int a = 3;
//int b = a + 2; //错误写法,不可用表达式。

//正确写法
int m = 10;
int n = 20;
int x = 35;

int doSome(){
	
	//函数内有跟全局变量同名的局部变量则采用局部变量的值，没有的话才去找全局变量。例如:x。
	int m = 66;
	int n = 77;
	printf("doSome: m = %d,n = %d, x = %d \n",m,n,x);

	return 0;

}

int main(void){

	printf("main: m = %d,n = %d \n",m,n);
	doSome();

	return 0;

}

