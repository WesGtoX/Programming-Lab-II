/*Algoritmo para gerenciar a alocação dos lugares de um teatro.
O teatro possui 100 lugares (10 cadeiras por 10 fileiras), o
valor zero representa cadeira vazio e o valor um representa
cadeira ocupada. O algoritmo deverá permitir a reserva de
lugares, assim o usuário informará o número da fileira e da
cadeira e o programa retornará se foi possível a reserva ou não*/

//libraries
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//variables
int teatro[10][10], cadeira, fileira, i, j;
char resposta;

//main function
main() {
	//array init
	for(i=0; i<10; i++) {
		for(j=0; j<10; j++)
			teatro[i][j]=0;
	}
	//repeat structure to reserve place
	do {
		//data entry
		printf("\nInforme a fileira (1-10): ");
		scanf("%i", &fileira);
		printf("\nInforme a cadeira (1-10): ");
		scanf("%i", &cadeira);
		
		if(teatro[fileira-1][cadeira-1]==0) {
			printf("\nLocal disponivel\nRESERVADO!\n");
			teatro[fileira-1][cadeira-1]=1;
		}
		else 
			printf("\nLOCAL OCUPADO...\nEscolha outro...\n");
		printf("\nDeseja escolher outro lugar <S/N>");
		resposta=getche();
	}while(resposta=='s'|| resposta=='S');
	
	printf("\n\n*** RESERVAS DO TEATRO ***\n");
	for(i=0; i<10; i++) {
		for(j=0; j<10; j++)
			printf("%i ", teatro[i][j]);
		printf("\n");
	}
}

