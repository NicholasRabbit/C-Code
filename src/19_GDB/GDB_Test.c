# include<stdio.h>

/*
 * GDB: GNU symbolic debugger.
 * To debug by using GDB.
 * */

int add_range(int begin, int end){
	
	int i,sum;
	//sum = 0;  //I didn't intialise the local variable deliberately in order to debug.
	for (i = begin; i <= end; i++)
		sum = sum * i;

	return sum;

}

int main(void){

	int result[10];

	result[0] = add_range(1,10);
	printf("result[0] = %d\n", result[0]);
	
	result[1] = add_range(1,100);
	printf("result[1] = %d\n", result[1]);


	return 0;

}
