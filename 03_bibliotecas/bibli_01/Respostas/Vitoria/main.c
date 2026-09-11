#include <stdio.h>
#include "esfera_utils.h"

/*
    sobre a biblioteca estatica 
    aprendendo... 

    1- Transformar o .c em .o -> gcc -c esfera_utils.c(nome do arquivo. c)

    2- Criar a biblioteca estática .a -> ar rcs libesfera_utils.a (lib + nome do arquivo .a ) esfera_utils.o (nome do arquivo.o)

    3- Compilar o main usando a biblioteca -> gcc main.c -o main -L. -lesfera_utils

    4- Executar -> ./main
*/

/*
Estática(.a): executável fica independente e pode ser maior. 
Dinâmica(.so): a biblioteca pode ser compartilhada por vários programas e atualizada sem

*/

int main()
{
    //Area: 352.81
    //Volume: 623.30

    float raio;
    
    scanf("%f", &raio);

    printf("Area: %.2f\n Volume: %.2f", calcula_area(raio), calcula_volume(raio));

    return 0;
}