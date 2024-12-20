#include<stdio.h>

/*
 * 1,C语言中的逻辑运算符 & 是取地址的，&&是逻辑与，其它与java一样。
 * 2,没有类似于Java中的布尔类型，C语言用0表示"否"，1或其它正数表示“是”
 * 3,逻辑运算符有执行顺序，&&优先于||，没必要刻意记住，用小括号表示即可。
 * */
int main(void){

	int i = 5;
	int j = 10;
	int b;

	/*一，短路或“||”, C语言中"|"，是位运算符，注意和Java区分
	 *短路或用法范例，跟java中一样，如果前面条件为真，后面的就不执行了。
	 *短路与"&&"用法同理。
	 * */
	//注意，这里j=23不是逻辑表达式也不报错，因为在C语言中0以外的数都被当作true来对待，
	//注意和Java语法区分。
	b = (i < j) || (j = 23); 
	
	//上面 i < j 为真，则短路或后面的就不执行了。
	printf("b=%d,j=%d\n",b,j); //b=1,表示true,j=10,说明后面的语句没有执行。
	
	/*二，短路与“&&”，C语言中"|"是位运算符
	 *
	 * */
	int x = 2;
	int y = 5;
	int z;
	z = (x < y) && (y = 17);  //&&短路与运算时，前面 x < y为真，后面也要判断，前面为假，后面就没必要判断了。跟java一样。
	printf("z=%d,y=%d\n",x,y);

	return 0;

}

