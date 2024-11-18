# include<stdio.h>
# include<stdlib.h>
# include<time.h>

# define N 100000

/* 生成真实的随机数范例
 *
 * rand()生成的实际是伪随机数，是底层库内函数基于某个初始值(称为Seed),按照公式计算的。
 * 因为初始值是固定的,所以得到的结果是平均分布的。
 * 可以通过srand(...)函数确定初始值，函数实参传入time(null)，即srand(time{NULL}),因为
 * time(null)结果是获取到1970-01-01 00:00:00的毫秒数，所以Seed一直变化，这样得到的就是真的随机数了。
 *
 * */

int arr[N];

void genRandomReal(int upperBound){
	
	int i;
	for(i = 0; i < N; i++){

		//每次调用rand()之前都改变初始值，使之生成真实的随机数
		//使用time(..)函数要引入time.h
		srand(time(NULL));

		arr[i] = rand() % upperBound;   
	
	}
	
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

	genRandomReal(10);

	int i;
	for(i = 0; i < 10; i++){
		printf("real random of %d ==> %d\n",i, howMany(i));
	}

	return 0;
}
