#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void MaxHeapify(int *A,int m,int i){
	int e = 2*i;
	int d = 2*i+1;
	int maior,aux;
	if(e<=m && A[e]>A[i])
		maior = e;
	else
		maior = i;
	if(d<=m && A[d] > A[maior])
		maior = d;
	if(maior!=i){
		aux = A[i];
		A[i] = A[maior];
		A[maior] = aux;
		MaxHeapify(A,m,maior);
	}
}

void buildMaxHeap(int *A,int n){
	for(int i=n/2;i>=0;i--)
		MaxHeapify(A,n,i);
}

void heapsort(int *A,int n){
	buildMaxHeap(A,n);	
	int m = n,aux;
	for(int i=n;i>=1;i--){
		aux=A[0];
		A[0]=A[i];
		A[i]=aux;
		m--;
		MaxHeapify(A, m, 0);	
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
	heapsort(A,i);
	printf("Tamanho vetor: %d - time: %lf\n",i,(double)(clock()-start)/CLOCKS_PER_SEC);
	/*for(int k=0;k<i;k++)
			printf("%d ",A[k]);*/
	free(A);
	return 0;
}


