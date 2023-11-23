# include<stdio.h>


/* Multidimensional Array
 *
 * */

int main(void){

	/* 
	 * 1, Multidimensional arrays may be initialise by specify bracketed values for each row.
	 * 注意：二维数组第一维度可以不指定长度，或手动赋值，编译器会自动指定并赋予默认值“0”
	 * 其它维度的都需要手动指定。
	 * */
	int mArr0[][];
	int mArr[3][2] = { {1,2,3}, {5,6,7},};  //
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 5; j++){
			printf("%d ",mArr[i][j]);
		}
		printf("\n");
	}
	
	/*
	 * 2, 
	 * */
	int mArr2[3][2] = {1,2,3,4,5,6};
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			printf("%d ",mArr2[i][j]);
		}
		printf("\n");
	}

	

	return 0;
}
