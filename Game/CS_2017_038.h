//CS/2018/038
void systemGenerateRandomNumber(int n,int numberList[]){
	//generate the random number
	time_t t;
	srand((unsigned) time(&t));
	printf("System generated number set: ");
	int i;
	for( i = 0 ; i < n ; i++ ) {
		int r;
		r = rand() % 38;
		numberList[i] = r;
		printf("%d ",numberList[i]);
	}
	printf("(when x = 38)\n");
}

void arrangeAandB(int A[],int B[],int numberList[],int n){
	//insert into boxes A and B
	int i;
	for(i = 0 ; i < n ; i++){
		A[i] = numberList[i];
		B[i] = numberList[n-1-i];
	}
	printf("A's number set is ");
	for( i = 0 ; i < n ; i++ ) {
		printf("%d ",A[i]);
	}
	printf("(%d is at the top of the box)",A[n-1]);
	printf("\nB's number set is ");
	for( i = 0 ; i < n ; i++ ) {
		printf("%d ",B[i]);
	}
	printf("(%d is at the top of the box)\n",B[n-1]);
}

void display(int A[],int B[],int topA,int topB,int n){
	//display the output
	int a = 0;
	int max = 2*n;
	int output[max];
	while(topA != 0 && topB != 0){
		if(A[topA-1] > B[topB-1]){
			output[a] = 2;
			topA--;
		}else if(A[topA-1] == B[topB-1]){
			output[a] = 0;
			topA--;
			topB--;
		}else{
			output[a] = 1;
			topB--;
		}
		a++;
	}
	printf("\nOutput:\t");
	int j;
	for(j=0;j < a;j++){
		printf("%d ",output[j]);
	}
	if(topA == 0){
		printf("\n\tA is the Winner\n");
	}else{
		printf("\n\tB is the Winner\n");
	}
}
