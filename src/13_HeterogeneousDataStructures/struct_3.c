#include <stdio.h>

struct rect {
	int llx;
	int lly;
	int colour;
	int width;
	int height;
};


int area(struct rect *rp);

void rotate_left(struct rect *rp);


int main(void) 
{
	struct rect r;
	r.llx = r.lly = 0;
	r.colour = 0xFF00FF;
	r.width = 10;
	r.height = 20;
	
	struct rect *rp = &r;

	/*
	 * A pointer to a structure is the address of its first byte.
	 * */
	printf("rp: 0x%x\n", rp);
	printf("r.llx: 0x%x\n", &r.llx);

	int square = area(rp);
	printf("The area is %d\n", square);

	/*
	 * Rotate the rectangle
	 * */
	rotate_left(rp);
	printf("height after rotating: %d\n", rp->height);

	return 0;
}

int area (struct rect *rp) 
{
	/*
	 * Note that the parentheses used here. If (*rp) were not
	 * bracketed, the compiler would interpret the expression
	 * as *(rp.width) which is not valid.
	 * */
	return (*rp).width * (*rp).height;
}

/*
 * (*rp).width can be represented by "rp->width" in C.
 * */
void rotate_left(struct rect *rp)
{
	int t = rp->height;
	rp->height = rp->width;
	rp->width = t;
	rp->llx -= t;

}
