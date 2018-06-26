/*implementar um programa para receber ATÉ 10 números inteiros e mostrar qual é o valor mediano*/

//bibliotecas e constantes
#include<stdio.h>
#include<stdlib.h>
#define M 10

//variáveis locais
int j,num[M],tam,i;


//função de ordenação
void cres(int vetor[M]){
	
	//variavel local
	int aux;
	//estrutura de ordenação
	for(i=0;i<tam;i++){
		for(j=i+1;j<tam;j++){
			if(vetor[i]>vetor[j]){
				aux = vetor[i];
				vetor[i] = vetor[j];
				vetor[j] = aux;
			}
		}
	}
}

//função mediana
float mediana(float dimensao){
	
	//variaveis locais
	float mediana = (dimensao+1)/2;
		
	return mediana;
}

//função principal
main(){
	tam = M;
	
	//definição do tamanho do vetor
	printf("\nInforme a quantidade de numeros que deseja inserir:\n");
	scanf("%i",&tam);
	if(tam<2 or tam>M){
		printf("Inválido");
		exit(0);
	}
	system("cls");
	
	//entrada de dados
		for(j=0;j<tam;j++){
			
			printf("\nInforme um valor\n");
			scanf("%i",&num[j]);
			system("cls");		
			}		
			
	//chamada da função de ordenação
	cres(num);
	printf("\nVetor ordenado corretamente:\n");
	//impressão do vetor ordenado
	for(j=0;j<tam;j++){
	printf("%i",num[j]);
	}
	//chamada e exibição do valor função mediana
	printf("\n\nO valor da mediana e %.2f\n\n",mediana(tam));
	
	return(0);
}



