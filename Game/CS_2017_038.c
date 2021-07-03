//CS/2018/038
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "CS_2017_038.h"
	
int main () {
	int args,topA,topB;
	void arrangeAandB(int[],int[],int[],int);
	void display(int[],int[],int,int,int);
	void systemGenerateRandomNumber(int,int[]);
	do{
		int no;
		printf("Input should be 5 to 20");
		printf("\nInput:");
		scanf("%d",&no);

		int numberList[no];
		int A[no];
		int B[no];
		topA = no;
		topB = no;
		
		if(no <= 20 && no >= 5){
			systemGenerateRandomNumber(no,numberList);
			arrangeAandB(A,B,numberList,no);
			display(A,B,topA,topB,no);
			printf("\nDo you want to continue?(if Yes Enter 1,Otherwise Enter Any Key):");
			scanf("%d",&args);
		}else{
			args = 1;
		}
		printf("\n");
	}while(args == 1);

   return(0);
}

