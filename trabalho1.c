#include <stdio.h>
#include <string.h>
#include "trabalho1.h"
#include "hash.h"

extern char* yylex();
extern int yylineno;
extern char *yytext;
extern FILE *yyin;

void main(int argc, char *argv[]){

    ++argv, --argc; /* skip over program name */
	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;

	char* ntoken;//utilizaremos a variavel tipo_token para sabermos qual é o tipo do id

	int tamanho, id;//armazena o tamanho do token lido atualmente

	hash_table_t * table_palavras=NULL;//cria uma tabela hash com as palavras reservadas da linguaguem

	list_t * no;// recebe nó da hash com as palavras reservadas da linguaguem

	table_palavras = populate_list();//inicializa a tabela hash com as diversas palavras reservadas

	ntoken = yylex();//recebe o nome do token
					// iremos utilizar a hash para identificar qual tipo de token é, diferenciar se é um id
					// ou uma palavra reservada, ou algum outro token/erro identificado anteriormente

	while(ntoken){//enquanto não tiver acabado de ler todos os tokens do arquivo de entrada faça
        id = 0;
		tamanho = strlen(yytext);

        if( (strcmp(ntoken,IDENTIFICADOR)==0) && (tamanho<=MAX_TAM_IDENT)){//se for um identificador de tamanho valido,verifica atraves de uma
			//tabela hash se é uma palavra reservada ou simbolo da linguaguem ou um id.

			no=lookup_string(table_palavras, yytext);//recece o nó correspondente a ntoken da hash se for uma palavra reservada

			if (no!=NULL){
				// se no diferente de NULL então ele é uma palavra reservada, imprime o valor lido no identificador lexico
				//e o nome da palavra reservada que esta armazenado em no->string2
				printf("%s - %s - palavra reservada\n", yytext , no->string2);


			}else{
				// se não for encontrado na tabela então o token é um identificador definido pelo usuário
				printf("%s - %s\n", yytext , IDENTIFICADOR);

			}
		}else if (tamanho>MAX_TAM_IDENT){
			// Se o token lido for um id e tiver tamanho maior que o permitido

            printf ("%s - ERRO :Identificador excedeu tamanho limite\n", yytext);

			}

        else if ((strcmp(ntoken, NUMERO_INT_MAL_FORMADO))==0) //verifica se ha algum numero inteiro mal formado
			{
			    printf("%s - ERRO: %s\n", yytext, ntoken); //trata o erro para numero inteiro mal formado
			}
        else if ((strcmp(ntoken, NUMERO_REAL_MAL_FORMADO))==0) //verifica se ha algum numero real mal formado
			{
			    printf("%s - ERRO: %s\n", yytext, ntoken); //trata o erro para numero real mal formado
			}

        else if (tamanho<=MAX_TAM_IDENT && (strcmp(ntoken, COMENTARIO)!=0)) //se nao for comentario e for dentro dos padroes de tamanho
        {
            printf("%s - %s\n", yytext , ntoken); //imprime o token reconhecido e sua descricao

        }
        ntoken= yylex();//chama o analizador lexico novamente para obtermos um novo token

    }

 }


