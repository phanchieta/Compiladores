%{
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include "hash.h"

%}

			         /* Yacc definitions */
%start programa
%token PARENTESES_ESQUERDO
%token PARENTESES_DIREITO
%token IDENTIFICADOR

%%

/* descriptions of expected inputs     corresponding actions (in C) */
programa	:"program" IDENTIFICADOR ';' corpo'.' {printf ("Primeira linha\n");} ;
corpo		:"begin" comandos "end" {printf ("Segunda linha\n");} ;
comandos	:"write" PARENTESES_ESQUERDO IDENTIFICADOR PARENTESES_DIREITO {printf ("Terceira linha\n");} ;

%%                     /* C code */
int main (void)
{

	return yyparse();

}
void yyerror (char *s) {fprintf (stderr, "%s\n", s);} 
