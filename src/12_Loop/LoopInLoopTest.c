# include<stdio.h>

/*
 * 嵌套循环
 * 打印99乘法表
 * */
int loop(int n){
	
	int i;
	for(i = 1; i <= n; i++){
		int j;
		for(j = 1; j <= i; j ++){
			printf("%d\t",i * j);
		}
		printf("\n");
	}

	return 0;
	

}

//to print a rhombus
int rhombus(int rows,char mark){
	//check if the num is odd.
	if(rows % 2 == 0){
		printf("the num must be odd.\n");
		return 0;
	}
	
	int num = (rows + 1) / 2;

	//first part
	int i;
	for(i = 1; i <= num; i++){
		//print blanks
		int j;
		for(j = 1; j <= num - i; j++)
			printf(" ");
		//print marks
		int k = 2 * i - 1;	//the quantity of asterisk
		int m;
		for(m = 1; m <= k; m++)
			printf("%c",mark);

		printf("\n");


	}

	//second half
	int num2 = num - 1;  //从中间向下的所有行数，比总行数一半少一行。
	
	int n;
	for(n = 1; n <= num2; n ++){
		//print blanks
		int j;
		for(j = 1; j <= n; j++)
			printf(" ");
		//pirnt marks
		int k = 2 * (num2 - n + 1) - 1; //the quantity of asterisk
		int m;
		for(m = 1; m <= k; m++){
			printf("%c",mark);
		
		}

		//next line
		printf("\n");
		
	
	}
		

	return 0;
}

int main(void){

	loop(9);

	printf("rows:");

	int rows;
	scanf("%d",&rows);

	rhombus(rows,'*');

	return 0;
}
