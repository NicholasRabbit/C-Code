#include <stdio.h>

#define N 32

void ten_per_line(int a[])
{
	int i;
	for (i = 0; i < N; i++)
		printf("%6d%c", a[i], (i % 10 == 9 || i == N - 1) ? '\n' : ' ');
}

int main(int argc, char *argv[])
{
	int i, arr[N];
	for (i = 0; i < N; i++)
		i[arr] = i;  // To review arithmetic operation of pointers.
	
	ten_per_line(arr);

	return 0;

}
