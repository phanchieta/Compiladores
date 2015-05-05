%{

#include "y.tab.h"

#include "hash.h"

#include <math.h>


hash_table_t * tabela_palavras=NULL;



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

[a-zA-Z]+[a-zA-Z_]*						{
	if(lookup_string(tabela_palavras, yytext)==NULL) 
		return VAR;
	else return PALAVRA_RESERVADA;

}
[\t\n]								;

.								;

								

%%

int main (void)
{

	tabela_palavras=populate_list();
	
	return yyparse();

}



int yywrap(){return 1;}
