# include<stdio.h>

/*
 * 研究各种类型的变量在内存中的存储形式
 * */

// A variable which is defined with const could not be modified.
const int A = 10;
int a = 20;
static int b = 30;
int c;

int main(void){

	static int a = 40;
	char b[] = "Hello C";
	register int c = 50;

	printf("Hello C %d\n", c);

	return 0;
}
