# include<stdio.h>

/*
 * 复合类型(compound type)
 * 数据类型分为基本数据类型,primitive type,例如int,double等。
 * 而符合数据类型就是有多个基本数据类型组成的，例如String类型由
 * 多个字符char组成。
 * 数学中的复数就是由实部和虚部组成，同样在编程语言中可以用符合类型来表示复数。
 * */

int compoudTest(){

	//复合类型写法
	//第一种写法，先规定好符合类型的内部结构，然后再声明变量。
	//注意：大括号后面的分号";"一定不要忘记，这不是函数。
	struct complex_struct{
		double x,y;
	}; 
	
	//声明变量，这里把"struct complex_struct"整体看作一个数据类型。
	struct complex_struct a1;
	struct complex_struct b1,b2;   //跟基本类型一样，可以一次声明多个变量。

	//第二种写法，规定类型的同时，声明变量
	

	return 0;
}
