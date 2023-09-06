# include<stdio.h>



/*
 * Recursion
 * Fibonacci array. Calculate the Nth number in the array.
 * */
int fibonacci(int n){

	//Base case.终止条件
	if(n == 0 || n == 1)
		return 1;

	int k = fibonacci(n -1) + fibonacci(n - 2);

	return k;
}

//Implementation of Fibonacci array with for loop
int fibonacciFor(int n){
	if(n < 0)
		return 0;
	//number of index 0 is defined as the first one.
	if(n <= 1)
		return n;
	
	int fib = 1;
	int prev = 1;
	for(int i = 2; i <=n; i++){
		int temp = fib; 
		fib += prev;
		prev = temp;
	}

	return fib;

}

int main(void){

	//recursion
	int result = fibonacci(6);
	printf("the Nth number in Fibonacci array is %d\n",result);

	//for loop
	int resultFor = fibonacciFor(6);
	printf("for loop,the Nth number in Fibonacci array is %d\n",resultFor);


	return 0;
}
