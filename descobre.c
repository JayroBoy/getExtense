#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct pilha{
	int valor;
	struct pilha *next;
}pilha;

typedef struct fila{
	int valor;
	struct fila *next,
				*previous;
}fila;


void pushFila(fila **inicio, fila **fim, int valor){
	//printf("	Fazendo push na fila...\n");
	fila *new = (fila*)malloc(sizeof(fila));
	new->valor = valor;
	new->next = NULL;
	new->previous = NULL;
	
	if((*fim) == NULL){
		*inicio = new;
		*fim = new;
		return;
	}
	
	(*fim)->next = new; //Adiciona ele ao fim da fila
	new->previous = *fim; //Adiciona o resto da fila na frente dele
	*fim = new; //Marca o novo fim da fila
	return;
}

void pushPilha(pilha **topo, int valor){
	//printf("	Fazendo push na pilha...\n");
	pilha *new = (pilha*)malloc(sizeof(pilha));
	new->valor = valor;
	new->next = NULL;
	
	if(*topo == NULL){
		*topo = new;
		return;
	}
	
	new->next = *topo; //Coloca a pilha embaixo dele
	*topo = new; //Marca o novo topo da pilha
	return;
}

int popPilha(pilha **topo){
	//printf("	Removendo da pilha...\n");
	if(*topo == NULL) return 11;
	
	int valorDoPop;
	pilha *novoTopo;
	
	novoTopo = (*topo)->next;
	valorDoPop = (*topo)->valor;
	
	free((*topo));
	*topo = novoTopo;
	
	return valorDoPop;
}


int popFila(fila **inicio, fila **fim){
	//printf("	Removendo da fila...\n");
	if(*inicio == NULL) return 11;
	
	int valorDoPop;
	fila *novoInicio;
	
	valorDoPop = (*inicio)->valor;
	novoInicio = (*inicio)->next;
				
	if(novoInicio != NULL){
		novoInicio->previous = NULL;
	}else{
		*fim = NULL;
	}
	
	free(*inicio);
	*inicio = novoInicio;
	
	return valorDoPop;
}


void esvaziaFila(fila **inicio, fila **fim){
	while(*inicio != NULL){
		popFila(inicio, fim);
	}
	return;
}

void esvaziaPilha(pilha **topo){
	while(*topo != NULL){
		popPilha(topo);
	}
	return;
}

void acharEstrutura(int nOp){
	int valor;
	char op;
	pilha *topo = NULL;
	fila *inicio = NULL,
		 *fim = NULL;
	bool isPilha = true,
		 isFila = true;
	
	for(int i = 0; i < nOp; i++){
		scanf("%c", &op);
		scanf("%c %d", &op, &valor);
		//printf("Operação: %c, valor: %d\n", op, valor);
		if(op == 'i'){
			pushPilha(&topo, valor);
			pushFila(&inicio, &fim, valor);
		}else{
			if(popPilha(&topo) != valor) isPilha = false;
			if(popFila(&inicio, &fim) != valor) isFila = false;
		}
	
	}
	if(!isPilha && !isFila){ /*Se as duas são falsas*/
		printf("impossivel\n");
	}else if(!isPilha){ /*Se não for pilha, é fila*/
		printf("fila\n");
	}else if(!isFila){ /*Se não for fila, é pilha*/
		printf("pilha\n");
	}else{ /*Caso contrário não há como saber qual é*/
		printf("indefinido\n");
	}
	
	esvaziaFila(&inicio, &fim);
	esvaziaPilha(&topo);
	return;
}

int main(){
	int casosDeTeste,
		nOperacoes;
		
	scanf("%d", &casosDeTeste);
	
	while(casosDeTeste){
		casosDeTeste--;
		scanf("%d", &nOperacoes);
		acharEstrutura(nOperacoes);
	}
	
	return 0;
}