# include<stdio.h>

/*
 * What is the realtionship between C and assembly language?
 *
 * Commands:
 * gcc -E Test.c -o Test.i // a preprocessed file(text)
 * gcc -S Test.c   // Compile C into assbmbly program named Test.s.
 * gcc -c Test.s   // Test.o
 * gcc Test.o -o Test // Test. It is an executable object programme.
 * 
 * */

int bar(int c, int d)
{
	int e = c + d;
	return e;
}

int foo(int a, int b)
{
	return bar(a, b);
}

int main(void){
	
	foo(2,3);

	return 0;

}
