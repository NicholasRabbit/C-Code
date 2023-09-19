# include<stdio.h>

/*
 * calculate factorial number by using "do...while"
 * */
int doWhile(int n){

	int i = 1;
	int result = 1;
	do{
		//注意：这里声明的变量在while(..)里无法获取，因为“出了大括号就不认识”，还是超出了局部变量作用域
		//int i = 1;
		result = result * i;
		i ++;

	}while(i <= n);

	return result;
}

int main(void){

	int result = doWhile(5);

	printf("factorial result==> %d\n",result);

	return 0;
}
