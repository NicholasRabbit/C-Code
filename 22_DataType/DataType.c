# include<stdio.h>

int main(void){

	/*
	 * 虽然int类型范围是-2147483648~2147483647，
	 * 但是x86平台中C语言无法表示-2147483648，因为把这个数看作一个符号“-”和2147483648组成
	 * 而显然后者越界了。
	 *
	 * */
	printf("%d\n", -2147483648);  //报错：

	return 0;
}
