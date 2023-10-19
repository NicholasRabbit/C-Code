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

	//第三种写法，这种写法没有定义结构体的名称，因此别的地方不能再引用此结构体声明变量了。
	struct {
		double x,y;
	} m1,m2;
	m1.x = 3.5;
	m1.y = 0.9;
	printf("anonymous struct:%f,%f\n",m1.x,m1.y);

	//2,结构体赋值
	double x = 2.5; //注意这里的x和复合类型中的x不是指向的同一内存地址
	a1.x = x; 
	a1.y = 3.0;
	printf("complex_struct(%f,%fi)\n",a1.x,a1.y);  //%fi不是一个输出控制符，是由%f和i组成的，用来表示虚数。
	
	
	//2.1,也可以初始化赋值
	
	//下面写法错误，忘了写关键字"struct"，结构体声明变量时，"struct"和"结构体名"要同时用!!
	//complex_struct02 m = {5.6,3.5}; 
	
	//正确写法。
	struct complex_struct02  m = {3.6,7.2};  //注意分号";",不要忘
	printf("struct02:m==>(%f,%f)\n",m.x,m.y);

	//2.2,结构体初始化赋值的个数可以比它的成员少，就从前向后给成员赋值，未赋值的用0代替，注意：初始化赋值个数不能比成员多。
	struct complex_struct02 n = {0.3};
	struct complex_struct02 h = {1.5,2.6,7.7};  //此处报警"excess element",但仍可编译通过
	//以下初始化赋值的写法都是正确的
	struct complex_struct02 j = {5.6,7.4,};  //最后可以有逗号","
	struct complex_struct02 k = {2.7,};
	double p = 9.8;
	struct complex_struct02 l = {p,1.5};
	struct complex_struct02 b = {.y = 4.5};  //指定给结构体的y赋值，x取默认值。
	struct complex_struct02 d = j;      //结构体变量时间可以相互赋值

	printf("struct02:n==>(%f,%f)\n",n.x,n.y);
	printf("struct02:h==>(%f,%f)\n",h.x,h.y);
	printf("struct02:b==>(%f,%f)\n",b.x,b.y);
	printf("struct02:d==>(%f,%f)\n",d.x,d.y);
	
	//2.3,{..}不能用于结构体变量的赋值，因为它不是表达式也不是常量等。
	struct complex_struct02 c;
	//c = {1.5,3.0};    //此处写法错误
	
	
	//3, +-*/和&&,||,!等不能用于结构体
	//d = j + k;  //报错
	
	//4，因为结构体之间可以相互赋值和初始化，所以结构体可当作函数的参数.(参照下一个代码文件)


	return 0;
}

int main(void){
	//调用函数，测试
	compoudTest();
	return 0;
}
