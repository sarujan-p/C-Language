#include<stdio.h>
#include<math.h>

int a,b,c,discriminant,decision;
float root1,root2;

void main() {
	extern int a,b,c,discriminant,decision;
	extern float root1,root2;
	
	void read();
	void calculate();
	void display();
	
	read();
	calculate();
	display();
	
	do{
		printf("\nDo you want to Continue!");
		printf("\n1)Continue");
		printf("\n2)Exit\n");
		printf("\nSelect the operation 1 OR 2: ");
		scanf("%d",&decision);
		if(decision == 1){
			read();
			calculate();
			display();
		}else if(decision == 2){
			printf("\nGood Bye!!!\n");
		}else{
			printf("\nYou Can Select Only 1 OR 2\n");
		}
	}while(decision != 2);
}

void read() {
	extern int a,b,c;
	do{
		printf("\nEnter the Value of a: ");
		scanf("%d",&a);
		if(a==0){
			printf("Value of a can not be zero!\n");
		}
	}while(a == 0);
	printf("Enter the Value of b: ");
	scanf("%d",&b);
	printf("Enter the Value of c: ");
	scanf("%d",&c);
}

void calculate() {
	extern int a,b,c,discriminant;
	extern float root1,root2;
	discriminant=((b*b)-(4*a*c));
	if(discriminant >= 0){
		if(discriminant > 0) {
	        root1 = ((-b)+sqrt(discriminant))/(2*a);
	        root2 = ((-b)-sqrt(discriminant))/(2*a);
    	}else {
	        root1 = root2 =(-b/(2*c));
    	}
	}
}

void display() {
	extern int discriminant;
	extern float root1,root2;
		if(discriminant == 0){
		printf("\nroot = %.2f\n", root1);
	}else if(discriminant > 0){
		printf("\nroot = %.2f or %.2f\n", root1, root2);
	}else{
		printf("\nDiscriminant is Negative!\n");
	}
}
