# include<stdio.h>

/*
 * switch demo
 * 跟if else 一样，不精确的浮点类型数据不适合用switch比较。
 * switch后的条件必须是整型常量表达式。
 *
 * switch一般都可以用if else代替，但是编译器编译的时候会对switch语句优化，因此其性能
 * 要高些。
 * */

int printWeekDay(int n){

	switch (n) {

		case 1 :
			printf("Monay\n");
			break;
		case 2 : 
			printf("Tuesday\n");
			break;
		case 3 :
			printf("Wednesday\n");
			break;
		case 4 :
			printf("Thursday\n");
			break;
		case 5 :
			printf("Friday\n");
			break;
		case 6 :
			printf("Saturday\n");
			break;
		case 7 :
			printf("Sunday\n");
			break;
		default :
			printf("illegal day number\n");
	
	}

	//case的穿透性，跟Java中一样
	switch (n) {
		case 1 :
		case 2 :
		case 3 :
		case 4 :
		case 5 :
			printf("workdday\n");
			break;
		case 6 :
		case 7 :
			printf("weekend\n");
			break;
		default :
			printf("illegal day number\n");
	
	}


	return 0;
}

int main(void){
	
	printf("input a day of week:");

	int n;
	scanf("%d",&n);

	printWeekDay(n);

	return 0;
}
