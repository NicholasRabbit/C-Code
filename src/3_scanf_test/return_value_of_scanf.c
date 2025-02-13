#include <stdio.h>

/*
 * 'scanf()' will return the number of its inputs.
 * */
int main(void) 
{
	int i, j, ret;

	printf("Please inupt a number:");

	ret = scanf("%d", &i); 
	printf("return value of a number = %d\n",ret);

	printf("Please inupt two numbers:");

	ret = scanf("%d %d", &i, &j);
	printf("return value of two number = %d\n",ret);


	return 0;
}
