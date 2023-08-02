# include <stdio.h>

/*
 * Globle and Local variable.
 * 全局变量和局部变量，和Java中的用法一样。"出了大括号就不认识"。
 *
 * 方法内的局部变量在方法被调用时分配存储空间，方法结束后存储空间释放。下次调用又分配新的存储空间。
 * 全局变量在程序被调用时分配存储空间，程序结束时释放。
 *
 * */


int foo(int i,int j){

	printf("i=%d,j=%d\n",i,j);

	return i + j;
}

int goo(){
	int num;
	printf("num = %d \n",num);
	num	= 555;
	return 0;
}

int main(void){

	
	/*
	 * 1,局部变量研究。
	 * 注意： main和foo方法里虽然有相同名字的局部变量 i ,j，但是两个i代表不同的存储空间,是不一样的，含有不同的内存地址,j同理。
	 * */
	int i,j;
	i = 10;
	j = 23;
	int result = foo(i,j);
	printf("result = %d\n",result);

	printf("======\n");

	/*
	 * 2，验证局部变量的的存储空间分配和释放。
	 * num一直没有初始化，始终使用的是旧值。具体原理需待后期深入学习后研究。
	 * */
	goo();
	goo();
	
	printf("======\n");

	goo();
	printf("hello C \n");
	goo();

	return 0;
}
