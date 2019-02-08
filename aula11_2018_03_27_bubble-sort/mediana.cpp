/*implementar um programa para receber AT� 10 n�meros inteiros e mostrar qual � o valor mediano*/

//bibliotecas e constantes
#include<stdio.h>
#include<stdlib.h>
#define M 10

//vari�veis locais
int j,num[M],tam,i;


//fun��o de ordena��o
void cres(int vetor[M]){
	
	//variavel local
	int aux;
	//estrutura de ordena��o
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

//fun��o mediana
float mediana(float dimensao){
	
	//variaveis locais
	float mediana = (dimensao+1)/2;
		
	return mediana;
}

//fun��o principal
main(){
	tam = M;
	
	//defini��o do tamanho do vetor
	printf("\nInforme a quantidade de numeros que deseja inserir:\n");
	scanf("%i",&tam);
	if(tam<2 or tam>M){
		printf("Inv�lido");
		exit(0);
	}
	system("cls");
	
	//entrada de dados
		for(j=0;j<tam;j++){
			
			printf("\nInforme um valor\n");
			scanf("%i",&num[j]);
			system("cls");		
			}		
			
	//chamada da fun��o de ordena��o
	cres(num);
	printf("\nVetor ordenado corretamente:\n");
	//impress�o do vetor ordenado
	for(j=0;j<tam;j++){
	printf("%i",num[j]);
	}
	//chamada e exibi��o do valor fun��o mediana
	printf("\n\nO valor da mediana e %.2f\n\n",mediana(tam));
	
	return(0);
}



