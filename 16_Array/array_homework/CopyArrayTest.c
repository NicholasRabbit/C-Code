# include<stdio.h>

//数组不能互相赋值，因此写个方法实现数组的复制

int copyArray(int srcArr[],int desArr[],int size){

	int i;
	for(i = 0; i < size; i++){
		desArr[i] = srcArr[i];
	}

	return 0;
}

int main(void){

	int srcArr[5] = {35,27,11,};
	int desArr[5];

	copyArray(srcArr,desArr,5);

	int i;
	for(i = 0; i < 5; i++){
		printf("desArr[%d]: %d\n",i,desArr[i]);
	}

	return 0;
}
