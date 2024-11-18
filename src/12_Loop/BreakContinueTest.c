# include<stdio.h>
# include<math.h>

/*
 * The usage of "break" and "contiue" in C.
 * Calculate the primes which are smaller than 100.
 * */

int isPrime(int n){

	int i;
	for(i = 2; i < n; i++)	
		if(n % i == 0)  //这里if算一个语句，所以for的{}可以省略
			break;
	if(i == n)
		return 1;	
	else
		return 0;

}

/*
 * 获取质数优化思路：
 * 一个数n如果不能在2~sqrt(n)(平方根)有数整除的话，那么这个数就是个质数。
 * 因为大于平方根的数能整除的话，那么从2开始肯定有能整除的。
 *
 * 此方法得出结果少个2，待分析
 * */
int isPrimeImproved(int n){
	int i;
	double squareNum = sqrt(n);  //这里n自动向上转型。
	int ceilNum = ceil(squareNum);  //向上取整，下面for循环多计算一次。

	for(i = 2; i <= ceilNum; i++)
		if(n % i == 0 )
			break;
	if(i <= ceilNum)	//i <= ceilNum 表示有能被n整除的数
		return 0;
	else 
		return 1;
	
}


int getPrimes(int n){
	int i;
	for(i = 2; i < n; i++){
		if(!isPrime(i))
			continue;
		printf("prime:%d\n",i);
	}

	return 0;

}

int getPrimesImproved(int n){
	//imporved
	int i;
	for(i = 2; i < n; i++){
		if(!isPrimeImproved(i))
			continue;
		printf("prime improved:%d\n",i);
	}
	return 0;


}



int main(void){

	//test sqrt()
	double num = 5.0;
	double b = sqrt(num);	//使用math.h的函数，编译时加 -lm
	printf("sqrt=%lf\n",b);

	//1,get primes
	getPrimes(100);

	printf("=============\n");

	//2,improved the function of getPrimes
	getPrimesImproved(100);


	return 0;
}
