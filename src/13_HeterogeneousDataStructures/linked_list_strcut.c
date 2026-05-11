#include <stdio.h>

typedef struct ELE {
	int val;
	struct ELE *next;
} *list_ptr;

int main(int argc, char *argv[])
{
	struct ELE ele1;
	struct ELE ele2;
	ele1.val = 0x00a;
	ele1.next = &ele2;
	ele2.val = 0x0b0;
	ele2.next = 0;


	return 0;
}
