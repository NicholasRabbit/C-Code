# include<stdio.h>

/*
 * C中声明无符号和有符号的类型。
 * unsigned: 无符号
 * signed: 有符号
 * 默认不写都是有符号的signed
 * */

int main(void){
	
	int bin_num = 0b11;
	printf("bin_num = %d\n", bin_num);
	
	//0xffffffff = 2^32 - 1, int类型最大数，在int范围内表示-1
	//(注意是2的32次方减去1，因为2^32表示的是所有数的总和，2^32 - 1才是最大整数, 跟256-1=255同理)
	int num = 0xffffffff;
	printf("num = %d\n", num);

	signed int signed_num = 0xffffffff;
	printf("max_int = %d\n", signed_num);
	
	unsigned long unsigned_num = 0xffffffff;
	printf("unsigned_num = %lu\n", unsigned_num);

	return 0;

}
