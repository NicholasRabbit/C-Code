

/*
 * The coding stytle I use is as same as style of Java.
 * I unconsciously or stubbornly type C code like Java code which is my first learned language.
 * It is time to observe the convention of C language.
 *
 * */

# include<stdio.h>

/*
 * Is the following code which is written by the "Linux kernel coding style" beautiful?
 * Honestly, they are clean and tidy except indentions of 8 characters that I can't accept at least.
 * */
int main (void) 
{
       
		int i;
		for (i = 0;i < 10; i++) {
				if ( i % 2 == 0) {
						printf("Hi coding stytle! [%d]\n", i);
				}
				
		}

	return 0;

}
