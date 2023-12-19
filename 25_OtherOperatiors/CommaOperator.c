# include<stdio.h>


/*
 * comma operator
 *
 * */
int main(void){
	
	int a = 5;
	int b = (a++, b++);
	printf("b = %d\n", b);
	

	return 0;
}
