# include<stdio.h>

/*
 * Segmentation fault in C.
 *
 * */
int main(void){
	
	int i = 0;
	printf("Please input a number: ");
	scanf("%d",i);  //segmentatioin falut, The '&' should be added before tha variable. Error occurs here.

	return 0;
}
