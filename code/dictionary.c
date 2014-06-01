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
	dic->size = 0;
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
	dic->size++;
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

void dicionario_print_aux(TrieNode trie_node,char* prefix){
	int i;
	int len = cad_tamanho(prefix);
	char* newPrefix;

	if (trie_node->isValue)
		printf("%s\n",prefix);

	newPrefix = (char*) malloc(sizeof(char)*len+2);
	cad_copiar(prefix,newPrefix);

	for (i = 0; i < ALPHABET_SIZE; ++i){
		newPrefix[len] = i+'A';
		newPrefix[len+1] = '\0';
		if(trie_node->children[i])
			dicionario_print_aux(trie_node->children[i],newPrefix);
	}
	free(newPrefix);
}

void dicionario_print(DICIONARIO dic){
	TrieNode trie_node = dic->root;
	char* newPrefix;
	int i;
	newPrefix = (char*) malloc(sizeof(char)*2);
	for (i = 0; i < ALPHABET_SIZE; ++i){
		newPrefix[0] = i+'A';
		newPrefix[1] = '\0';
		if(trie_node->children[i])
			dicionario_print_aux(trie_node->children[i],newPrefix);
	}

}

