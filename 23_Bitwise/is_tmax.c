# include<stdio.h>



int isTmax(int x) {
  int map = x + 0x01;
  int res = ~(map + x);
  return !res & (!!map);  
}

int main (void) 
{
	int ret = isTmax(0x7fffffff);

	return 0;

}
