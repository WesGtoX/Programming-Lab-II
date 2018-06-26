#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
	char nome[30];
	float salario;
}pessoa;

#define MAX 3

//declaração das variaveis
struct pessoa cliente[MAX];
int i, j, flag = 0;
struct pessoa aux;

//declação da função principal
main() {
	for(i=0; i < MAX; i++) {
		system("cls");
		printf("Informe o nome: ");
		fflush(stdin);
		gets(cliente[i].nome);
		printf("Informe o Salario: ");
		scanf("%f",&cliente[i].salario);
	}
	
	//ordenação alfabetica
	for(i=0; i < MAX; i++) {
		for(j=i+1; j < MAX; j++) {
			if(strcmp(cliente[i].nome,cliente[j].nome) > 0) {
				strcpy(aux.nome, cliente[i].nome);
				strcpy(cliente[i].nome, cliente[j].nome);
				strcpy(cliente[j].nome, aux.nome);
				aux.salario = cliente[i].salario;
				cliente[i].salario = cliente[j].salario;
				cliente[j].salario = aux.salario;
			}
		}
	}
	
	//mostrar dados ordenados
	for(i=0; i < MAX; i++) {
		printf("\nNome: %s - \tR$ %.2f",cliente[i].nome,cliente[i].salario);
	}
	printf("\n");
	system("pause");
	
	//alteração
	system("cls");
	printf("Informe o nome que deseja alterar: ");
	fflush(stdin);
	gets(aux.nome);
		
	for(i=0; i < MAX; i++) {
		if(strcmp(aux.nome,cliente[i].nome) == 0) {
			//imprimir o valor encontrado
			printf("\nNome: %s - \tR$ %.2f", cliente[i].nome,cliente[i].salario);
			printf("\nInforme o novo nome: ");
			fflush(stdin);
			gets(aux.nome);
			printf("Informe o novo salario: ");
			scanf("%f", &cliente[i].salario);
			flag = 1;
		}
	}
	if(flag == 0) {
		printf("Nome nao cadastrado...");
	}
}
