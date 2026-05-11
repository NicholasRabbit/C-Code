#include <stdio.h>

#define N 8

int buy_sell(int a[]);
int buy_sell2(int a[]);

int main(int argc, char *argv[])
{
	int a[N] = {3, 7, 2, 4, 8, 1, 10, 0};

	int profit = buy_sell(a);
	printf("Solution 1: %d\n", profit);

	profit = buy_sell2(a);
	printf("Solution 2: %d\n", profit);
	

	return 0;
}

// Solution 1.
int buy_sell(int a[]) 
{
	int i, j, min, profit;
	i = 0;
	min = a[0];
	profit = 0;
	for (j = i + 1; j < N; j++) {
		// Note that the index of the minimum price is always equal or less
		// than j, therefore, this "if(a[j] < min)" can write first before the second "if" below.
		// As a result, the programme won't compute "a[6] - a[7]", (10 - 0).
		if (a[j] < min)
			min = a[j];

		if (a[j] - min > profit) 
			profit = a[j] - min;
	}

	return profit;

}




// Solution 2.
int buy_sell2(int a[])
{

	int i, j, min, profit;
	min = a[0];  // The minimum price.
	profit = 0;
	for (i = 0, j = i + 1; j < N; j++, i++) {
		if (a[i] < min)
			min = a[i];
		if (a[j] - min > profit) 
			profit = a[j] - min;

	}
	
	return profit;

}
