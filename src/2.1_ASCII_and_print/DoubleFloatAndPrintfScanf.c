# include<stdio.h>


/*
 * %f: 表示单浮点精度float
 * %lf: 表示双浮点精度double
 *
 * 1,printf()函数中这俩没有区别，因为printf()会自动把单浮点数float向上转型为double
 * 2,scanf()函数中有区别，%f表示接收float, %lf表式接收double.
 *
 * */

int main(void){

	printf("Please input a float number:");
	
	//以下的测试无法试出来，终端输入任何数都会被自动转型，后期待研究。

	float num1;
	scanf("%f",&num1);
	printf("Is it a float? num1=%f\n",num1);  //输出的还是double

	double num2;

	printf("Please input a double number:");
	scanf("%lf",&num2);
	printf("double? num2=%lf\n",num2);  
	

	return 0;

}
