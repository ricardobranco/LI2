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
/**
 @brief Função que diz se uma string é prefixo de outra string
 @param s1 String a verificar sendo prefixo
 @param s2 String que deverá conter a string s1 como prefixo
 @return Inteiro como booleano da verificação (0 falso, 1 verdadeiro)
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_e_prefixo(char s1[], char s2[]);
/**
 @brief Função que diz se uma string é sufixo de outra string
 @param s1 String a verificar sendo prefixo
 @param s2 String que deverá conter a string s1 como sufixo
 @return Inteiro como booleano da verificação (0 falso, 1 verdadeiro)
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_e_sufixo(char s1[], char s2[]);
/**
 @brief Função que diz se uma string é igual outra string
 @param s1 String a comparar com s2
 @param s2 String a comparar com s1
 @return Inteiro como booleano da verificação (0 falso, 1 verdadeiro)
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_iguais(char s1[], char s2[]);
/**
 @brief Função que diz se uma string é menor do que outra string
 @param s1 String que se verificará se é menor
 @param s2 String usada para comparação
 @return Inteiro como booleano da verificação (0 falso, 1 verdadeiro)
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_primeiro(char s1[], char s2[]);
/**
 @brief Função que compara duas strings (segundo a ordem lexicográfica)
 @details Função que compara duas strings. Equivalente ao strcmp do string.h
 @param s1 String para comparação 1
 @param s2 String para comparação 2
 @return Inteiro com o resultado da comparação (-1 se s1<s2; 0 se s1=s2; 1 se s1>s2)
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_comparar(char s1[], char s2[]);
/**
 @brief Função que procura o primeiro índice numa string que contém um dos caracteres de outra string
 @details Função que procura o primeiro índice numa string que contém um dos caracteres de outra string. Equivalente ao strpbrk do string.h
 @param s1 String que conterá (ou não) um dos caracteres da string s2
 @param s2 String que contém os caracteres de comparação.
 @return Inteiro a posição em s1 do primeiro caracter comum na string s2
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_um_dos(char s1[], char s2[]);
/**
 @brief Função que procura o primeiro índice numa string que não contém um dos caracteres de outra string
 @param s1 String que conterá (ou não) um dos caracteres da string s2
 @param s2 String que contém os caracteres de comparação.
 @return Inteiro a posição em s1 do primeiro caracter não comum na string s2
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_nenhum_dos(char s1[], char s2[]);
/**
 @brief Função que copia uma string para outra
 @details Função que copia uma string para outra. Equivalente ao strcpy do string.h
 @param s1 String atribuição para rebeber a cópia.
 @param s2 String que será copiada
 @return Inteiro com confirmação de sucesso.
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_copiar(char s1[], char s2[]);
/**
 @brief Função que adiciona ao fim de uma string outra string
 @details Função que adiciona ao fim de uma string outra string. Equivalente ao strcat do string.h
 @param s1 String a ser acrescentada por s2
 @param s2 String que será adicionada a s1
 @return Inteiro com o tamanha da nova string
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_colar(char s1[], char s2[]);
/**
 @brief Função que move n bytes de uma string para outra string
 @details Função que move n bytes de uma string para outra string. Equivalente ao strncat do string.h
 @param m1 String a ser acrescentada
 @param m2 String a ser criada
 @param n número de caracteres a serem movidos a partir de m1
 @return Inteiro que retorna o sucesso da operação
 @author Daniel Araújo
 @author Pedro Duarte
 @author Ricardo Branco
 */
int cad_mover(char m1[], char m2[], int n);
