# include<stdio.h>


/*
 * To use "_attribute_((packed))" to eliminate pads between variables.  
 * */

int main(void){
	
	struct {
		char a;
		short b;
		int c;
		char d;
	} __attribute__ ((packed)) s;  //Be cautious. There are two "_" on each side of "attribute".
	
	s.a = 1;
	s.b = 2;
	s.c = 3;
	s.d = 4;
	
	printf("sizeof %lu\n", sizeof(s));

	return 0;
}
