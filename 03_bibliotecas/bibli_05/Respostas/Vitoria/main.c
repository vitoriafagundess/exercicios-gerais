#include <stdio.h>
#include "string_utils.h"

int main()
{
    /*
    1 - Tamanho da string
    2 - Copiar string
    3 - Converter string para letras maiusculas
    4 - Converter string para letras minusculas
    5 - Imprimir string ao contrario
    6 - Encerrar o programa
    Opcao escolhida: 
    
    */
    char world[100];
    int n;

    scanf("%[^\n]", world);
    

    do
    {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Tamanho da string: %d\n", string_length(world));
            break;
        case 2:
        {
            char copia[100];
            string_copy(world,copia);
            printf("String copiada: %s\n", copia);
            break;
        } 
        case 3:
            string_upper(world);
            printf("String convertida para maiusculas: %s\n", world);
            break;
        case 4:
            string_lower(world);
            printf("String convertida para minusculas: %s\n", world);
            break;
        case 5:
            string_reverse(world);
            printf("String invertida: %s\n", world);
            break;
        default:
            break;
        }
     
        
    }while(n != 6);
    
}