//Exemplo de declaração e inicialização de uma matriz

//libraries
#include <stdio.h>
#include <stdlib.h>

//variables
int matriz[5][5]; //array
int x, y; //array control variable

//main function
main() {
	//array init
	for(x=0;x<5;x++) {
		for(y=0;y<5;y++) {
			matriz[x][y]=0;
		}
	}
	
	//show array init
	for(x=0;x<5;x++) {
		for(y=0;y<5;y++) {
			printf("%i ", matriz[x][y]);
		}
		printf("\n");
	}
}
