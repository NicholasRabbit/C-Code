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

	//浮点数不适合用"=="比较,因为"=="表示的是绝对相等，而浮点数并不是精确的
	double dnum = 20.0;
	double num = dnum  / 7.0;
	
	if( num * 7.0 == dnum )		
		printf("equals\n");  //改dnum为不同的double类型的值，结果有可能相等，也可能不等。
	else 
		printf("unequals\n");

	return 0;
}
