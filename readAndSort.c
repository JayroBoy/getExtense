#include<stdio.h>
#include<stdlib.h>


void readSize(int *size){
	printf("Informe o tamanho do vetor: ");
	scanf("%d", size);
	return;
}

void allocateArray(int **a, int size){
	*a = (int*)malloc(size * sizeof(int));
	return;
}

int *allocate(int size){
	int *a;
	a = (int*)malloc(size * sizeof(int));	
	return a;
}	

void readNumbers(int *a, int size){
	printf("Informe os %d números:\n", size);
	for(int i = 0; i < size; i++){
		scanf("%d", &a[i]);
	}
	return;
}

void swap(int *a, int n, int m){
	int aux;
	aux = a[n];
	a[n] = a[m];
	a[m] = aux;
	return;
}

//bubble sort
void sort(int *a, int size){
	int aux;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size-1; j++){
			if(a[j] > a[j + 1]){
				swap(a, j, j+1);
			}
		}	
	}
	return;
}


void printArray(int *a, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}

int main(void){
	int *a,
		size;
	readSize(&size);
	allocateArray(&a, size);
	readNumbers(a, size);
	sort(a, size);
	printArray(a, size);
	free(a);
	
	return 0;
}