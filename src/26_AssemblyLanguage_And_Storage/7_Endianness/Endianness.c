# include<stdio.h>

/*
 * Coursework: 19.4
 *
 * Detecting endiannes in a C programme.
 *
 * The fisrt approach:
 * Commands:
 * gcc -Wall -g Endianness.c -o Test.out
 * gdb Test.out
 * (gdb)breakpoint 25  # set breakpoint at line 25
 * start
 * x/1tb &i  #print the memory as text in byte format.
 * 
 * The second approach:
 * To use 'readelf', 'objdump' and 'hexdump'.
 *
 *
 * */

//使用第二种方法，可以看到全局变量的存储位置，个人得到结果是在这个操作系统里，是按小端little endian存储的。
int i = 5;  //A global variable could be found in the result of "readelf..."
int main(void){
	
	int i = 3;

	return 0;
}
