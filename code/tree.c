#include "tree.h"

TREE tree_init(){
	TREE tree = (TREE) malloc(sizeof(struct struct_tree));
	tree->value = NULL;
	tree->left = NULL;
	tree->right  = NULL;
	return tree;
}

void tree_add_palavra(TREE tree, char palavra[]){
	int comp;
	int len = cad_tamanho(palavra);

	if(tree->value){
		comp = cad_comparar(palavra,tree->value);
		if(comp){
			if(comp < 0){
				if(!tree->left)
					tree->left = tree_init();
				tree_add_palavra(tree->left,palavra);
			}else{
				if(!tree->right)
					tree->right = tree_init();
				tree_add_palavra(tree->right,palavra);
			}
		}
	}
	else{
		tree->value = (char*) malloc(sizeof(char)*len+1);
		cad_copiar(palavra,tree->value);
	}
}
int tree_search(TREE tree, char palavra[]){
	int comp;

	if(tree && tree->value){
		comp = cad_comparar(palavra,tree->value);
		if(!comp)
			return 1;
		else{
			if(comp < 0)
				return tree_search(tree->left,palavra);
			else
				return tree_search(tree->right,palavra);
		}
	}
	else
		return 0;

}
void tree_print(TREE tree){
	if(tree && tree->value){
		tree_print(tree->left);
		printf("%s\n",tree->value);
		tree_print(tree->right);
	}
}
