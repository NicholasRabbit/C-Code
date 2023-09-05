# include<stdio.h>

/*
 * 用递归实现阶乘范例
 * 递归可以想象成一个方法调用另一个方法，递归类似于数学归纳法;
 * 数学归纳法有一个Base case和递推关系，只有这两个正确数学归纳才成立。
 * 同理，递归也需要一个Base Case做为终止递归的条件，而函数中的代码就是对应递推关系。
 *
 * */

int factorial(int n){
	//Base case,阶乘中最关键的一个条件,0! = 1
	if(n == 0)
		return 1;

	//为了方便理解，把表达式分开写
	int recursion = factorial(n -1);
	int result = n * recursion;
	return result;

	//简化写法
	//return n * factorial(n - 1);


}


int main(void){

	//由控制台输入数字
	printf("Please input a factrial number:\n");

	int num;
	scanf("%d",&num);

	int result = factorial(num);
	printf("factorial result:%d \n",result);


	return 0;


}
