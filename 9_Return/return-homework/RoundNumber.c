# include<stdio.h>
# include<math.h>


/*
 * 四舍五入
 *
 * Write a programme which round the value of a number.
 *
 * Don't forget to use "-lm" at the end of gcc command when you want to use function from math.h
 * */

double roundNumber(double num){
	
	int i = floor(num);

	if(num - i < 0.5)
		return i;

	return ceil(num);
	
}


int main(void){
	
	printf("Please input a decimal and you'll get a round number:");
	double num;
	scanf("%lf",&num);
	
	double retValue = roundNumber(num);

	printf("retValue==>%lf \n",retValue);


	return 0;
}
