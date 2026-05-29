#include <stdio.h>

int binary_search(int x, int v[], int n);
int binary_search2(int x, int v[], int n);


int main(int argc, char *argv[])
{
	int v[6] = {1, 3, 5, 7, 9, 11};
	int i = binary_search(3, v, 6);
	printf("1. The index is %d\n", i);
	i = binary_search2(3, v, 6);
	printf("2. The index is %d\n", i);



	return 0;

}

int binary_search(int x, int v[], int n)
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low < high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else 
			return mid;

	}



	return -1;
}


// One test in the loop.
int binary_search2(int x, int v[], int n)
{
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;

	}

	return (x == v[mid]) ? mid : -1;

}
