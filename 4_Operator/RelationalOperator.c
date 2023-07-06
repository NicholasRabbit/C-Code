#include<stdio.h>

/*
 * Relational Operator : 关系运算符。
 * */
int main(void){
	
	int b,c,d,e,f;
	b = 10 < 3; //先比较后赋值
	c = 1 == 1;
	d = 5 <= 90;
	e = 3 >= 2;
	f = 12 != 13;
	printf("b=%d,c=%d,d=%d,e=%d,f=%d\n",b,c,d,e,f); //输出：b=0/1, C语言中0表示fasle,1表示true。

	return 0;
}
