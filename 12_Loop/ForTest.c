# include<stdio.h>

/*
 * for demo
 * It is as same as in Java.
 * */

int forLoop(){

	//for和while可以互换，写法不同，用处不同，功能相同。
	//for中间的判断式不写，相当于while(true),死循环
	/*for( ; ; ){
		printf("endless loop\n");
	}*/

	return 0;
}

//implements of factorial by using for loop.
int factorial(int n){

	int result = 1;
	//注意，for(..)括号内初始化局部变量，仅在C99中可用，跟Java不同。
	//因此编译时需加指定命令，gcc -std=c99 ForTest.c -o ForTest.out
	//这是从C++借鉴的语法，出于兼容性考虑，C中不建议使用这样的写法
	for(int i = 1; i <= n; i++){
		result = result * i;
	}

	return result;
}


int main(void){

	forLoop();

	printf("calculate factorial result:");
	int n;
	scanf("%d",&n);

	int result = factorial(n);
	
	printf("factorial result==>%d\n",result);

	return 0;
}
