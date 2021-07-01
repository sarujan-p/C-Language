#ifndef game_H_INCLUDED
#define game_H_INCLUDED
void systemGenerateRandomNumber(int n){
	time_t t;
	int i;
	int numberList[n];
	int topA = n;
	int topB = n;
	int A[topA];
	int B[topB];
	srand((unsigned) time(&t));
	printf("System generated number set: ");
	for( i = 0 ; i < n ; i++ ) {
		int r;
		r = rand() % 38;
		numberList[i] = r;
		printf("%d ",numberList[i]);
	}
	for(i = 0 ; i < n ; i++){
		A[i] = numberList[i];
		B[i] = numberList[n-1-i];
	}
	printf("(when x = 38)\n");
	printf("A's number set is ");
	for( i = 0 ; i < n ; i++ ) {
	    printf("%d ",A[i]);
	}
	printf("(%d is at the top of the box)",numberList[n-1]);
	printf("\nB's number set is ");
	for( i = 0 ; i < n ; i++ ) {
	    printf("%d ",B[i]);
	}
	printf("(%d is at the top of the box)\n",numberList[0]);
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
#endif // game_H_INCLUDED
