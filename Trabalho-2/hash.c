#include "hash.h"

#include "y.tab.h"





hash_table_t *create_hash_table(int size)

{

    int i;

    hash_table_t *new_table;



    if (size<1) return NULL;



    /* Aloca memoria para a estrutura */

    if ((new_table = malloc(sizeof(hash_table_t))) == NULL) {

        return NULL;

    }



    /* Aloca memoria para o no da lista */

    if ((new_table->table = malloc(sizeof(list_t *) * size)) == NULL) {

        return NULL;

    }



    /*Inicia todos os ponteiros do array com NULL*/

    for(i=0; i<size; i++)

        new_table->table[i] = NULL;



    new_table->size = size;



    return new_table;

}



unsigned int hash(hash_table_t *hashtable, char *str)

{

    unsigned int hashval=0;

    for(; *str != '\0'; str++)

        hashval = *str + (hashval << 5) - hashval; /*Funcao hash*/



    /* Retorna um valor dentro do tamanho do array */



    return hashval % hashtable->size;

}



list_t *lookup_string(hash_table_t *hashtable, char *str)

{

    list_t *list;

    unsigned int hashval = hash(hashtable, str);



    /* Aplica a funcao hash e vai no valor.

     * Se achou a string, retorna o ponteiro para o elemento da lista.

     * Se nao achou, percorre a lista (por causa das colisoes)

     */

    for(list = hashtable->table[hashval]; list != NULL; list = list->next) {

        if (strcmp(str, list->string) == 0) return list;

    }

    return NULL; /*Se nao achou, retorna NULL*/

}



int add_string(hash_table_t *hashtable, char *str, int valor_string)

{

    list_t *new_list;

    list_t *current_list;

    unsigned int hashval = hash(hashtable, str);






    /* Aloca memoria para a lista */

    if ((new_list = malloc(sizeof(list_t))) == NULL) return 1;



    /* Verifica se o item existe */

    current_list = lookup_string(hashtable, str);

        /* Se o item existe, nao insere */

    if (current_list != NULL) return 2;

    /* Insere na lista */

    new_list->string = strdup(str);
    new_list->val_string=valor_string;



    new_list->next = hashtable->table[hashval];

    hashtable->table[hashval] = new_list;





    return 0;

}





hash_table_t *populate_list () /*retorna uma tabela hash alocada e preenchida com a lista da linguagem lalg*/

{

    hash_table_t *hashtable=create_hash_table(19); /*para adicionar mais valores, aumentar o numero e inserir ao final*/



    add_string(hashtable, "program", PROGRAM );

    add_string(hashtable, "begin", START );

    add_string(hashtable, "end", END );

    add_string(hashtable, "const", CONST );

    add_string(hashtable, "var", VAR );

    add_string(hashtable, "real", REAL );

    add_string(hashtable, "integer", INTEGER );

    add_string(hashtable, "procedure", PROCEDURE );

    add_string(hashtable, "else", ELSE );

    add_string(hashtable, "read", READ );

    add_string(hashtable, "write", WRITE );

    add_string(hashtable, "while", WHILE );

    add_string(hashtable, "do", DO );

    add_string(hashtable, "if", IF );

    add_string(hashtable, "then", THEN );

    add_string(hashtable, "numero_int", NUM_INTEIRO );

    add_string(hashtable, "numero_real", NUM_REAL );
    add_string(hashtable, "for", FOR );
    add_string(hashtable, "to", TO );



    return hashtable;



}

/*hash_table_t *populate_symbols ()

{

    hash_table_t *hashtable=create_hash_table(16);



    add_string(hashtable, "+", MAIS );

    add_string(hashtable, "-", MENOS );

    add_string(hashtable, "=", IGUAL );

    add_string(hashtable, "*", VEZES );

    add_string(hashtable, "/", DIVIDIDO );

    add_string(hashtable, "<", MENOR );

    add_string(hashtable, ">", MAIOR );

    add_string(hashtable, "<=", MENOR_IGUAL );

    add_string(hashtable, ">=", MAIOR_IGUAL );

    add_string(hashtable, "(", PARENTESES_ESQUERDO );

    add_string(hashtable, ")", PARENTESES_DIREITO );

    add_string(hashtable, ",", VIRGULA );

    add_string(hashtable, ":=", ATRIBUICAO );

    add_string(hashtable, ";", PONTO_E_VIRGULA );

    add_string(hashtable, ":", DOIS_PONTOS );

    add_string(hashtable, ".", PONTO );



    return hashtable;

}*/
