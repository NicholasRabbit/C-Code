
/*
 * How to a modifier named "volatile"?
 * */
# include<stdio.h>

unsigned char recv;
unsigned char send;

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


