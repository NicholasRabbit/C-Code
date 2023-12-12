# include<stdio.h>

/*
 * Chapter 16.1
 * Coursework of mask.
 * Caculate how many 1s in a binary number.
 * */
int countOnes(int num){
	int count = 0;

	//利用位操作来统计1的个数，后期待研究……
	while(num){
		num &= (num - 1);
		count++;
	}

	return count;
	
}

int main(void){

	printf("Please input:");

	unsigned int num;
	scanf("%d", &num);
	
	int count = countOnes(num);
	printf("The number of 1 in %d is %d.\n", num, count);

	return 0;
}

