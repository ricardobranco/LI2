#include <stdio.h>
#include <stdlib.h>
#include "cadeias.h"

typedef struct struct_tree{
	char* value;
	struct struct_tree *left;
	struct struct_tree *right;
}*TREE;

TREE tree_init();
void tree_add_palavra(TREE tree, char palavra[]);
int tree_search(TREE tree, char palavra[]);
void tree_print(TREE tree);
