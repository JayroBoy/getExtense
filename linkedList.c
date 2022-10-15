#include<stdio.h>
#include<stdlib.h>

typedef int elem;

typedef struct foo{
	int chave;
	struct foo *prox;
}no;


no *alocaElemento(){
	no *resultado;
	resultado = (no*)malloc(sizeof(no));
	resultado->prox = NULL;
	return resultado;
}	

/*Função que remove o primeiro nó com a chave valor da lista*/
no* removeElemento(int valor, no* inicio){
	no *runner,
		*auxiliar;
	
	//Se o elemento que queremos remover for o primeiro
	if(inicio != NULL && inicio->chave == valor){
		auxiliar = inicio->prox;
		free(inicio);
		return auxiliar;
	}
	
	
	
	//Se o elemento que queremos remover for algum subsequente
	auxiliar = inicio;
	runner = inicio->prox;
	
	//Percorrer a lista até o fim
	while(runner != NULL){
		if(runner->chave == valor){ //Se acharmos o valor
			auxiliar->prox = runner->prox; //Remover o nó da lista
			free(runner); //Liberar a memória
			return inicio; //Devolver o ponteiro de inicio da lista
		}
		
		//Passar pra o proximo par
		auxiliar = runner; 
		runner = runner->prox;
	}
}

no* removeTodasVezes(int valor, no *lista){
	no *inicio = lista,
		*runner = lista;
	
	int contar = 0;
	
	//Contar quantas vezes o valor aparece na lista
	while(runner != NULL){
		if(runner->chave == valor) contar++;
		runner = runner->prox;
	}
	
	//Remover a primeira ocorrência do valor na lista até não ter mais ocorrências
	for(int i = 0; i < contar; i++) inicio = removeElemento(valor, inicio);

	return inicio;
}

void freeList(no *l){
	no *um, *dois;
	
	um = l;
	
	while(um->prox != NULL){
		dois = um->prox;
		free(um);
		um = dois;
	}
	free(dois);
	
	return;
}

void addNewNode(no *lista){
	int newKey;
	no *runner = lista;
	
	while(runner->prox != NULL){
		runner = runner->prox;
	}

	scanf("%d", &newKey);
	runner->prox = alocaElemento();
	runner->prox->chave = newKey;
	
	return;
}
	
void printList(no *lista){
	/*Função que imprime toda a lista*/
	no *iterator = lista;
	
	while(iterator != NULL){
		printf("%d ", iterator->chave);
		iterator = iterator->prox;
	}
	
	printf("\n");
	
	return;
}

int main(void){
	int n,
		sel = 1;
	no *lista,
	   *corredor;
	printf("Digite o tamanho da lista: ");
	scanf("%d", &n);
	
	lista = alocaElemento();
	corredor = lista;
	
	for(int i = 0; i < n; i++){
		corredor->chave = i%5;
		corredor->prox = alocaElemento();
		corredor = corredor->prox;
	}
	
	corredor->chave = n%3;
	
	printf("Lista criada:\n");
	printList(lista);
	
	lista = removeElemento(2, lista);	
	printf("Após remoção de 1 elemento: \n");
	printList(lista);
	
	lista = removeTodasVezes(2, lista);
	printf("Após remoção de todas as ocorrencias do elemento: \n");
	printList(lista);

	while(sel){
		printf("Digite um valor para adicionar: ");
		addNewNode(lista);
		printf("Novamente?(1|0): ");
		scanf("%d", &sel);
	}
	
	printf("Após inserções: \n");
	printList(lista);
	
	sel = 1;
	while(sel){
		printf("Digite um valor para remover: ");
		scanf("%d", &n);
		printf("Deseja remover todas as ocorrências ou só a primeira?(0 para todas, 1 para a primeira)\n");
		scanf("%d", &sel);
		
		if(sel){
			lista = removeElemento(n, lista);
		}else{
			lista = removeTodasVezes(n, lista);
		}
		
		printf("Novamente?(1|0): ");
		scanf("%d", &sel);
	}
	
	printf("Após remoções:\n");
	printList(lista);
	
	freeList(lista);
	return 0;
}
	