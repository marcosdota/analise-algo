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

int binary_search(int *A, int n, int k){
	int l=1,r=n,m;
	while(l<=r){
		m = (l+r)/2;
		if(A[m]>k)
			r=m-1;
		else if(A[m]==k)
			return m;
		else if(A[m]<k)
			l=m+1;
	}
	return -1;
}


int main(){
	int i=50000,j;
	int *A;	
	A = (int *)malloc (i * sizeof (int));
	//Pior caso:
	for(int k=0;k<i;k++)
			A[k]=i-k;	
	//Escolha:
	selection(A,i);
	//insertion(A,i);
	
	//Busca binária:
	clock_t start = clock();
	j=binary_search(A,i,A[i-1]);
	printf("Valor: %d - Posicao vetor: %d - time: %lf\n",A[i-1],j,(double)(clock()-start)/CLOCKS_PER_SEC);
	free(A);
	return 0;
}
