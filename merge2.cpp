#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void intercala(int *A, int p,int q,int r){
	int i,j=0,k;
	int B[r-p+1];
	for(i=p;i<=q;i++)
		B[j++]=A[i];
	for(i=r;i>=q+1;i--)
		B[j++]=A[i];
	i=0;
	j=r-p;
	for(k=p;k<=r;k++){
		if(B[i]<B[j]){
			A[k]=B[i];
			i++;
		}
		else{
			A[k]=B[j];
			j--;
		}
	}
}

void mergeSort2(int *A,int p,int r){
	if(p<r){
		int q = (p+r)/2;
		mergeSort2(A,p,q);
		mergeSort2(A,q+1,r);
		intercala(A,p,q,r);	
	}

}

int main(){
	int i=100;
	int *A;	
	A = (int *)malloc (i * sizeof (int));
	//Pior caso:
	for(int k=0;k<i;k++)
			A[k]=i-k;	
	clock_t start = clock();
	mergeSort2(A,0,i-1);
	printf("Tamanho vetor: %d - time: %lf\n",i,(double)(clock()-start)/CLOCKS_PER_SEC);
	for(int k=0;k<i;k++)
			printf("%d ",A[k]);
	free(A);
	return 0;
}


