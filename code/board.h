#include "stdlib.h"

typedef struct struct_board{
	int nc;
	int nl;
	char **board;
}*BOARD;

BOARD board_init(int nl, int nc);
