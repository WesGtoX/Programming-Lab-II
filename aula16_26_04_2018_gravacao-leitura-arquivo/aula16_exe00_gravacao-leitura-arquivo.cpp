Armazenamento de arquivos

Modos de abertura de arquivos
w - abre um arquivo para escrita em modo texto, sempre cria o arquivo.
a - abre um arquivo para escrita em modo texto, contudo só cria o arquivo 
	se ele não existir, caso o arquivo exista, 
	as informações são armazenadas a partir do fim do arquivo.
r - abre um arquivo para leitura em modo texto.

fwrite() - utilizado para gravar as informações em arquivo em formato de registro.
fread() - utilizado para ler as informações em arquivo em formato de registro.

fwrite()
Sintaxe:
fwrite(endereço_da_estrutura, tamanho_estrutura, quantidade_de_itens_da_estrutura, ponteiro_arquivo);

struct aluno {
	int codigo;
	char nome[30];
};

struct aluno engenharia;

fwrite(&engenharia, sizeof(engenharia), 1, arquivo);

fread()
Sintaxe:
fread(endereço_da_estrutura, tamanho_estrutura, quantidade_de_itens_da_estrutura, ponteiro_arquivo);

while(fread(&engenharia, sizeof(engenharia), 1, arquivo) == 1)
