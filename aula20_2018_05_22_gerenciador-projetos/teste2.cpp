void alterar(FILE *pont, int codigo)
{
struct jogo cad;
int sucesso=0;
[COLOR="Red"]

int posicao = 0; // inicio do arquivo

// usar fseek para ir ao inicio do arquivo pois
// voce pode estar adiante do registro que quer alterar

fseek(pont, posicao, SEEK_SET); 

[/COLOR]
do {
  if (fread(&cad,sizeof(struct jogo),1,pont) == 0)
    break;
  if (cad.codigo == codigo) 
   { 
    system("cls");
    
    printf("<<<<<Registro Antigo>>>>>\n\n");
    printf("Codigo............: %d\n",cad.codigo);
    printf("Jogo..............: %s\n",cad.nome_jogo);
    printf("Plataforma........: %s\n",cad.plataforma);
    printf("Desenvolvedor'a'..: %s\n",cad.desenvolvedor_a);
    printf("Ano...............: %d\n\n",cad.ano);
    
    printf("<<<<<Digite o Registro novo>>>>\n\n");
    printf("Código..........: ");
    scanf("%d", &cad.codigo);
    fflush(stdin);
    printf("Nome do Jogo....: ");
    gets(cad.nome_jogo);
    printf("Plataforma......: ");
    gets(cad.plataforma);
    printf("Desenvolvedor'a': "); 
    gets(cad.desenvolvedor_a);
    fflush(stdin);
    printf("Ano.............: ");
    scanf("%d", &cad.ano);
    fflush(stdin);
    
    cad.deletado=0;
    
[COLOR="red"]
    // quando você le o arquivo o ponteiro se desloca.
    // é necessario voltar para a posicao anterior a 
    // da leitura que é onde o registro começa

    fseek(pont, posicao, SEEK_SET);

    // agora sim, podemos gravar
    // e é melhor o sucesso estar condicionado a 
    // correta gravacao do registro (abaixo)
[/COLOR]
    sucesso= fwrite(&cad,sizeof(struct jogo),1,pont) == sizeof(struct jogo);
    break;
  }
[COLOR="Red"]
// ajustar posicao em relação ao inicio do arquivo
  posicao = posicao + sizeof(struct jogo);
[/COLOR]
} while(1);
if (!sucesso) 
  printf("Jogo não encontrado no arquivo\n");
system("pause");
} 
