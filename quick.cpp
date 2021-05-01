#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int partition(int *A,int p, int r){
	int x = A[r];
	int i = p-1;
	int aux;
	for(int j=p;j<=r-1;j++){
		if(A[j]<=x){
			i = i+1;
			aux = A[i];
			A[i] = A[j];
			A[j] = aux;
		}
	}
	aux = A[i+1];
	A[i+1] = A[r];
	A[r] = aux;
	return i+1;
	 
}

void quickSort2(int *A,int p,int r){
	if(p<r){
		int q = partition(A,p,r);
		quickSort2(A,p,q-1);
		quickSort2(A,q+1,r);
	}	
}

int main(){
	int i=100000;
	int *A;	
	A = (int *)malloc (i * sizeof (int));
	for(int k=0;k<i;k++)
			A[k]=i-k;	
	clock_t start = clock();
	quickSort2(A,0,i-1);
	printf("Tamanho vetor: %d - time: %lf\n",i,(double)(clock()-start)/CLOCKS_PER_SEC);
	for(int k=0;k<i;k++)
			printf("%d ",A[k]);
	free(A);
	return 0;
}


