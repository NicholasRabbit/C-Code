#include<stdio.h>
/*
 *Unary Operator : 自运算符。
 * */
int main(void){
	

	
	//1,++ 用法范例
	//跟Java一样，i++，++在后面的话也是先赋值给j，然后i再自加1
	//因此打印结果是j=10,i=11
	int i = 10;
	int j = i++;
	printf("j=%d,i=%d\n",j,i);

	//++m, ++在前面则是先自加1再赋值
	int m = 6;
	int n = ++m;
	printf("m=%d,n=%d\n",m,n);

	//2,--用法同理
	

	//3，- ：负数
	int positiveNum = 25;
	int negativeNum = - positiveNum;
	printf("negativeNum=%d\n",negativeNum);

	//4，! ：取反
	int b = (1 > 0);
	int c = !b;
	printf("b=%d,c=%d\n",b,c);

	//5, & : 取地址
	int u = 23;
	printf("u's address==>%p\n",&u);

	return 0;
}
