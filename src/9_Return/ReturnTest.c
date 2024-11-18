# include<stdio.h>

/*
 * return的用法
 *
 * 1,基本和Java中一样，
 * 
 * 2,不同之处是C语言中，当返回值不为void时，编译阶段不会检查是否漏写return,
 * 下面的doSome(..)例子中，假如y=0，则下面语句都不会执行，但是函数除了if判断语句，最后也没写return。
 * 在Java中会编译报错,C语言中不报错，但是会返回一个未定义的不确定的值。
 * 最大的隐患就是编译阶段不报错，返回的错误值会导致bug。可能后期写了几万行代码，用户总是遇到错误，但是你总是找不到错误在哪里.
 *
 * 3,因此建议多使用-Wall,使用-Wall会有提醒。
 * */

int doSome(int y){

	if(y < 0)
		return -y;
	else if(y > 0)
		return y;
	
	/*
	 * 重点：凡是返回值指定数据类型，一定要考虑到所有情况下的返回值，不要漏写。
	 * 
	 * */
	//return 0;   //这里注释，测试返回什么值。

}

int main(void){

	int i = doSome(-5);
	printf("i = %d \n",i);

	//to test if there were any failure when the arguemnt is 0.
	int j = doSome (0); //这里返回一个错误值：7，可能每次编译都返回不同的值。
	printf("j = %d \n",j);

	return 0;
}
