# include<stdio.h>

//coursework of 16.4
int main(void){
	
	int i = 0;
	unsigned int sum = 0;
	for(; i < 16; i++)
		sum = sum + 1U << i;

	printf("sum=%x\n", sum);

	return 0;
}
