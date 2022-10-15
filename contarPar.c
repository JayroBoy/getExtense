/*Programinha que recebe uma expressão aritmetica e 
informa se todos os parenteses estão em par

Usa uma pilha.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 1000

typedef struct no{
	struct no* next;
}no;


no *push(no *pilha){
	no *new = (no*)malloc(sizeof(no));
	new->next = pilha;
	return new;
}

int pop(no **pilha){
	if(*pilha == NULL){
		return 0;
	}
	no *aux = (*pilha)->next;
	free(*pilha);
	*pilha = aux;
	return 1;
}


int main(void){
	char expressao[SIZE];
	no *pilha = NULL;
	scanf("%s", expressao);
	
	for(int i = 0; i < strlen(expressao); i++){
		if(expressao[i] == '(') pilha = push(pilha);
		else if(expressao[i] == ')'){ 
			if(!pop(&pilha)){
				printf("ERRO! FECHOU UM PARÊNTESE QUE NÃO TINHA ABERTO!\n");
				return 0;
			}	
		}
	}
	
	if(pilha != NULL){ 
		printf("ERRO! ABRIU PARÊNTESES E NÃO FECHOU!\n");
		while(pop(&pilha)); //Roda até pilha ser NULL
	}
	
	return 0;
}
		