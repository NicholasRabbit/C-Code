# include<stdio.h>

int print_pointers()
{
	int *ip, i;	
	i = 19;
	ip = &i;
	*ip = 30;
	
	return *ip;

	
}

int main(int argc, char *argv[])
{
	print_pointers();
	return 0;

}
