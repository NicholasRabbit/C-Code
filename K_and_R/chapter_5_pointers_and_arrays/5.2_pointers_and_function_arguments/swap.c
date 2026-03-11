#include <stdio.h>


void swap(int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;

}


int main(int argc, char *argv[])
{
	int x, y;
	x = 1; 
	y = 2;
	printf("Before swapping: x = %x, y = %d\n", x, y);
	swap(&x, &y);
	printf("After swapping: x = %x, y = %d\n", x, y);


	return 0;
}
