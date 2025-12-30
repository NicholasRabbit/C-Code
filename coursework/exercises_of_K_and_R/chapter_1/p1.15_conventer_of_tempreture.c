#include <stdio.h>


int fahrenheit_to_celsius();

int main(void) 
{
	fahrenheit_to_celsius();
	return 0;
}


int fahrenheit_to_celsius()
{
	int fahrenheit, celsius;

	int lower, upper, step;
	lower = 0;
	upper = 300;
	step = 20;

	printf("C   F\n");
	fahrenheit = lower;
	while (fahrenheit < upper) {
		celsius = 5 * (fahrenheit - 32) / 9;
		printf("%d  %d\n",  celsius, fahrenheit);
		fahrenheit += step;
	}

	return 0;
}
