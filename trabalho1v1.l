%{

#include "hash.h"
#include <math.h>
#include "trabalho1.h"

%}	
	

%%
":="								return ATRIBUICAO;
"="								return IGUAL;
">="								return MAIOR_IGUAL;
"<="								return MENOR_IGUAL;
">"								return MAIOR;
"<"								return MENOR;
"+"								return MAIS;
"-"								return MENOS;
"*"								return VEZES;
"/"								return DIVIDIDO;
")"								return PARENTESES_DIREITO;
"("								return PARENTESES_ESQUERDO;
","								return VIRGULA;
";"								return PONTO_E_VIRGULA;
"."								return PONTO;
"{"[a-zA-Z]*"}"							return COMENTARIO;
[-]?[1-9][0-9]*							return NUM_INTEIRO;
[-]?[1-9][0-9]*"."[0-9][0-9]*|[-]?[0-9]+"."[0-9]+		return NUM_REAL;
[-]?[a-zA-Z]+[1-9][0-9]*[a-zA-Z0-9]*|[-]?[1-9][a-zA-Z]+[a-zA-Z0-9]*					return NUMERO_INT_MAL_FORMADO;
[-]?[a-zA-Z]+[1-9][0-9]*[a-zA-Z0-9]*"."[a-zA-Z0-9]*|[-]?[1-9][a-zA-Z]+[a-zA-Z0-9]*"."[a-zA-Z0-9]*|[-]?[1-9][0-9]*"."[a-zA-Z]+[a-zA-Z0-9]*|[-]?[1-9][0-9]*"."|[-]?[1-9][0-9]*"."[0-9]+[a-zA-Z]+[a-zA-Z0-9]* return NUMERO_REAL_MAL_FORMADO;
"@"+|"!"+|"#"+|"$"+|"%"+|"&"+|"?"+|"|"+"`"+|"'"+		return CARACTERES_INVALIDOS;
[\t\n]								;
[a-zA-Z]+[a-zA-Z_]*						return IDENTIFICADOR;
.								;
								
%%


int yywrap(){return 1;}

