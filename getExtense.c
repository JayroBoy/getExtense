//Jayro Boy V. Neto
//Programa que recebe números entre -9.223.372.036.854.775.807 e 9.223.372.036.854.775.807(considerando long long int como 64 bits) 

 
#include<stdio.h>
#include<stdlib.h>



//Recebe um número e imprime o nome da potência de mil associada a esse número, sem o final da palavra
void printSignificance(int counter){
	switch(counter){
		case 0:
			break;
		case 1:
			printf("mil");
			break;
		case 2: 
			printf("milh");
			break;
		case 3:
			printf("bilh");
			break;
		case 4:
			printf("trilh");
			break;
		case 5:
			printf("quadrilh");
			break;
		case 6:
			printf("quintilh");
			break;
		case 7:
			printf("sextilh");
			break;
		case 8:
			printf("septilh");
			break;
		case 9:
			printf("octilh");
			break;
		default:
			break;
	}
	return;
}

//Recebe um número de 0 a 9 e imprime a centena correspondente se for maior do que 0
int centenas(int number){
	switch(number){
		case 0:
			break;
		case 1:
			printf("cento ");
			break;
		case 2:
			printf("duzentos ");
			break;
		case 3:
			printf("trezentos ");
			break;
		case 4:
			printf("quatrocentos ");
			break;
		case 5:
			printf("quinhentos ");
			break;
		case 6:
			printf("seiscentos ");
			break;
		case 7:
			printf("setecentos ");
			break;
		case 8:
			printf("oitocentos ");
			break;
		case 9:
			printf("novecentos ");
			break;
	}
	return number;
}

//Recebe um número de 2 a 9 e imprime a dezena corresponde
int dezenas(int number){
	switch(number){
		case 2:
			printf("vinte ");
			break;
		case 3:
			printf("trinta ");
			break;
		case 4:
			printf("quarenta ");
			break;
		case 5:
			printf("cinquenta ");
			break;
		case 6:
			printf("sessenta ");
			break;
		case 7:
			printf("setenta ");
			break;
		case 8:
			printf("oitenta ");
			break;
		case 9:
			printf("noventa ");
			break;
	}
	return number;
}

//Recebe um número de 0 a 9 e imprime o nome por extenso se for maior do que 0
int unidades(int number){
	switch(number){
		case 0:
			break;
		case 1:
			printf("um ");
			break;
		case 2:
			printf("dois ");
			break;
		case 3:
			printf("tres ");
			break;
		case 4:
			printf("quatro ");
			break;
		case 5:
			printf("cinco ");
			break;
		case 6:
			printf("seis ");
			break;
		case 7:
			printf("sete ");
			break;
		case 8:
			printf("oito ");
			break;
		case 9:
			printf("nove ");
			break;
	}
	return number;
}	

//ElevenToNineteen
void elToNi(int number){
	switch(number){
		case 10:
			printf("dez ");
			break;
		case 11:
			printf("onze ");
			break;
		case 12:
			printf("doze ");
			break;
		case 13:
			printf("treze ");
			break;
		case 14:
			printf("catorze ");
			break;
		case 15:
			printf("quinze ");
			break;
		case 16:
			printf("dezesseis ");
			break;
		case 17:
			printf("dezessete ");
			break;
		case 18:
			printf("dezoito ");
			break;
		case 19:
			printf("dezenove ");
			break;
	}
	return;
}

//Recebe um número de 3 dígitos e imprime ele por extenso na tela
void toText(int number){
	
	if(number == 100){
		printf(" cem");
		return;
	}
	
	if(centenas(number/100) && number % 100 != 0) printf ("e "); //numero não tem só centenas
	number = number % 100;
	
	if(number >= 20){
		if(dezenas(number/10) && number % 10 != 0) printf ("e "); //numero restante não tem só dezenas
	}else if(number >= 10){
		elToNi(number);
		return;
	}
	
	number = number % 10;
	unidades(number);
	return;
}

//Função recursiva que analisa de 3 em 3 dígitos um determinado número
int recGetEx(unsigned long long int number, int counter){
	if(number == 0){ 
		return 0; //Caso base, acabou o número
	}
	
	recGetEx(number/1000, counter + 1); //Passo recursivo
	toText(number % 1000);
	
	printSignificance(counter);
	
	if(counter > 1){//Se o número for maior do que 999.999
		number % 1000 == 1? printf("ão") : printf("ões"); //Verifica se é singular ou plural e imprime apropriadamente o final da ordem de grandeza
	}
	
	if(counter > 0){//Se o número for maior do que 999
		number - ((number/1000) * 1000) != 0? printf(", ") : printf(""); //Imprime uma vírgula caso ainda haja dígitos menos significativos diferentes de 0
	}
	
	return 0;
}

//Função de controle de fluxo, recebe um número, trata 0 e 1000 e encaminha os demais para a solução recursiva
int getExtense(long long int number){
	if(number == 0){
		printf("Zero");
		return 0; //Corner case 1: Usaremos de caso base na recursão
	}
	
	if(number == 1000){
		printf("Mil");
		return 1000; //Corner case 2: Análise de 4 dígitos de uma vez, faremos de 3 em 3
	}
	
	if(number < 0){
		printf("Menos ");
		number = number * -1;
	}
	
	return recGetEx(number, 0); //Recursive Get Extense
}
	
int main(void){
	long long int numero;
	int cont = 1;

	while(cont == 1){
		printf("Digite um numero: ");
		scanf("%lld", &numero);
		getExtense(numero);
		printf("\nOutro? (1/0) ");
		scanf("%d", &cont);
	}
	
	return 0;
}	