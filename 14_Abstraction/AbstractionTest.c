# include<stdio.h>
# include<math.h>

/*
 * the abstraction levels of codes
 *
 * 通过练习复数用点坐标或者极坐标表示，以此实现加减乘除来理解各个抽象层。
 * 复数的加减用点坐标比较方便，乘除用极坐标方便。
 *
 * 什么是“抽象”？
 * 抽象实际类似于数学中的提取公因式，例如:ac + ab = a(c + b)，对于等号左边如果改变a的值
 * 那么ac和ab都要改，但是对于右边，只需要改a就可以了。
 * Java中的抽象类，抽象方法就是用到了这一特性，从而使得代码耦合性降低，减少了代码量，使其易于维护。
 *
 * 复数 
 * 乘法计算方法：模长相乘，角度相加。
 * 除法：模长相除，角度相减。
 *
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


/*
 * 三，加减乘除运算方法。
 * */
struct complex_number add(struct complex_number z1, struct complex_number z2){
	//加法，实实相加，虚虚相加，减法同理。
	/*
	 * 重点：
	 * 这里直接调用封装好的方法来进行相加，而不是直接访问结构体本身(z1.x + z2.x)，封装好的方法实际是对结构体的一层抽象。 
	 * 将来即使结构体本身发生改动，这两个realPart(..),imaginaryPart(..)并不受影响，因此这里的加法也不用做改动。
	 * 只需改动realPart(),imaginaryPart()以及createFromRealImg(),createFromMagAng()这两层的相关方法内部代码即可。
	 * add()方法不用做任何改动。
	 *
	 * */
	double real = realPart(z1) + realPart(z2);
	double img  = imaginaryPart(z1) + imaginaryPart(z2);
	return createFromRealImg(real,img);
}

//sub
struct complex_number sub(struct complex_number z1, struct complex_number z2){
	double real = realPart(z1) - realPart(z2);
	double img = imaginaryPart(z1) - imaginaryPart(z2);
	return createFromRealImg(real,img);
}

//multiple  乘法除法用极坐标运算比较方便。
struct complex_number multiple(struct complex_number z1, struct complex_number z2){
	double mag = magnitude(z1) * magnitude(z2);
	double ang = angle(z1) * angle(z2);
	return createFromMagAng(mag,ang);	
	
}

//divide
struct complex_number divide(struct complex_number z1, struct complex_number z2){
	double mag = magnitude(z1) / magnitude(z2);
	double ang = angle(z1) - angle(z2);
	return createFromMagAng(mag,ang);	
}

int main(void){

	struct complex_number z1 = {3,4};
	struct complex_number z2;
	z2.x = 5;
	z2.y = 30;  
	
	//1,加法
	struct complex_number addResult = add(z1,z2);
	printf("add:x=%f,y=%fi\n",addResult.x,addResult.y);
	//2,减法
	struct complex_number subRes = sub(z1,z2);
	printf("sub:x=%f,y=%fi\n",subRes.x,subRes.y);
	//3,乘法
	struct complex_number mutRes = multiple(z1,z2);
	printf("multiple:x=%f,y=%fi\n",mutRes.x,mutRes.y);
	//4,除法
	struct complex_number divRes = divide(z1,z2);
	printf("divide:x=%f,y=%fi\n",divRes.x,divRes.y);


	return 0;
	
}






