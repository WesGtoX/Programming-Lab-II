Fun��o com passagem de par�metro por refer�ncia

Cria��o da fun��o:

Sintaxe:

tipo_da_fun��o nome_da_fun��o(tipo_do_ponteiro nome_do_ponteiro, ...) {
	//instru��es da fun��o
}

Chamada da fun��o
nome_da_fun��o(&nome_da_vari�vel, ...);

Exemplo:
	
Cria��o da fun��o:

void troca(int *a, int *b) {
	//instru��es para trocar
}


Chamada da fun��o:

troca(&v1, &v2);
