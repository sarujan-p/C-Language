#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "game.h"

int main () {
	int args;
	void systemGenerateRandomNumber(int);
	do{
		int no;
		printf("Input should be 5 to 20");
		printf("\nInput:");
		scanf("%d",&no);
		if(no <= 20 && no >= 5){
			systemGenerateRandomNumber(no);
			printf("\nDo you want to continue?(if Yes Enter 1,Otherwise Enter Any Key):");
			scanf("%d",&args);
		}else{
			args = 1;
		}
		printf("\n");
	}while(args == 1);
   
   return(0);
}



