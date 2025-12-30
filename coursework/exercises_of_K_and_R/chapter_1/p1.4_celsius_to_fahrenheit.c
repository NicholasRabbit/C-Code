# include<stdio.h>

/*
 * Converting degree celsius to fahrenheit.
 *
 * The orginal mathematical function is:
 *
 * fahr = celsius * 9.0/5.0 + 32.0
 *
 * */
int main(void) 
{
	float fahr, celsius;

	int lower, upper, step;
	lower = 0;
	upper = 100;
	step = 3;

	fahr = lower;

	printf("cel fahr\n");
	while (celsius <= upper) {
		fahr = celsius * (9.0 / 5.0) + 32.0;
		printf("%3.0f %6.2f\n", celsius, fahr);
		celsius += step;
	}

	return 0;
}
