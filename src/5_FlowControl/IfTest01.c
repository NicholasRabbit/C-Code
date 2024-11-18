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

	//一，C语言中只有0代表是false,其它的包括负数都是true
	if(-1){
		printf("-1==>\n");	//这里执行
	}

	//二，char类型也是等于true，实际底层都是数
	char b = 'a';
	if(b){
		printf("b==>\n");
		printf("b = %d\n",b);
	}

	//三，if..else if... else和Java中一样
	if(2 > 5){
		printf("2>5?\n");
	}else if(2 < 5){
		printf("2<5\n");
	}else{
		printf("else\n");
	}

	//四，if后不写大括号默认范围是一条语句。
	if(2 > 3)
		printf("test default!"); //这一句不执行
	printf("not in the domain of if\n"); //这一句执行
	
	//五，表达式写法, 60 < j < 100,不正确
	//   无论j去什么值，结果总为真，因为先执行60<j，结果为0或1,它们恒小于100
	int j = 200;
	if(60 < j < 100) 
		printf("result = %d\n",60<j<100);  //这里一直会执行
	// 正确写法
	if(j > 60 && j < 100)
		printf("won't execute"); //不执行


	

	return 0;
}
