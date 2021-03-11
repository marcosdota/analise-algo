#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void insertion(int *A, int n){
	int chave,i,j;
	for(j=1;j<n;j++){
		chave=A[j];
		i=j-1;
		while(i>=0 && A[i]>chave){
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=chave;
	}
}

int main(){
	int i=100000;
	int *A;	
	A = (int *)malloc (i * sizeof (int));
	//Pior caso:
	for(int k =0;k<i;k++)
			A[k]=i-k;
			
	clock_t start = clock();
	insertion(A,i);
	printf("Tamanho vetor: %d - time: %lf\n",i,(double)(clock()-start)/CLOCKS_PER_SEC);
	free(A);
	return 0;
}
