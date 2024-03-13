# include<stdio.h>

/*
 * Sequence Point: 一个函数调用之前和结束之后的点称为Sequence Point，
 *				   一个表达式对变量的操作之前和结束之后也是各有一个Sequence Point
 *
 * Side Effect: 表达式会产生Side Effect，即副作用。
 *
 * 1,如果对一个变量，同一时间只有一个操作动作，则不会报错或产生undefined。
 * 如果同时有多个操作则会产生undefined.因为不知道从哪个Sequence Point后面获取结果。
 * 2,写程序时尽量避免多个操作无序进行，容易导致混乱。
 * 
 * */
int main(void){
	
	int a,b,c;
	a = 1;
	b = 2; 
	c = -5;
	// "||"运算符就是有序进行的，左边的执行完产生结果后再进行右边的判断。
	if(a > 0 || b > 0 || c > 0)
		printf("execute");


	//编译阶段 自运算"++"是同时进行的，产生了多个Sequence Point, 那么编译器就不知道a取那个结果了，最后产生undefined.
	int m = (m++) + (++m) + (m++);


	return 0;
}
