#include "string_utils.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

/**
 * @brief Retorna o tamanho de uma string.
 * @param str A string para obter o tamanho.
 * @return O tamanho da string.
 */
int string_length(char *str)
{
    int i=0;
    while(str[i] != '\0')
        i++;
   
    return i;
}

/**
 * @brief Copia uma string de origem para destino.
 * @param src A string de origem.
 * @param dest A string de destino.
 */
void string_copy(char *src, char *dest)
{
    int i=0;
    while(src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**
 * @brief Converte todos os caracteres de uma string para maiúsculas.
 * @param str A string para converter.
 */
void string_upper(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

/**
 * @brief Converte todos os caracteres de uma string para minúsculas.
 * @param str A string para converter.
 */
void string_lower(char *str)
{
    int i =0;
    while(str[i] != '\0')
    {
        str[i] = tolower(str[i]);
        i++;
    }
}

/**
 * @brief Inverte uma string.
 * @param str A string para inverter.
 */
void string_reverse(char *str)
{
    int i, j=0, tam;
    tam = strlen(str);
    char aux[tam];

    for (i = tam -1; i >= 0; i--)
    {
        aux[j] = str[i];
        j++;
    }
    //copiando de volta para string original
    for(i = 0; i<tam; i++)
    {
        str[i] = aux[i];
    }

}
