#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void combina(int *A, int inicio,int meio,int fim){
	int n1 = meio-inicio+1;	//Quantidade de elementos em A[inicio..meio]	
	int n2 = fim-meio;		//Quantidade de elementos em A[meio + 1..fim]
	int B[n1],C[n2];		//Vetores Auxiliares
	int i,j,k;
	
	for(i=1;i<=n1;i++)
		B[i-1]=A[inicio+i-1];	//Copiando o conteúdo de A[inicio..meio] para B
	
	for(j=1;j<=n2;j++)
		C[j-1]=A[meio+j];		//Copiando o conteúdo A[meio + 1..fim] para C
	
	i=0;	//i manterá o índice em B do menor elemento ainda não copiado
	j=0;	//j manterá o índice em C do menor elemento ainda não copiado
	k=inicio;	//k manterá o índice em A da posição para onde um elemento será copiado
	
	while(i<n1 && j<n2){
		//Copia o menor dentre B[i] e C[j] para A[k]	
		if(B[i]<=C[j]){
			A[k]=B[i];
			i++;
		}
		else{
			A[k]=C[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		//Termina de copiar elementos de B, se houver
		A[k] = B[i];
		i++;
		k++;
	}
	
	while(j<n2){
		//Termina de copiar elementos de C, se houver 
		A[k]=C[j];
		j++;
		k++;
	}	
}

void mergeSort(int *A,int inicio,int fim){
	if(inicio<fim){
		int meio = (inicio+fim)/2;
		mergeSort(A,inicio,meio);
		mergeSort(A,meio+1,fim);
		combina(A,inicio,meio,fim);	
	}

}

int main(){
	int i=500000;
	int *A;	
	A = (int *)malloc (i * sizeof (int));
	//Pior caso:
	for(int k=0;k<i;k++)
			A[k]=i-k;	
	clock_t start = clock();
	mergeSort(A,0,i-1);
	printf("Tamanho vetor: %d - time: %lf\n",i,(double)(clock()-start)/CLOCKS_PER_SEC);
	/*for(int k=0;k<i;k++)
			printf("%d ",A[k]);*/
	free(A);
	return 0;
}


