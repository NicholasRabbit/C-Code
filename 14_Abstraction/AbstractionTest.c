# include<stdio.h>
# include<math.h>

/*
 * the abstraction levels of codes
 *
 * 通过练习复数用点坐标或者极坐标表示，以此实现加减乘除来理解各个抽象层。
 * 复数的加减用点坐标比较方便，乘除用极坐标方便。
 *
 * 复数乘法计算方法：模长相乘，角度相加。
 * */

//首先声明一个全局范围的结构体类型,这里并没有声明变量，只是声明了一个结构体类型。
struct complex_number{
	double x,y;
};

//一，复数的两种表示方法。

//1,用点坐标表示复数。(rectangular coordinate system)
//1.1 获取实部 
double realPart(struct complex_number z){
	return z.x;
}

//1.2 获取虚部
double imaginaryPart(struct complex_number z){
	return z.y;
}

//2,用极坐标表示复数。(polar coordinate system)
//2.1 模长
double magnitude(struct complex_number z){
	return sqrt(z.x * z.x + z.y * z.y);
}

//2.2 角度
double angle(struct complex_number z){
	return atan2(z.y,z.x); //直边比邻边得到正切值。atan: arctan
}


//二，根据输入的参数获取复数
//输入点坐标
struct complex_number createFromRealImg(double x,double y){
	//使用全局的结构体类型声明变量。
	struct complex_number z;
	z.x = x;
	z.y = y;
	return z;
}

//输入直角坐标,r:模长，a:角度
struct complex_number createFromMagAng(double r,double a){
	struct complex_number z;
	z.x = r * cos(a);
	z.y = r * sin(a);
	return z;
}





