# include<stdio.h>
# include<math.h>

/*
 * Homework of abstraction.
 *
 * Write a funtion to print the real and imaginary part of a complex number.
 * Don't print the part if it is 0.
 *
 * */

//声明全局结构体变量
struct complex_number{
	double x,y;
};


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

//print a complex number.
//这一层和Abtratcion.c中的加减乘除运算方法属于同一抽象层面。
int printComplex(struct complex_number z){

	double real = realPart(z);
	double img = imaginaryPart(z);

	if(real != 0.0)
		printf("%f",real);
	if(img != 0.0)
		printf("%fi",img);

	return 0;
}


int main(void){
	struct complex_number z = {.y=2.5};
	printComplex(z);
	return 0;
}
