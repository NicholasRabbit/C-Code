

//数组应用范例：统计随机数


# include<stdio.h>
# include<stdlib.h>

//这里定义一个常量，供编译器预处理阶段把代码中的N全部替换为指定数值。
//关于Macro,define等参照个人笔记。
# define N 1000000    //Caution: 这里不要加分号";"



//name a global variable of array
/* 这里的N在预处理阶段会被替换为对应的数值。
 * 这种写法也类似于提取公因式，当代码中的N很多时，就不用再一个个去改了。
 * 因为一个个改浪费时间，也容易出错。
 * */
int arr[N];   

/*
 * 生成随机数，放进数组。
 * rand()是stdlib.h中的函数。
 * 其中有个常量 "RAND_MAX"，这个数根据不同的平台数值不同。
 * rand()的返回值是 0~ RAND_MAX 之间的值。
 * 
 * 注意：rand()函数底层生成的数也不是完全随机的，而是按照一个公式计算的结果。
 *
 * 本例我们不需要那么大的值，因此用它跟 upperBound = 10或其它较小的数取余。
 * */
void genRandom(int upperBound){
	int i;
	for(i = 0; i < N; i++)
		arr[i] = rand() % upperBound;   
	
}

//计算数的出现次数
int howMany(int num){

	int count = 0;

	int i;
	for(i = 0; i < N; i++){
		if(num == arr[i])
			count ++;
	}

	return count;
}

int main(void){

	//生成10以内的随机数
	genRandom(10);

	int i;
	//遍历计算每个数出现的次数
	for(i = 0; i < 10; i++){
		printf("count of %d ==> %d\n",i, howMany(i));
	}

	return 0;
}

