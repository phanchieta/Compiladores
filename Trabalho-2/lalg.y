
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
%token MENOR_MAIOR
%token MAIOR
%token MENOR
%token MAIS
%token MENOS
%token VEZES
%token DIVIDIDO
%token VIRGULA
%token PONTO_E_VIRGULA
%token PONTO
%token DOIS_PONTOS
%token PARENTESES_ESQUERDO
%token PARENTESES_DIREITO
%token NUM_INTEIRO
%token NUM_REAL
%token COMENTARIO
%token NUMERO_INT_MAL_FORMADO
%token NUMERO_REAL_MAL_FORMADO
%token CARACTERES_INVALIDOS
%token PROGRAM
%token START /*Use start instead of begin since flex already defined begin previously*/
%token END
%token CONST
%token VAR
%token REAL
%token INTEGER
%token PROCEDURE
%token ELSE
%token READ
%token WRITE
%token WHILE
%token DO
%token IF
%token THEN 
%token FOR
%token TO 
%token IDENT

%%
/* descriptions of expected inputs     corresponding actions (in C) */
programa	: PROGRAM IDENT PONTO_E_VIRGULA corpo PONTO {printf ("Primeira regra\n"); } ;
corpo		: dc START comandos END {printf ("Segunda regra\n");} ; 
dc		: dc_c dc_v dc_p;
dc_c		: CONST IDENT IGUAL numero PONTO_E_VIRGULA dc_c | empty;
dc_v		: VAR variaveis DOIS_PONTOS tipo_var PONTO_E_VIRGULA dc_v | empty;
tipo_var	: REAL | INTEGER ;
variaveis	: IDENT mais_var ;
mais_var	: VIRGULA variaveis | empty;
dc_p		: PROCEDURE IDENT parametros PONTO_E_VIRGULA corpo_p dc_p | empty;
parametros	: PARENTESES_ESQUERDO lista_par PARENTESES_DIREITO | empty;
lista_par	: variaveis DOIS_PONTOS tipo_var mais_par ;
mais_par	: PONTO_E_VIRGULA lista_par | empty;
corpo_p		: dc_loc START comandos END PONTO_E_VIRGULA ;
dc_loc		: dc_v ;
lista_arg	: PARENTESES_ESQUERDO argumentos PARENTESES_DIREITO | empty;
argumentos	: IDENT mais_ident ;
mais_ident	: PONTO_E_VIRGULA argumentos | empty;
pfalsa		: ELSE cmd | empty;
comandos	: cmd PONTO_E_VIRGULA comandos | empty;
cmd		: READ PARENTESES_ESQUERDO variaveis PARENTESES_DIREITO
		| WRITE PARENTESES_ESQUERDO variaveis PARENTESES_DIREITO
		| WHILE PARENTESES_ESQUERDO condicao PARENTESES_DIREITO DO cmd
		| FOR expressao TO condicao cmd
		| IF condicao THEN cmd pfalsa
		| IDENT ATRIBUICAO expressao
		| IDENT lista_arg
		| START comandos END {printf ("CMD\n");};
condicao 	: expressao relacao expressao ;
relacao		: IGUAL | MENOR_MAIOR | MAIOR_IGUAL | MENOR_IGUAL | MAIOR | MENOR ;
expressao	: termo outros_termos ;
op_un		: MAIS | MENOS | empty;
outros_termos	: op_ad termo outros_termos | empty;
op_ad		: MAIS | MENOS ;
termo		: op_un fator mais_fatores ;
mais_fatores	: op_mul fator mais_fatores | empty;
op_mul		: VEZES | DIVIDIDO ;
fator		: IDENT | numero | PARENTESES_ESQUERDO expressao PARENTESES_DIREITO ;	
numero		: NUM_INTEIRO | NUM_REAL ;
empty		: ;


%%                     /* C code */

void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 
