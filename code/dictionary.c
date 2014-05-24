#include "dictionary.h"

TrieNode getNode()
{
    TrieNode pNode = NULL;
    int i;

    pNode = (TrieNode)malloc(sizeof(struct trie_node));

    if( pNode ){
        for(i = 0; i < ALPHABET_SIZE; i++){
            pNode->children[i] = NULL;
        }
    }
    return pNode;
}

DICIONARIO dicionario_init(){
	DICIONARIO dic = (DICIONARIO) malloc(sizeof(struct struct_dictionary));
	dic->root = getNode();
	return dic;
}

void add_palavra(DICIONARIO dic, char palavra[]){
	int len = cad_tamanho(palavra);
	int index;
	int i;

	TrieNode trie_node = dic->root;

	for(i=0; i < len;i++){
		index = toupper(palavra[i])-'A';
		if(!trie_node->children[index])
			trie_node->children[index] = getNode();
		trie_node = trie_node->children[index];

	}
	trie_node->isValue = 1;
}

int palavra_existe(DICIONARIO dic, char palavra[]){
	int len = cad_tamanho(palavra);
	int index;
	int i,flag;

	TrieNode trie_node = dic->root;

	for(i=0,flag=1; i < len && flag;i++){
		index = toupper(palavra[i])-'A';
		if(!trie_node->children[index])
			flag = 0;
		else
			trie_node = trie_node->children[index];
	}
	return (flag && trie_node->isValue)? 1 : 0;
}

int palavra_prefix(DICIONARIO dic, char palavra[]){
	int len = cad_tamanho(palavra);
	int index;
	int i,flag;

	TrieNode trie_node = dic->root;

	for(i=0,flag=1; i < len && flag;i++){
		index = toupper(palavra[i])-'A';
		if(!trie_node->children[index])
			flag = 0;
		else
			trie_node = trie_node->children[index];
	}
	return flag? 1 : 0;
}

void dicionario_load(DICIONARIO dic, char file[]){
	char readline[128];
	char word[50];
	FILE* f;

	f = fopen(file, "rt");

	while (fgets(readline,sizeof readline,f))
    {
		sscanf (readline,"%s\n",word);
		add_palavra(dic,word);
	}
	fclose(f);
}


