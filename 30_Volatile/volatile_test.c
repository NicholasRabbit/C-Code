
/*
 * How to use a modifier named "volatile"?
 * to be continued...
 * */
# include<stdio.h>

//unsigned char recv;
//unsigned char send;

volatile unsigned char recv;
volatile unsigned char send;

unsigned char buffer[3];

int main (void) 
{
	buffer[0] = recv;
	buffer[1] = recv;
	buffer[2] = recv;
	send = ~ buffer[0];
	send = ~ buffer[1];
	send = ~ buffer[2];

	return 0;
}


