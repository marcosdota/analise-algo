#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void selection(int *A, int n){
	int j,m,i,chave;
	for(j=0;j<n-1;j++){
		m=j;
		for(i=j+1;i<n;i++)
			if(A[i]<A[m])
				m=i;
		chave=A[j];
		A[j]=A[m];
		A[m]=chave;
	}
}

int main(){
	int i=100000;
	int *A;	
	A = (int *)malloc (i * sizeof (int));
	//Pior caso:
	for(int k=0;k<i;k++)
			A[k]=i-k;		
	clock_t start = clock();
	selection(A,i);
	printf("Tamanho vetor: %d - time: %lf\n",i,(double)(clock()-start)/CLOCKS_PER_SEC);
	free(A);
	return 0;
}
