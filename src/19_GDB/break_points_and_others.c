# include<stdio.h>

/*
 * Practise some orders of gdb such as berakpoints, display, info and so on.
 * Refer to my personal note about how to use them.
 *
 * (gdb)break, display etc.
 * */

int sum_of_numbers(){

	int sum = 0, i = 0;
	char input[5];

	while(1){

		printf("Please input:");
 		scanf("%s",input);  //You don't have to write "&" before the variable.
		
		//The problem is that the "sum" must be intialised every loop.
		sum = 0;

		for(i = 0; input[i] != '\0'; i++){
			sum = sum * 10 + input[i] - '0';  //A char will be transfered to an integer after it minus by '0'.
		}

		printf("input = %d\n", sum);

	}

	return sum;
}


int main(void){

	sum_of_numbers();

	return 0;
}
