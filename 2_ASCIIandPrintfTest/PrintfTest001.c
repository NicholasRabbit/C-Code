# include<stdio.h>


/*
 * 1,输出控制符范例。
 * */
int main(void){
	int i = 10;
	/*1,%d表示把i以10进制的形式输出;
	 *2,%x,%X表示以16进制输出，这俩意思一样,一般都用大写，好区分;
	 *3,%f：表示单浮点精度float，双浮点是%lf
	 * */
	printf("%d\n",i);
	printf("%X\n",i);	//10用16进制表示就是a,即9后面就是a。

	int j = 15;
	printf("%X\n",j);

	float age = 12.9;
	printf("age = %f\n",age); //这行和下行都是输出6位精度，待研究。printf()函数把单浮点的自动向上转型了。

	double money = 82.35;
	printf("money = %lf\n",money);

	return 0;
}

/*
 * 2,printf(..)函数的形参是可变长度的。
 * 可通过Linux命令行执行 man 3 printf 查看说明。
 * 这里的 3代表Section 3，具体见个人Linux笔记。
 * */
