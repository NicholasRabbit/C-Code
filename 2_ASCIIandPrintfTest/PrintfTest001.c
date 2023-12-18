# include<stdio.h>


/*
 * 1,输出控制符范例。
 * */
int main(void){
	int i = 10;
	//一，输出控制符
	
	/* 
	 * 1,%d表示把i以10进制的形式输出;
	 *   %u: 输出无符号的int类型数,对应的是有符号的%d
	 *
	 * 2,%x,%X表示以16进制输出，这俩意思一样,一般都用大写，好区分;
	 *
	 * 3,%f表示单浮点精度float;
	 *   %lf表示双浮点精度double
	 *   但是对于prinf()函数来说没有区别，printf()会自动把float向上转型为double输出。
	 *   对于scanf()有区别，具体见本目录下: DoubleFloatAndPrintfScanf.c内解释。
	 *
	 * 4,%ld: signed long (long decimal缩写，默认是有符号的)
	 *   %lu: unsigned lon 4,%ld: signed long (long unsigned缩写)
	 *
	 *
	 * */
	printf("%d\n",i);   //%d默认打印有符号的int类型(signed  integer)
	printf("%X\n",i);	//10用16进制表示就是a,即9后面就是a。

	int j = 15;
	printf("%X\n",j);

	float age = 12.9;
	printf("age = %f\n",age); //这行和下行都是输出6位精度，待研究。printf()函数把单浮点的自动向上转型了。

	double money = 82.35;
	printf("money = %lf\n",money);

	long k = 0xfffffff; //32个1,是int的最大数，在int范围里表示-1
	printf("signed long = %ld\n",k);

	//二，long输出控制符。
	//这里写不写unsigned关键字都可以，输出的时候使用"%lu"就可以打印无符号的数。
	//unsigned的作用仅表示声明了一个无符号的整数变量，打印可以打印成有符号或无符号的。
	//本质上m的底层表示是一样的数，本例中都是64个1，范围不用表示的数字不一样。
	unsigned long m = 0xffffffffffffffff;
	printf("signed long(m) = %ld\n", m);   //signed有符号；表示-1
	printf("unsigned long(m) = %lu\n", m); //unsigned无符号：表示：2^32次方

	//三，%u
	int n = -1;
	printf("-1 unsigned = %u\n", n);

	return 0;
}

/*
 * 2,printf(..)函数的形参是可变长度的。
 * 可通过Linux命令行执行 man 3 printf 查看说明。
 * 这里的 3代表Section 3，具体见个人Linux笔记。
 * */
