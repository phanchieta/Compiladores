%{
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include "hash.h"
#include "lex.yy.h"

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
%token PALAVRA_RESERVADA
%token COMENTARIO
%token NUMERO_INT_MAL_FORMADO
%token NUMERO_REAL_MAL_FORMADO
%token CARACTERES_INVALIDOS
%token VAR

%%
/* descriptions of expected inputs     corresponding actions (in C) */
programa	: PALAVRA_RESERVADA VAR PONTO_E_VIRGULA corpo PONTO {printf ("Primeira regra\n"); } ;
corpo		: PALAVRA_RESERVADA comandos PALAVRA_RESERVADA {printf ("Segunda regra\n");} ; 
comandos	: PALAVRA_RESERVADA PARENTESES_ESQUERDO VAR PARENTESES_DIREITO PONTO_E_VIRGULA {printf ("Terceira regran");} ;
%%                     /* C code */

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 
