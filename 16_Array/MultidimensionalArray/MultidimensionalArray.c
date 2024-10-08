# include<stdio.h>


/* Multidimensional Array
 * 
 * 本例for全部使用C99语法。
 * */

int main(void){

	/* 
	 * 1, Multidimensional arrays may be initialise by specify bracketed values for each row.
	 * 注意：二维数组第一维度可以不指定长度，或手动赋值，编译器会自动指定并赋予默认值“0”
	 * 其它维度的都需要手动指定。
	 * 为什么？
	 * 因为在底层多维数组是线性排列的，例如，1，2，3；4，5，6
	 * 第一维长度不指定的话编译器可以自行决定，但是其它维度不指定的话编译器就无法决定每个数组元素
	 * 之间的间隔，无法进行最节省空间的分配内存空间的方式。
	 * */
	int mArr[3][2] = { {1,2,3}, {5,6,7},};  //
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			printf("%d ",mArr[i][j]);  //在下标 mArr[1]处的第二维的数组没有手动赋值，获取的都是脏数据。
		}
		printf("\n");
	}

	//int multiArray[5][];   //第二维没指定容量，报错
	
	/*
	 * 2,第二种初始化赋值方式,实际在存储器中二维数组也是连续存储的，跟一维数组一样，因此可以用这样的方式赋值。
	 * */
	int mArr2[3][2] = {1,2,3,4,5,6};  //warn but not error. 
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			printf("%d ",mArr2[i][j]);
		}
		printf("\n");
	}

	//3, C99语法，动态指定位置赋值
	int array[5][4] = {[0][1] = 38, [2][3] = 55};
	printf("[0][1] = %d, [2][3] = %d\n", array[0][1],array[2][3]);

	//4, char类型多维数组
	// "xx"相当于一个一维数组。
	// 这里第一维容量设置为8是为了让0空出来，第二维最大容量是10是为了保证最大长度后还有一个位置给"\0",详见"Linux C一站式编程"对应章节
	char days[8][10] = {"","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	for(int i = 1; i < 8; i++){
		printf("%s\n",days[i]);
	}

	return 0;
}
