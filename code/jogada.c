#include "jogada.h"

LISTA_JOGADAS jogadas_init(){
	LISTA_JOGADAS res = (LISTA_JOGADAS) malloc(sizeof(struct struct_jogadas));
	res->next = NULL;
	return res;
}

LISTA_JOGADAS jogadas_add_jogada(LISTA_JOGADAS lista,int x,int y){
	LISTA_JOGADAS res;
	if(lista){
		lista->next=jogadas_add_jogada(lista->next,x,y);
	}else{
		res = jogadas_init();
		res->x = x;
		res->y = y;
		return res;
	}
	return lista;
}

int  jogadas_contem(LISTA_JOGADAS lista, int x, int y){
	if(lista == NULL)
		return 0;
	if(lista->x == x && lista->y == y)
		return 1;
	else
		return jogadas_contem(lista->next,x,y);
}


void jogadas_free(LISTA_JOGADAS lista){
	if(lista){
		jogadas_free(lista->next);
		free(lista);
	}
}

int jogadas_tamanho(LISTA_JOGADAS lista){
	if(!lista)
		return 0;
	return 1+jogadas_tamanho(lista->next);
}

void jogadas_pop(LISTA_JOGADAS jogadas){
	LISTA_JOGADAS aux;
	if(jogadas){
		aux = jogadas->next;
		free(jogadas);
		jogadas = aux;
	}
}
