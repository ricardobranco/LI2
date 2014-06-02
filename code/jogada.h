#include <stdio.h>
#include <stdlib.h>

typedef struct struct_jogadas
{
	int x;
	int y;
	struct struct_jogadas *next;
}*LISTA_JOGADAS;


LISTA_JOGADAS jogadas_init();
LISTA_JOGADAS jogadas_add_jogada(LISTA_JOGADAS lista,int x,int y);
int  jogadas_contem(LISTA_JOGADAS lista,int x, int y);
void jogadas_free(LISTA_JOGADAS lista);
int jogadas_tamanho(LISTA_JOGADAS lista);
void jogadas_pop(LISTA_JOGADAS jogadas);
