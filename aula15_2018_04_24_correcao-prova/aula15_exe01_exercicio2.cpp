//Exercício 2

//libraries
#include <stdio.h>
#include <stdlib.h>

#define MAX 5
//struct
struct empresa {
	int melhoria, satisfacao;
	float valor;
};

struct empresa pesquisa[10];

//function coleta
void coleta(struct empresa pesquisa[]) {
	//local variables
	int i;
	for(i=0; i < MAX; i++) {
		system("cls");
		printf("Informe o indice de melhoria da empresa (1 a 5): ");
		scanf("%i", &pesquisa[i].melhoria);
		if(pesquisa[i].melhoria < i && pesquisa[i].melhoria > 5) {
			printf("\n*** Indice invalido...***\n");
			system("pause");
			i--;
		}
		printf("Informe o grau de satisfacao (1 a 5): ");
		scanf("%i", &pesquisa[i].satisfacao);
		if(pesquisa[i].satisfacao < i && pesquisa[i].satisfacao > 5) {
			printf("\n*** Grau invalido...***\n");
			system("pause");
			i--;
		}
		printf("Informe o valor custo/beneficio: ");
		scanf("%f", &pesquisa[i].valor);
	}
}

int melhoria(struct empresa pesquisa[]) {
	//local variables
	//int indice1=0, indice2=0, indice=3, indice4=0, indice5=0, maior=0;
	int i, maior, resultado, indice[5] = {0,0,0,0,0,};
	for(i=0; i < MAX; i++) {
		if(pesquisa[i].melhoria == 1) {
			indice[0]++;
		}
		else if(pesquisa[i].melhoria == 2) {
			indice[1]++;
		}
		else if(pesquisa[i].melhoria == 3) {
			indice[2]++;
		}
		else if(pesquisa[i].melhoria == 4) {
			indice[3]++;
		}
		else {
			indice[4]++;
		}
	}	
		//inicializar o maior
		maior = indice[0];
		resultado = 1;
		for(i=0; i < MAX; i++) {
			if(indice[i] > maior) {
				maior = indice[i];
				resultado = i+1;
			}
		}
		return resultado;
}

//media function
float media(struct empresa pesquisa[]) {
	//local variables
	int i, soma=0;
	for(i=0; i < MAX; i++) {
		soma+= pesquisa[i].satisfacao;
	}
	return float(soma)/MAX;
}

float menor(struct empresa pesquisa[]) {
	//local variables
	int i;
	float menor;
	menor = pesquisa[0].valor;
	for(i=1; i < MAX; i++) {
		if(pesquisa[i].valor < menor) {
			menor = pesquisa[i].valor;
		}
	}
	return menor;
}

//main function
main() {
	coleta(pesquisa);
	
	printf("\nIndice de melhoria mais encontrado: %i", melhoria(pesquisa));
	printf("\nMedia grau de satisfacao: %.1f", media(pesquisa));
	printf("\nMenor custo / beneficio: %.2f", menor(pesquisa));
	system("pause");
}
