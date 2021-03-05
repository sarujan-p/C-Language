#include<stdio.h>
#include<math.h>

void main()
{
	int a,b,c,discriminant,decision;
	float root1,root2;
	
	void read(int*,int*,int*);
	void calculate(int,int,int,float*,float*,int* discriminant);
	void display(float,float,int* discriminant);
	
	read(&a,&b,&c);
	calculate(a,b,c,&root1,&root2,&discriminant);
	display(root1,root2,&discriminant);
		
	do{
		printf("\nDo you want to Continue!");
		printf("\n1)Continue");
		printf("\n2)Exit\n");
		printf("\nSelect the operation 1 OR 2: ");
		scanf("%d",&decision);
		if(decision == 1){
			read(&a,&b,&c);
			calculate(a,b,c,&root1,&root2,&discriminant);
			display(root1,root2,&discriminant);
		}else if(decision == 2){
			printf("\nGood Bye!!!\n");
		}else{
			printf("\nYou Can Select Only 1 OR 2\n");
		}
	}while(decision != 2);	
	
}
		
void read(int* x,int* y,int* z) {
	do{
		printf("\nEnter the Value of a: ");
		scanf("%d",x);
		if(*x==0){
			printf("Value of a can not be zero!\n");
		}
	}while(*x == 0);
	printf("Enter the Value of b: ");
	scanf("%d",y);
	printf("Enter the Value of c: ");
	scanf("%d",z);
}
void calculate(int x,int y,int z,float* root1,float* root2,int* discriminant) {
	*discriminant=((y*y)-(4*x*z));
	if(*discriminant >= 0){
		if(discriminant > 0) {
	        *root1 = ((-y)+sqrt(*discriminant))/(2*x);
	        *root2 = ((-y)-sqrt(*discriminant))/(2*x);
    	}else {
	        *root1 = *root2 =(-y/(2*z));
    	}
	}
}
void display(float root1,float root2,int* discriminant) {
	if(*discriminant == 0){
		printf("\nroot = %.2f\n", root1);
	}else if(*discriminant > 0){
		printf("\nroot = %.2f or %.2f\n", root1, root2);
	}else{
		printf("\nDiscriminant is Negative!\n");
	}
}
