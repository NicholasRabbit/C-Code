# include<stdio.h>


/*
 * comma operator
 *
 * */
int main(void){
	
	/*
	 * Excute from left to right and the last result is assigned to the variables.
	 * */
	int a = 5;
	int b = (a++, b++);
	printf("b = %d\n", b);
	

	return 0;
}
