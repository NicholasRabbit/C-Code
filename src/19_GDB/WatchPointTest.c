# include<stdio.h>

/*
 * Input a number whose length is longer than the array's length.
 * Then use the "wathcpoint" to find out the bug.
 * */
int do_some(){

	int sum = 0, i = 0;
	char input[5];

	while(1){

		printf("Please input:");

 		scanf("%s",input);  //You don't have to write "&" before the variable.
		
		//The problem is that the "sum" must be intialised every loop.
		//这里每次都初始化sum，但是如果用户输入的数字越界怎么办？
		//结合这个问题使用(gdb)watchpoint来debug
		sum = 0;

		for(i = 0; input[i] != '\0'; i++){
			printf("input[%d]=%d\n",i,input[i]);
			sum = sum * 10 + input[i] - '0';  //A char will be transfered to an integer after it minus by '0'.
			printf("sum = %d\n",sum);
		}

		printf("input = %d\n", sum);

	}

	return sum;
}


int main(void){

	do_some();

	return 0;
}
