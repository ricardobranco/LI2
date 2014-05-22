#include "stdlib.h"
#include "cadeias.h"
#include "stdio.h"

typedef struct struct_board{
	int nc;
	int nl;
	char **board;
}*BOARD;

BOARD board_init(int nl, int nc);
int add_row(char* row,int pos,BOARD board);
void print(BOARD board);
