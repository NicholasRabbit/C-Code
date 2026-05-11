#include <stdio.h>

#define N 8

int equilibrium_index(int arr[])
{
	int i, leftSum, sumTotal;
	leftSum = 0;
	sumTotal = 0;
	
	for (i = 0; i < N; i++)
		sumTotal += arr[i];

	printf("sumTotal is %d\n", sumTotal);

	for (i = 0; i < N; i++) {
		sumTotal -= arr[i];
		if (leftSum == sumTotal)
			printf("%d is an equilibrium index\n", i);
		leftSum += arr[i];
	}

	return i;

	
}


int main(int argc, char *argv[])
{
	int arr[N] = {-1, 3, -4, 5, 1, -6, 2, 1};
	equilibrium_index(arr);

	return 0;
}
