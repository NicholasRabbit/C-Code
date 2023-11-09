# include<stdio.h>

/*
 * Enum type in C.
 * */

//name a global variable of enum.
enum weekEnum {MONDAY,TUESDAY,WEDNESDAY};  //Attention: don't add "=" in the middle of the expression.

int main(void){


	printf("%d,%d,%d\n",MONDAY,TUESDAY,WEDNESDAY);  

	//enum数据结构内的值默认从“0”开始，也可以手动设置改变下标的开始值。
	//enum的数据可以作为switch..case的参数
	enum seasonEnum {SPRING,SUMMER,AUTUMN,WINTER};  
	printf("%d,%d,%d,%d\n",SPRING,SUMMER,AUTUMN,WINTER);  //result: 0,1
	
	//手动改变下标，这里JANUARY还是0，后面就从2开始
	enum monthEnum {JANUARY,FEBRUARY = 2,MARCH,APRIL};

	//int SPRING;  //这里报错，虽然这俩SPRING不在同一个作用域内，但是seasonEnum和本行的SPRING在一个作用域，因此报错

	printf("%d,%d,%d,%d\n",JANUARY,FEBRUARY,MARCH,APRIL);  //result: 0,2,3,4

	return 0;
}


