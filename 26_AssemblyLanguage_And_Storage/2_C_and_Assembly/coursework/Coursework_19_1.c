# include<stdio.h>

/*
 * Coursework 1.
 * 使用Old style C的风格写代码。
 * Deliberately write wrong arguments.
 * */

int foo();

int bar();


int main(void){
	
	foo(2,3,4);

	return 0;

}


int foo(int a, int b)
{
	return bar(a);
}


int bar(int c, int d)
{
	int e = c + d;
	return e;
}

