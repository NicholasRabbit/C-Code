# include<stdio.h>


/*
 * 1,输出控制符范例。
 * */
int main(void){
	
	//一，输出控制符
	
	/* 
	 *
	 *
	 *
	 * 4,%ld: signed long (long decimal缩写，默认是有符号的)
	 *   %lu: unsigned long (long unsigned缩写)
	 *
	 * 5,%p : 这个输出控制符表示输出指针，即变量的地址，注意打印时在变量前加“&”表示取地址。
	 *   See PrintfTes002.c
	 *
	 * 6,%c : to pirnt the representation of character of arguments.
	 * */

	/*
	 * 0, How to print '%' itself?
	 *	  Using "%%".
	 * */
	printf("%%\n");


	/*
	 * 1,%d: 'd' is short for "decimal". It means that to print the value 
	 *       in a decimal integer.
	 *   %u: to print unsigend decimal integer.
	 *   
	 *   %6d: print a decimal integer with at least 6 characters.
	 * */
	int i;
	i = -1;
	printf("%%d: %d\n",i);   
	printf("u: %u\n", i);
	printf("6d: %6d\n", i);

	/*
	 * 2,%x or %X: To print the hexadecimal value of a argument.
	 *   %.2x : That indicates that an integer should be printed in hexadecimal 
	 *          with at leat 2 digits. 
	 * */
	int j = 15;
	printf("j's hexadecimal value is %X\n", j);

	/*
	 * 3,%f: print as floating point.
	 *   %lf: print as double floating point.
	 *
	 *	 %3.0f: It means that a floating number is to be printed at least 
	 *	        three characters wide without no decimal point or fractinal digits.
	 *	        For example: 3.22 -> 3
	 *	 %6.2f: It means that a floating number is to be printed as least
	 *	        six characters wide with 1 digit after the decimal point.
	 *
	 *   N.B. The function "printf(...)" casts 'float' to 'double' by default,
	 *   but "scanf(...)" doesn't. See "DoubleFloatAndPrintfScanf.c".
	 * */
	float f0, f1, f2;
	f0 = 12.9;
	printf("f0 = %f\n", f0); 

	f1 = 20.0 / 6.0;
	f2 = 3.020304; 
	printf("f1 = %3.0f\n", f1);
	printf("f1 = %6.2f\n", f2);

	double d1 = 82.35;
	printf("d1 = %lf\n", d1);


	//二，long输出控制符。
	//这里写不写unsigned关键字都可以，输出的时候使用"%lu"就可以打印无符号的数。
	//unsigned的作用仅表示声明了一个无符号的整数变量，打印可以打印成有符号或无符号的。
	//本质上m的底层表示是一样的数，本例中都是64个1，范围不用表示的数字不一样。
	unsigned long m = 0xffffffffffffffff;
	printf("signed long(m) = %ld\n", m);   //signed有符号；表示-1
	printf("unsigned long(m) = %lu\n", m); //unsigned无符号：表示：2^32次方

	long k = 0xfffffff; //32个1,是int的最大数，在int范围里表示-1
	printf("signed long = %ld\n",k);

	//三，%u
	int n = -1;
	printf("-1 unsigned = %u\n", n);

	// 6, %c 
	char c = 98;
	printf("char==>%c\n", c);

	return 0;
}

/*
 * 2,printf(..)函数的形参是可变长度的。
 * 可通过Linux命令行执行 man 3 printf 查看说明。
 * 这里的 3代表Section 3，具体见个人Linux笔记。
 * */
