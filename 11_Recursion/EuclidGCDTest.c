# include<stdio.h>

/*
 * Implemmentation of Euclid greatest common divisor algorithm.
 * */

/*
 * if a/b = c ...0,then b is the GCD 
 * if a/b = c ...d,then 
 * b/d = e ... f
 * ...
 * x/y = z ... 0
 * y is the GCD
 *
 * */
int gcd(int num1,int num2){

	//设置num1为大值
	if(num1 < num2){
		int temp = 0;
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	//取余数
	int mod = num1 % num2;

	//Base case,终止条件
	if(mod == 0)
		return num2;

	//递归
	return gcd(num2,mod);

	
}

int main(void){

	printf("Please input two numbers which are seperated by a comma.==>\n");

	int i,j;

	scanf("%d,%d",&i,&j);

	int result = gcd(i,j);

	printf("GCD is %d \n",result);

	return 0;
}
