# include<stdio.h>



int main(void){

	/*
	 * 位运算:
	 * 移位后数字的符号问题？
	 *
	 * 负数向右移位后前面补0还是1？
	 * 由于计算机底层的数字表示机制问题，正数移位后，前面直接补0不会产生错误。
	 * 但是负数是补0还是1是实现方式决定的,即Implementation defined。
	 * 分两种情况：
	 * 1，unsigned无符号数的移位，直接移动后前面补0；
	 * 2，signed有符号数移位，则是移位后由编译器再补充原来的符号，即高位补1了。
	 *
	 * 提示：做位运算的时候尽量适用unsigned，避免不必要的麻烦。
	 * 
	 * 本例中就是负数移位。
	 * */
	int i = 0xcffffff3;  //在int范围内，这个是负数：-80530638 (1100 1111 ... 1111 0011)
	printf("i = %d\n",i); 
	
	//直接用数值移位和使用变量移位结果不同

	//这个结果就是直接移位，前面补0，显然是printf(...)函数中直接操作数值的话是当成无符号unsigned数来处理的，没有考虑正负数表示的问题。
	printf("%x\n", 0xcffffff3 >> 2);  //33fffffc
	printf("%d\n", 0xcffffff3 >> 2);  

	printf("%x\n", i >> 2);  //f3fffffc, 这个结果就是高位补1，还是保持原来的负数，移位就是等同于和2运算，原来的符号不要变。
	printf("%d\n", i >> 2);  

	return 0;
}
