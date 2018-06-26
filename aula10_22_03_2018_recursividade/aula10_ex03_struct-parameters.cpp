/*Algoritmo para exemplificar o uso de passagem de estrutura de dados por
parâmetro por valor.
Receber o registro das notas de 10 alunos, sendo informado o nome, a nota
parcial e a nota final */

//libraries
#include <stdio.h>
#include <stdlib.h>

//struc tdata
struct aluno {
	char nome[30];
	float notap, notaf;
};
typedef struct aluno aluno;

//constant
#define LIM 5

//register function
void cadaluno(aluno turma[]) {
	//local variables
	int i;
	
	//data entry
	for(i=0; i<LIM; i++) {
		printf("\nInforme o nome do aluno: ");
		fflush(stdin);
		gets(turma[i].nome);
		
		printf("Informe a nota parcial: ");
		scanf("%f", &turma[i].notap);
		printf("Informe a nota final: ");
		scanf("%f", &turma[i].notaf);
	}
}

//class average function
float mediaturma(aluno turma[]) {
	//local variables
	int i;
	float soma=0;
	
	//average calculation
	for(i=0; i<LIM; i++) {
		soma+=(turma[i].notap * 0.4) + (turma[i].notaf * 0.6);
		
	return soma / LIM;
	}
}

//menu function
void menu() {
	//local variables
	int opcao;
	
	//struct data
	aluno alunos[LIM];
	
	system("cls");
	
	printf("*** MENU ***");
	printf("\n\n1 - Cadastrar\n2 - Listar\n3 - Media da sala\n0 - Sair\n\n");
	printf("Escolha uma opcao: ");
	scanf("%i", &opcao);
	
	switch(opcao) {
		case 1 : {
			cadaluno(alunos);
		}
		menu();
		case 2 : {
			exit(0);
		}
		case 3 : {
			printf("Media da sala = %.2f\n\n", mediaturma(alunos));
			system("pause");
		}
		case 0 : {
			exit(0);
		}
		default : {
			printf("\nOpcao Invalida...\n\n");
		}
		system("pause");
		menu();
	}
}

//main function
main() {
	
	menu();
}

