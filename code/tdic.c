#include <stdio.h>
#include "dictionary.h"

int main(){
	DICIONARIO dic = dicionario_init();
	dicionario_load(dic,"dicio.txt");
	return 0;
}
