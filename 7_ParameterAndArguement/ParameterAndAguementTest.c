# include<stdio.h>

/*
 * 形参和实参研究。
 * 
 * C语言中这两个概念和Java中的定义一样。
 * 函数声明或者定义时，定义形参及数量。
 * 调用函数时传入实参。
 * 
 * 注意：定义变量时相同变量可以一起声明，但是定义形参是不可以。
 * 例：int a,b; 正确。int foo(int a,b)错误。
 * C语言是一种设计优美的语言，这样的例外很少，有其道理，后期待研究。
 *
 *
 * */

/* 此种形参写法报错：b未指定类型。
int foo(int a,b){
	printf("foo");
	return 0;
}
*/

//正确写法
int foo(int a,int b){
	printf("a + b = %d \n", a + b);
	return 0;
}


int main(void){
	foo(10,12);
	return 0;
}
