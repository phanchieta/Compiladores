#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _list_t_ {
    char *string;
    int val_string; //*informacao a ser armazenada*/
    struct _list_t_ *next; /*ponteiro para o prox elemento da lista*/
} list_t;

typedef struct _hash_table_t_ {
    int size;       /* tamanho da lista */
    list_t **table; /* vetor de ponteiros para cada elemento da lista */
} hash_table_t;

hash_table_t *create_hash_table(int); /* funcao para alocar a tabela*/

unsigned int hash(hash_table_t *, char *); /*funcao hash*/

list_t *lookup_string(hash_table_t *, char *); /*procura o elemento da lista e retorna um ponteiro para ele, retorna NULL se nao encontrou*/

int add_string(hash_table_t *, char *, int); /*adiciona elementos na tabela*/

hash_table_t *populate_list (); /*inicializa a tabela com a lista de palavras reservadas da linguagem lalg*/

hash_table_t *populate_symbols ();

#endif // HASH_H_INCLUDED
