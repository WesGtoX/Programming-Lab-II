/* Produto escalar - fun��o bin�ria que devolve a rela��o entre dois vetores por meio de um n�mero real. 
Equa��o: produto escalar = E(soma)vetor1[i] * vetor2[i]

Implementar fun��o para retornar o produto escalar de dois vetores */


//libraries
#include <stdio.h>
#include <stdlib.h>

//constant
#define MAX 3

//declara��o da fun��o inserir no vetor
void inserir(int vetor[], int tamanho) {
	int i;
	for(i=0; i<tamanho; i++) {
		printf("Informe um numero inteiro: ");
		scanf("%i", &vetor[i]);
	}
}

//declara��o da fun��o prod_e
int escalar(int vetorA[], int vetorB[], int tamanho) {
	int i, n=0;
	for(i=0; i<tamanho; i++) {
		n += vetorA[i] * vetorB[i];
	}
	return n;
}

//main function
main() {
	//local variables
	int vetorA[MAX], vetorB[MAX];
	
	//function call for register vector A
	inserir (vetorA,MAX);
	
	//function call for register vector B
	inserir (vetorB,MAX);
	
	//show sum
	printf("Produto escalar = %i\n\n",escalar(vetorA,vetorB,MAX));
	
	system("pause");
}
