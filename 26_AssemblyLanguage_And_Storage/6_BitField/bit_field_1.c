# include<stdio.h>


/*
 * A structre declarator can be a specified number of bits,  which is called a "bit-field". 
 * */

typedef struct {
	unsigned int icon : 8;   //8 bits
	unsigned int colour : 4;
    unsigned int underline : 1;
	unsigned int blink : 1;	
} screen;


int main(void){
	
	screen s = {100, 2, 1, 0};

	printf("sizeof: %lu\n", sizeof(s));

	return 0;

}
