# include<stdio.h>
# include<math.h>

/*
 * 数据类型标志
 *
 * 上节中，复数结构体的直角坐标系和极坐标形式采用两种不同的结构体表示。
 *
 * 如何用一种结构体表示这两种形式？
 * 方法1：采用三角函数转换的形式，把极坐标转换成直角坐标再存起来。因为double类型本省有精度损失问题，这样做不好。
 * 方法2：在结构体内增加一个标志，区分其内的数是用来表示直角坐标还是极坐标的。
 *
 * 方法2的做法合适。
 *
 * */

//声明一个enum类型全局变量，不要声明为局部变量
enum coordinateType {RECTANGULAR, POLAR};  //这里从0开始默认复制，因此0表示直角坐标系，1表示极坐标系

//复数
struct complexNumber {
	enum coordinateType t;
	double x,y;
};

//create a complex number from a rectangular coordinate system
struct complexNumber createFromRealImg(double x, double y){
	struct complexNumber z;
	z.t = RECTANGULAR;
	z.x = x;
	z.y = y;
	return z;
}

//create a complex number from a polar coordinate system
struct complexNumber createFromPolar(double x, double y){
	struct complexNumber z;
	z.t = POLAR;
	z.x = x;
	z.y = y;
	return z;
}

//get the real part of a complex number
double realPart(struct complexNumber z){
	//rectangular coordinate system
	if(z.t == 0){
		return z.x;

	}else if(z.t == 1){
		//polar coordinateType system
		double r = z.x * cos(z.y);	 //
		return r;
	}

	return 0;
}

//get the imaginary part of a complex number
double imgPart(struct complexNumber z){
	//rectangular coordinateType system
	if(z.t == 0){
		return z.y;
	}else{
		// z.t == 1
		// polar coordinateType system
		double i = z.x * sin(z.y);
		return i;
	}
}


int main(void){

	
	//call the function to create a number of rectangular system
	struct complexNumber cnum = createFromRealImg(3.0,4.0);
	printf("%d,%f,%fi\n", cnum.t, cnum.x, cnum.y);

	//and call the function to careate a number of polar system
	struct complexNumber polarNum = createFromPolar(5.0,30);
	printf("%d,%f,%f\n", polarNum.t, polarNum.x, polarNum.y);



	//enum data also could be initialized only if it is written in a proper order.
	struct complexNumber z = {0,3.0,4.0};
	printf("%d,%f,%fi\n", z.t, z.x, z.y);

	

	return 0;
}
