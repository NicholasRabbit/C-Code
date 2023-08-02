# include<stdio.h>

/*
 * Homework of Parameter and arguement
 *
 * 局部变量范围考察。
 * 看看i,j分别调用doSome函数后，它们在main方法中各自的值是否变化。
 * 答：不变化。
 * */

int doSome(int a){
	a = a + 1;
	printf("a ==> %d\n",a);
	return a;
}

int main(void){
	
	int i = 10;
	
	doSome(i);
	printf("i ==> %d \n",i);

	int j = 20;
	
	doSome(j);
	printf("j ==> %d \n",j);
	
	return 0;
}
