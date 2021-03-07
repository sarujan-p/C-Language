#include<stdio.h>
#include<string.h>
#define size 1000

typedef struct{
	int sides[3];
	char type[50];
}Triangle;
	
int main(){
	int side1,side2,side3,i=0;
	char operation;
	Triangle triangle[size];
	
	void input_sides(Triangle[],int *,int *,int *,int *);
	void get_type(Triangle[],int *);
	void get_output(Triangle[],int *);
	
	do{
		input_sides(triangle,&side1,&side2,&side3,&i);
		printf("\nInput another?(Y/N):");
		scanf(" %c",&operation);
		switch(operation){
			case 'Y':
				i++;
				break; 
			
			case 'N':
				break;
				
			default :
				while(operation != 'Y'){
					printf("\nYou can only enter Y or N\n");
					printf("\nInput another?(Y/N):");
					scanf(" %c",&operation);
					if(operation == 'N'){
						break;
					}
				}
				if(operation == 'Y'){
					i++;
					break;
				}
		}
	}while(operation != 'N');
	get_type(triangle,&i);
	get_output(triangle,&i);
	
	return 0;
	
}
void input_sides(Triangle triangle[],int *side1,int *side2,int *side3,int *i){
	printf("\nEnter the length of the sides for a triangle\n");
	printf("Side 1 = ");
	scanf("%d",side1);
	printf("Side 2 = ");
	scanf("%d",side2);
	printf("Side 3 = ");
	scanf("%d",side3);
	
	triangle[*i].sides[0]=*side1;
	triangle[*i].sides[1]=*side2;
	triangle[*i].sides[2]=*side3;
}
void get_type(Triangle triangle[],int *i){
	int a,g_side1,g_side2,g_side3,t1,t2,t3;
	for(a=0;a<=*i;a++){
		g_side1=triangle[a].sides[0];
		g_side2=triangle[a].sides[1];
		g_side3=triangle[a].sides[2]; 
		
		t1=g_side1*g_side1;
		t2=g_side2*g_side2;
		t3=g_side3*g_side3;
		
		if((g_side1 <= g_side2+g_side3) && (g_side2 <= g_side1+g_side3) && (g_side3 <= g_side1+g_side2) && g_side1 > 0 && g_side2 > 0 && g_side3 > 0){
			if((t1==t2+t3) || (t2==t1+t3) || (t3==t1+t2)){
				strcpy(triangle[a].type,"A right triangle ");
			}else if(g_side1==g_side2 || g_side1==g_side3 || g_side2==g_side3){
				if(g_side1==g_side2 && g_side2==g_side3){
					strcpy(triangle[a].type,"An equilateral triangle");
				}else if((t1==t2+t3) || (t2==t1+t3) || (t3==t1+t2)){
					strcpy(triangle[a].type,"A right & isosceles triangle");
				}else{
					strcpy(triangle[a].type,"An isosceles triangle");
				}	
			}else{
				strcpy(triangle[a].type,"A scalene triangle");
			}
		}else{
			strcpy(triangle[a].type,"not a triangle");
		}
	}
}
void get_output(Triangle triangle[],int *i){
	int j,b;
	printf("\nThe details of the triangles are");
	for(b=0;b<=*i;b++){
		printf("\nTriangle number %d\n",b+1);
		for(j=0;j<3;j++){
			printf("Side %d = %d\n",j+1,triangle[b].sides[j]);
		}
		printf("Type = %s\n",triangle[b].type);
	}
}
