#include <stdio.h>

void fizzbuzz();


int main(int argc, char *argv[])
{
	fizzbuzz();
	return 0;
}

void fizzbuzz() {
	int i;
	for (i = 1; i <= 100; i++) {
		// The condition to test the multiples of 3 and 5 should be the first 
		// branch. or it will never be executed. 
		if ((i % 3 == 0) && (i % 5 == 0))
			printf("Number: %d, FizzBuzz\n", i);
		else if (i % 5 == 0) 
			printf("Number: %d, Buzz\n", i);
		else if (i % 3 == 0)
			printf("Number: %d, Fizz\n", i);
	}

}
