/*	
 Recursão
	1 - O que é recursão?
	2 - Quais os elementos de uma recursão?
	3 - Quando eu devo usar uma recursão?
	4 - Quais as desvantagens de uma recursão?
*/

/*1 - Recursão é um método alternativo de programação no qual eu 
	estabeleço uma repetição por meio de funções em vez de por 
	meio de loops. Apesar do nome, não necessariamente uma recursão
	começa do final e vai para o início.
	
  2 - Os elementos básicos de uma recursão são:
		Caso base ou Condição de parada
		Passo recursivo
		
  3 - Em geral, quando seu problema requer divisão do problema em pedaços
  menores que são o mesmo problema, a semantica de recursão vai surgir 
  naturalmente. Um exemplo disso é o mergeSort, mas o mais clássico 
  é a sequência de fibonacci. Recursões costumam ser mais fáceis de 
  escrever também, então se a sua limitação de tempo for maior pra o 
  programador do que pra o computador, faz sentido escrever um código
  recursivo.
  
  4 - Quase sempre, a recursão é mais lenta do que a iteração. Isso
  acontece por que chamadas de função quebram o fluxo do programa,
  o que tem um custo no processador. Além disso, recursões SEMPRE
  consomem mais memória do que iterações, já que cada nova chamada
  de função reinstancia os seus argumentos. Uma função que tenha 
  como argumento apenas um ponteiro de char, e que percorra esse
  vetor de char até chegar ao final, por exemplo, se for iterativa
  terá um custo de memória de sizeof(char*) - O tamanho do ponteiro,
  + 2 * sizeof(int) - O tamanho do iterador e da variavel que armazena
  o tamanho da string. A mesma função escrita de forma recursiva terá
  um custo de memória de stringSize * (sizeof(char*) + sizeof(int)),
  já que descarta o iterador porém é chamada stringSize vezes.
 
 */
	
	

#include <stdio.h>
#include <stdlib.h>

long long int recFib(int n)
{
    //Base case
    if (n == 0) return 0;
  
    //Base case
    if (n == 1) return 1;
  
	//Recursive step
    return (recFib(n - 1) + recFib(n - 2));
}
  
long long int itFib(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
	
	//N >= 2
	long long int *fibs,
				   ans;
	
	fibs = (long long int*)calloc(n + 1, sizeof(long long int));
	
	fibs[0] = 0;
	fibs[1] = 1;
	
	for(int i = 2; i <= n; i++){
		fibs[i] = fibs[i-1] + fibs[i-2];
	}
	
	ans = fibs[n];
	
	free(fibs);
	
	return ans;
}



int main(void){
	int n;
	char s[4] = "sim";
		
	while(s != "Não" && s != "não" && s != "nao" && s!= "não"){
		printf("Digite um número: ");
		scanf("%d", &n);
		printf("Versão iterativa: %lld\n", itFib(n));
		printf("Versão recursiva: %lld\n", recFib(n));
		printf("Mais um? ");
		scanf("%s", s);
	}
	
    return 0;
}