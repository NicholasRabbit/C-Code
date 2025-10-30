# include<stdio.h>

/*
 * Segmentation faulst in C.
 *
 * */

int main(void){
	
	int i = 0;
	scanf("%d",i);  //segmentatioin falut, The '&' should be added before tha variable. Error occurs here.

	return 0;
}
