# include<stdio.h>


/*
 * shifting bits by the amount of -1 or 31
 * */
int main (void) 
{
	int i = 0x5;

	i = i >> -1;

	printf("i = 0x%.4x\n", i);

	int j = i << 31;
	printf("j = 0x%.4x\n", j);

	return 0;
}
