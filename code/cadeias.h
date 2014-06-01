/**
 @brief Função que diz o tamanho de uma string
 @details Função que diz o tamanho de uma string. Equivalente ao strlen do string.h
 @param s String que se pretender medir
 @return Tamanho da String
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_tamanho(char s[]);
/**
 @brief Função que diz se um caracter existe numa string
 @param c Caracter a encontrar
 @param s String que deverá ter o caracter c
 @return Inteiro com o indice da primeira ocorrência de c em s
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_procurar_car(char c, char s[]);
/**
 @brief Função que diz o número de ocorrências de um caracter numa string
 @param c Caracter a encontrar
 @param s String que deverá ter o caracter c
 @return Inteiro com o numéro de ocorrências de c em s
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_ocorrencias(char c, char s[]);
/**
 @brief Função que diz se uma string é substring de outra string
 @details Função que diz se uma string é substring de outra string. Equivalente ao strstr do string.h
 @param c Caracter a encontrar
 @param s String que deverá ter o caracter c
 @return Inteiro com o numéro de ocorrências de c em s
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_procurar_str(char s1[], char s2[]);
int cad_e_prefixo(char s1[], char s2[]);
int cad_e_sufixo(char s1[], char s2[]);
int cad_iguais(char s1[], char s2[]);
int cad_primeiro(char s1[], char s2[]);
int cad_comparar(char s1[], char s2[]);
int cad_um_dos(char s1[], char s2[]);
int cad_nenhum_dos(char s1[], char s2[]);
int cad_copiar(char s1[], char s2[]);
int cad_colar(char s1[], char s2[]);
int cad_mover(char m1[], char m2[], int n);
