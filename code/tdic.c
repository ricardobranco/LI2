#include <stdio.h>
#include "dictionary.h"

int main(){
	DICIONARIO dic = dicionario_init();
	add_palavra(dic,"OLA");
	add_palavra(dic,"BOLA");
	add_palavra(dic,"BOLO");

	/*dicionario_load(dic,"dicio.txt");
	printf("%d\n",palavra_existe(dic,"OLA"));
	printf("%d\n",palavra_existe(dic,"abacos"));
	printf("%d\n",palavra_existe(dic,"TAT"));*/
	dicionario_print(dic);

	return 0;
}
