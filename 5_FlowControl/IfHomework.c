# include<stdio.h>

/*
 * if homework:
 * Calculate the number of ones place or tens place of a given number.
 * */
int place(int number){

	// ones place
	int ones = number % 10;
	printf("ones: %d\n",ones);

	// tens place
	int tens = (number / 10) % 10;
	printf("tens: %d\n",tens);

	return 0;
}


int main(void){

	place(1234);

	return 0;
}
