#include "cadeias.h"

int cad_tamanho(char s[]){
	if (s[0] == '\0')
		return 0;
	else
		return 1 + cad_tamanho(s+1);
}

int cad_procurar_car(char c, char s[]){
	int len = cad_tamanho(s);
	int encontrou = 0;
	int res = -1;
	int i;

	for ( i = 0; i < len && !encontrou; ++i){
		if(s[i] == c){
			res = i;
		}
	}

	return res;
}

int cad_ocorrencias(char c, char s[]){
	int len = cad_tamanho(s);
	int res = 0;
	int i;

	for ( i = 0; i < len; ++i){
		if(s[i] == c)
			res++;
	}

	return res;
}

