# include<stdio.h>
# include<math.h>

/*
 * Incremental developing : 增量式开发
 *
 * 边学习C语言，边复习巩固开发的理念。
 * 增量式开发实际就是一步步的开发，写完一个逻辑之后进行测试，测试无误再往下进行。
 * 在上一步正确的基础上进行下一步的开发。跟写Java一样，实际这种理念无关语言，任何
 * 开发工作都适用。
 *
 * 同时还需要分解问题，把大问题分解为小问题，把小问题分解为更小的代码块。还有注意代码
 * 块复用，一个方法或函数只完成一个功能。多个函数组合到一个函数里完成一个复杂的功能。
 * 就是常说的“高内聚，低耦合”。
 *
 * 下面以实现计算给定圆心和半径的圆面积为例，实践上述思路。
 *
 * */

//第一步，计算两点间距离，即半径
double distance(double x1,double x2,double y1,double y2){
	
	double dx = x1 - x2;
	double dy = y1 - y2;
	double dsquare = dx * dx + dy * dy;

	//调用函数求平方根
	double result = sqrt(dsquare);

	return result;

}

//第二步，根据半径求出圆面积
double area(double radius){
	double areas = 3.14 * radius * radius;
	return areas;
}


int main (void){

	//测试计算距离对不对，后期可注释
	double radius = distance(1.0,4.0,2.0,6.0);
	printf("d = %lf\n",radius);

	//求面积
	double square = area(radius);
	printf("square = %lf \n",square);

	return 0;
}
