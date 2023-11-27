# include<stdio.h>
# include<stdlib.h>
# include<time.h>


/*
 * To write a game of playing sessior,stone and cloth.
 *
 * */

int play(){

	//Declare an array which represents the gestures.
	char gestures[][10] = {"Scissors","Stone","Cloth"};

	//Declare all of the variables;
	int man,com,hasInput,result;

	while(1){
	
		printf("Please input 0-scissor, 1-stone or 2-cloth:");

		//To check if there is any input number. If the return value is 1, user has input a number.
		hasInput = scanf("%d",&man);

		printf("hasInput=%d\n",hasInput);

		//check if the input number is valid or not.
		if(hasInput != 1 || man < 0 || man > 2){
			printf("%s\n","The input number is valid");
			continue;
		}

		//To generate a random number which represents comptuter.
		srand(time(NULL));
		com = rand() % 3;

		printf("Your gesture is:%s,and the computer's gesture is %s\n",gestures[man],gestures[com]);

		//??
		result = (man - com + 4) % 3 - 1;

		//To compare the gestures.
		if(result == 0)
			printf("even\n");
		else if(result < 0)
			printf("You lose!\n");
		else 
			printf("You win!\n");


	
	}

	return 0;
}


int main(void){

	play();

	return 0;
}
