#include <stdio.h>

int binary_search2(int x, int v[], int n);


int main(int argc, char *argv[])
{
	int v[5] = {1, 3, 5, 7, 9};
	int i = binary_search2(3, v, 5);
	printf("The index is %d\n", i);

	return 0;

}

int binary_search2(int x, int v[], int n)
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	/*
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else 
			return mid;

	} */



	return -1;
}
