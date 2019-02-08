Função com passagem de parâmetro por referência

Criação da função:

Sintaxe:

tipo_da_função nome_da_função(tipo_do_ponteiro nome_do_ponteiro, ...) {
	//instruções da função
}

Chamada da função
nome_da_função(&nome_da_variável, ...);

Exemplo:
	
Criação da função:

void troca(int *a, int *b) {
	//instruções para trocar
}


Chamada da função:

troca(&v1, &v2);
