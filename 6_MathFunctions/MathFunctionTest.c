# include <math.h>
# include <stdio.h>

/*
 * C语言的常用数学函数库范例
 * 1，要引入<stdio.h>
 * 2, 注意使用数学函数时编译命令最后加 -lm,否则报错。
 *   gcc -Wall MathFunctionTest.c -o M.out -lm
 *   也可以不写其参数,默认生成a.out
 *   gcc MathFuntionTet.c -lm
 * 3,ln 函数在C语言中写作log。
 * */
int main(void){

	double pi = 3.1416;
	//使用数学函数时，参数要用括号括起来，跟数学中的用法不一样，程序中调用的是函数，括号中是传的参数。
	printf("sin(pi/2) = %f \n ln(1) = %f \n",sin(pi/2),log(1.0));
	return 0;


}
