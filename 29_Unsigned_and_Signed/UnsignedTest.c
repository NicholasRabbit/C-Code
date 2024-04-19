# include<stdio.h>


/*
 * An unsigned number is always bigger than 0.
 * The for loop below is endless.
 * */
int main(void){


	unsigned int i;
	for(i = 10; i >= 0; i--){
		printf("%u\n", i);
	}
	
	

	return 0;
}
