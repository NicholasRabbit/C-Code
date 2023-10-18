# include<stdio.h>

/*
 * 复合类型(compound type)
 *
 * 结构体就是一种符合类型。
 * 
 * 数据类型分为基本数据类型,primitive type,例如int,double等。
 * 而符合数据类型就是有多个基本数据类型组成的，例如String类型由多个字符char组成。
 * 数学中的复数就是由实部和虚部组成，同样在编程语言中可以用符合类型来表示复数。
 *
 * C语言中的结构体，使用struct关键字定义。
 * */

int compoudTest(){

	//1,结构体写法
	//第一种写法，先规定好符合类型的内部结构，然后再声明变量。
	//注意：大括号后面的分号";"一定不要忘记，这不是函数。
	struct complex_struct{
		double x,y;
	}; 
	
	//声明变量，这里把"struct complex_struct"整体看作一个数据类型。
	struct complex_struct a1;
	struct complex_struct b1,b2;   //跟基本类型一样，可以一次声明多个变量。

	//第二种写法，规定类型的同时，声明变量
	struct complex_struct02{
		double x,y;
	} z1,z2;

	//2,结构体赋值
	double x = 2.5; //注意这里的x和复合类型中的x不是指向的同一内存地址
	a1.x = x; 
	a1.y = 3.0;
	printf("complex_struct(%f,%fi)\n",a1.x,a1.y);  //%fi不是一个输出控制符，是由%f和i组成的，用来表示虚数。
	
	
	//2.1,也可以初始化赋值
	
	//下面写法错误，忘了写关键字"struct"，结构体声明变量时，"struct"和"结构体名"要同时用!!
	//complex_struct02 m = {5.6,3.5}; 
	
	struct complex_struct02  m = {3.6,7.2};  //注意分号";",不要忘
	printf("struct02:m==>(%f,%f)\n",m.x,m.y);

	//2.2,结构体初始化赋值的个数可以比它的成员少，就从前向后给成员赋值，未赋值的用0代替，注意：初始化赋值个数不能比成员多。
	struct complex_struct02 n = {0.3};
	struct complex_struct02 h = {1.5,2.6,7.7};  //此处未报错，原因待查
	//以下初始化赋值的写法都是正确的
	struct complex_struct02 j = {5.6,7.4,};  //最后可以有逗号","
	struct complex_struct02 k = {2.7,};
	double p = 9.8;
	struct complex_struct02 l = {p,1.5};
	
	printf("struct02:n==>(%f,%f)\n",n.x,n.y);
	printf("struct02:h==>(%f,%f)\n",h.x,h.y);

	


	return 0;
}

int main(void){
	//调用函数，测试
	compoudTest();
	return 0;
}
