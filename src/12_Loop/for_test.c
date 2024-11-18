# include<stdio.h>

/*
 * for demo
 * It is as same as in Java.(Wrong statement.) 
 * The truth is that Java bears a striking resemblance to C 
 * because the former imitates most of the features of the latter.
 * */

int forLoop(){

	// The effect of 'for loop' is alomost as same as 'while loop' except 
	// minor differences of the variables in the condition.
	
	// 1. In 'for loop' empty condition is allowed and it yield an endless loop just
	// like 'while (true)'.
	/*for( ; ; ){
		printf("endless loop\n");
	}*/

	/*
	 * 2. The usual way of the declaration of a for loop.
	 *
	 * */
	int i;
	// 2.1 The braces of the satement of a for loop could be omitted when there is only one line of code.
	for (i = 0; i < 10; i++) 
		printf("%d\n", i);  
	

	// 2.2 If there is no statement, which is also allowed in C, 
	// a semicolon should be added at the end of the for loop
	for (i = 0; i < 10; i++)
		;  


	return 0;
}

//implements of factorial by using for loop.
int factorial(int n){

	


	int result = 1;
	// Declaring a variable and initiating it is new feature of C99 
	// so that a condition should be add in the command line to ensure the process of compiling. 
	// For example,  gcc -std=c99 ForTest.c -o ForTest.out
	// While this kind of syntax is derived from C++ and it is not recommended in C.
	for(int i = 1; i <= n; i++){
		result = result * i;
	}

	return result;
}


int main(void){

	forLoop();

	printf("calculate factorial result:");
	int n;
	scanf("%d",&n);

	int result = factorial(n);
	
	printf("factorial result==>%d\n",result);

	return 0;
}
