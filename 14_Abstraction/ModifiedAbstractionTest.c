# include<stdio.h>
# include<math.h>

//首先声明一个全局范围的结构体类型,这里并没有声明变量，只是声明了一个结构体类型。
/*
struct complex_number{
	double x,y;  //直接坐标形式的结构体来表示复数
};
*/

/* 
 * 改成以下内部是极坐标形式的结构体来表示复数，
 * 只需再写获取实部和虚部和创建复数结构体的方法，而不用修改加减乘除的函数。
 * 由此体现了“抽象”的作用。
 * */
struct complex_number{
	double r,a;  //极坐标形式的内部形式来表示复数。 r：模长(半径), a: 角度
};



//极坐标形式的结构体复数，获取实部和虚部的方法
double realPart(struct complex_number z){
	return z.r * cos(z.a);
}
double imaginaryPart(struct complex_number z){
	return z.r * sin(z.a);
}

/*
 * 二，根据输入的参数获取复数
 * */

//输入点坐标
struct complex_number createFromRealImg(double x,double y){
	//先使用全局的结构体类型声明变量。
	struct complex_number z;
	z.r = sqrt(x * x + y * y);
	z.a = atan2(y, x);
	return z;
}

//输入直角坐标,r:模长，a:角度
struct complex_number createFromMagAng(double r,double a){
	struct complex_number z;
	z.r = r;
	z.a = a;
	return z;
}

/*
 * 三，加减乘除运算方法。
 * */
struct complex_number add(struct complex_number z1, struct complex_number z2){
	//加法，实实相加，虚虚相加，减法同理。
	/*
	 * 重点：这里直接调用封装好的方法来进行相加，而不是直接访问结构体本身(z1.x + z2.x)，封装好的方法实际是对结构体的一层抽象。 
	 * 将来即使结构体本身发生改动，这两个realPart(..),imaginaryPart(..)并不受影响，因此这里的加法也不用做改动。
	 *
	 * */
	double real = realPart(z1) + realPart(z2);
	double img  = imaginaryPart(z1) + imaginaryPart(z2);
	return createFromRealImg(real,img);
}

//其它三个运算方法同理。

int main(void){

	//注意：结构体内部的变量名称发生了改变，这里引用时也要修改。
	struct complex_number z1 = {3,4};
	struct complex_number z2;
	z2.r = 5;
	z2.a = 30;  
	
	//1,加法
	struct complex_number addResult = add(z1,z2);
	printf("add:x=%f,y=%f\n",addResult.r,addResult.a);


	return 0;

}


