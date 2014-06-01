#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cadeias.h"


#define ALPHABET_SIZE (26)

typedef struct trie_node{
	int isValue;
	struct trie_node *children[ALPHABET_SIZE];
}*TrieNode;


typedef struct struct_dictionary{
	TrieNode root;
	int size;
}*DICIONARIO;

DICIONARIO dicionario_init();
void add_palavra(DICIONARIO dic, char palavra[]);
int palavra_existe(DICIONARIO dic, char palavra[]);
int palavra_prefix(DICIONARIO dic, char palavra[]);
void dicionario_load(DICIONARIO dic, char file[]);
void dicionario_print(DICIONARIO dic);
