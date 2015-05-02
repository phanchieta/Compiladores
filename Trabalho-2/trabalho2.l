%{
#include "y.tab.h"
#include "hash.h"
#include <math.h>


%}	
	

%%

")"								return PARENTESES_DIREITO;
"("								return PARENTESES_ESQUERDO;
[a-zA-Z]+[a-zA-Z_0-9]*						return IDENTIFICADOR;
[\t\n]								;
.								;
								
%%


int yywrap(){return 1;}

