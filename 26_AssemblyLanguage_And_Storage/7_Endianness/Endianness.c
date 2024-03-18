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
 * (gdb)breakpoint 15  # set breakpoint at line 15
 * start
 * x/1tb &i  #print the memory as text in byte format.
 * 
 * The second approach:
 * To use 'readelf', 'objdump' and 'hexdump'.
 *
 * */

int main(void){
	
	int i = 3;

	return 0;
}
