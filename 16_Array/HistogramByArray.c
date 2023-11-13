# include<stdio.h>
# include<stdlib.h>

# define N 100000


/*
 * 把统计随机的结果存起来。
 *
 * */

int arr[N];



//计算随机数
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


/* 把统计结果放进数组，有两种方法。
 *
 * 第一种：创建一个数组，有10个元素，每个下标代表一个数，调用howMany(..)函数，统计好数量后放到这个数组的对应下标位置。
 * 缺点：每个元素都得遍历一遍原数组arr[N]，如果数组元素多就很没效率。
 *
 * */
int histogram(int arr[]){

	int histogramArr[10];
	int i;
	for(i = 0; i < 10; i++){
		histogramArr[i] = howMany(i);
		//查看结果
		printf("hg[%d]: %d\n",i, histogramArr[i]);
	}

	return 0;
}

/*
 * 第二种：利用下标arr[N]中的数和histogramArr[]中下标相同的特性，只需一次遍历就可统计0~9出现的次数。
 * 这种方式效率高。
 * */
int histogramImproved(int arr[]){

	int histogramArr[10];
	int i;
	for(i == 0; i < N; i++){
		histogramArr[ arr[i] ]++;  //arr[i]是全局变量数组，元素都是0~9间的数，正好是histogramArr的下标
	}


	for(i = 0; i < 10; i++){
		//查看结果
		printf("hg[%d]: %d\n",i, histogramArr[i]);
	}




	return 0;
}

int main(void){

	genRandom(10);
	
	histogram(arr);

	histogramImproved(arr);

	return 0;

}
