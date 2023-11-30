# include<stdio.h>

/*
 * Practise some orders of gdb such as berakpoints, display, info and so on.
 * Refer to my personal note about how to use them.
 * */

int do_some(){

	int sum = 0, i = 0;
	while(1){

		char input[5];

		scanf("%s",input);  //You don't have to write "&" before the variable.
		
		for(i = 0; input[i] != '\0'; i++){
			sum = sum * 10 + input[i] - '0';  //A char will be transfered to an integer after it is minus by '0'.
		}

		printf("input: %d\n" + sum);

	}

	return sum;
}


int main(void){

	do_some();

	return 0;
}
