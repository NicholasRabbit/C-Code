# include<stdio.h>


//int power(int m, int n);
power(int m, int n);  // The return type can be omitted when it is integer.
power_2(m, n); // The date type of parameters can alos be omitted if they are integers.

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < 10; i++)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));

	return 0;

}

int power(int base, int n)
{
	int i, p;

	p = 1;
	for(i = 1; i <= n; i++)
		p = p * base;

	return p;
}

