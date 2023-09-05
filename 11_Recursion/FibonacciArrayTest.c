# include<stdio.h>



/*
 * Fibonacci array. Calculate the Nth number in the array.
 * */
int fibonacci(int n){

	//Base case.终止条件
	if(n == 0 || n == 1)
		return 1;

	int k = fibonacci(n -1) + fibonacci(n - 2);

	return k;
}

int main(void){

	int result = fibonacci(6);

	printf("the Nth number in Fibonacci array is %d\n",result);

	return 0;
}
