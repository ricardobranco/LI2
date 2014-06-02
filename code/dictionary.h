#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "cadeias.h"


#define ALPHABET_SIZE (26)


/**
 @brief Estrutura de uma trie (árvore de prefixos)
 @param isValue booleano que indica se se trata de uma palavra
 @param children array em que cada posição contem o caracter seguinte e um apontador para a subpalavra que se segue
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
typedef struct trie_node{
	int isValue;
	struct trie_node *children[ALPHABET_SIZE];
}*TrieNode;

/**
 @brief Dicionário que contem todas as palavras
 @param Root Trie que contem todas as palavras do dicionário
 @param size número de palavras na estrutura
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
typedef struct struct_dictionary{
	TrieNode root;
	int size;
}*DICIONARIO;


/**
 @brief Função que inicializa um dicionário
 @return Retorna o dicionário inicializado, sem palavras.
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
DICIONARIO dicionario_init();
/**
 @brief Função que adiciona uma palavra ao dicionário
 @details Função que adiciona uma palavra ao dicionário, evitando que sejam adicionadas palavras repetidas
 @param dic Dicionário em que se pretende inserir uma palavra
 @param palavra palavra a adicionar
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
void add_palavra(DICIONARIO dic, char palavra[]);
/**
 @brief Função que verifica se uma palavra já existe no dicionário
 @param dic Dicionário em que se pretende pesquisar uma palavra
 @param palavra palavra a pesquisar
 @return sucesso da operação (0 se a palavra não for encontrada)
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int palavra_existe(DICIONARIO dic, char palavra[]);
/**
 @brief Verifica se existe um prefixo no dicionário
 @param dic Dicionário em que se pretende pesquisar um prefixo
 @param palavra prefixo a pesquisar
 @return sucesso da operação
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int palavra_prefix(DICIONARIO dic, char palavra[]);
/**
 @brief Função que adicionao palavras num dicionário a partir de um ficheiro com uma lista de palavras
 @param dic Dicionário em que se pretende inserir um conjunto de palavras provinientes de um ficheiro
 @param file caminho (Path) para o ficheiro a carregar
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
void dicionario_load(DICIONARIO dic, char file[]);
/**
 @brief Função que imprime todas as palavras num dicionário, por ordem alfabética
 @param dic Dicionário com palavras (a imprimir)
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
void dicionario_print(DICIONARIO dic);
