%{
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include "hash.h"

%}

			         /* Yacc definitions */
%start programa
%token ATRIBUICAO
%token IGUAL
%token MAIOR_IGUAL
%token MENOR_IGUAL
%token MAIOR
%token MENOR
%token MAIS
%token MENOS
%token VEZES
%token DIVIDIDO
%token VIRGULA
%token PONTO_E_VIRGULA
%token PONTO
%token PARENTESES_ESQUERDO
%token PARENTESES_DIREITO
%token NUM_INTEIRO
%token NUM_REAL
%token IDENTIFICADOR
%token COMENTARIO
%token NUMERO_INT_MAL_FORMADO
%token NUMERO_REAL_MAL_FORMADO
%token CARACTERES_INVALIDOS

%%
/* descriptions of expected inputs     corresponding actions (in C) */
programa	: IDENTIFICADOR IDENTIFICADOR PONTO_E_VIRGULA corpo PONTO {printf ("Primeira regra\n");} ;
corpo		: IDENTIFICADOR comandos IDENTIFICADOR {printf ("Segunda regra\n");} ; 
comandos	: IDENTIFICADOR PARENTESES_ESQUERDO IDENTIFICADOR PARENTESES_DIREITO {printf ("Terceira regra\n");} ;
%%                     /* C code */
int main (void)
{

	return yyparse();

}
void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 
