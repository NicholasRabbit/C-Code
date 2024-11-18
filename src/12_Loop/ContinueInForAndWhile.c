# include<stdio.h>

/*
 * The for loop is as same as the  while loop in most circunmstances,
 * but there is a significant difference when the "continue" is used in them.
 * */


int forLoop(){

	int i;
	for(i = 0; i <= 10; i++){  
		if(i % 2 == 0)
			continue;   // the code below won't be executed but "i++" in the parentheses will.
		printf("for=%d\n",i);
	}

	return 0;
}


int whileLoop(){
	
	int i = 0;
	while(i <= 10){
		printf("while=%d\n",i);
		if(i % 2 == 0)
			continue;	// the following statement won't be executed including "i++";
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
