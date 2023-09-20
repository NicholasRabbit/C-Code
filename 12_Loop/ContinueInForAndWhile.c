# include<stdio.h>

/*
 * The for loop is as same as the  while loop in most circunmstances,but there is a dramatic difference
 * when the "continue" is used in them.
 *
 * */


int forLoop(){

	int i;
	for(i = 0; i <= 10; i++){  //当continue执行后，在大括号内其下面的语句不会执行，但是本行的i++会执行。
		if(i % 2 == 0)
			continue;
		printf("for=%d\n",i);
	}

	return 0;
}


int whileLoop(){
	
	int i = 0;
	while(i <= 10){
		printf("while=%d\n",i);
		if(i % 2 == 0)
			continue;		//while循环中，continue执行后，下面的都不执行，包括i++，因此这里会出现死循环。
		printf("while=%d\n",i);
		i ++;
	}

	return 0;
}


int main(void){
	
	forLoop();

	printf("=========\n");

	whileLoop();

	return 0;
}
