# include<stdio.h>
/*
 * 流程控制if练习
 * 和Java中的使用方法一样
 *
 * 写代码就是为了实现流程控制。
 *
 * 再复杂的程序都可以由 顺序，选择，循环这三种流程控制解决。--Turing
 * */
int main(void){
	
	if(1 < 2){
		printf("1 < 2\n");
	}

	if(0){
		printf("0==>\n");
	}

	//C语言中只有0代表是false,其它的包括负数都是true
	if(-1){
		printf("-1==>\n");	//这里执行
	}

	//char类型也是等于true，实际底层都是数
	char b = 'a';
	if(b){
		printf("b==>\n");
		printf("b = %d\n",b);
	}

	//if..else if... else和Java中一样
	if(2 > 5){
		printf("2>5?\n");
	}else if(2 < 5){
		printf("2<5\n");
	}else{
		printf("else\n");
	}

	return 0;
}
