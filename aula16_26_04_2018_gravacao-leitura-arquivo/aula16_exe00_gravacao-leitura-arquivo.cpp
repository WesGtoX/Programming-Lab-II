Armazenamento de arquivos

Modos de abertura de arquivos
w - abre um arquivo para escrita em modo texto, sempre cria o arquivo.
a - abre um arquivo para escrita em modo texto, contudo s� cria o arquivo 
	se ele n�o existir, caso o arquivo exista, 
	as informa��es s�o armazenadas a partir do fim do arquivo.
r - abre um arquivo para leitura em modo texto.

fwrite() - utilizado para gravar as informa��es em arquivo em formato de registro.
fread() - utilizado para ler as informa��es em arquivo em formato de registro.

fwrite()
Sintaxe:
fwrite(endere�o_da_estrutura, tamanho_estrutura, quantidade_de_itens_da_estrutura, ponteiro_arquivo);

struct aluno {
	int codigo;
	char nome[30];
};

struct aluno engenharia;

fwrite(&engenharia, sizeof(engenharia), 1, arquivo);

fread()
Sintaxe:
fread(endere�o_da_estrutura, tamanho_estrutura, quantidade_de_itens_da_estrutura, ponteiro_arquivo);

while(fread(&engenharia, sizeof(engenharia), 1, arquivo) == 1)
