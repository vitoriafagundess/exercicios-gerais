#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

/**
 * Cria um vetor de inteiros de tamanho especificado, alocado dinamicamente.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
int *CriaVetor(int tamanho)
{

    /*
    int x = sizeof(int) --> printf("%d", x) vai imprimir 4 , que é o numero de bytes que o tipo inteiro ocupa na memoria.
    
    */
    int *vet = (int*) malloc(tamanho * sizeof(int));
    if(vet == NULL)
    {
        printf("Erro ao alocar memoria!");
        return 0;
    }

    return vet;
}

/**
 * Lê um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d ", &vetor[i]);
    }
}

/**
 * Calcula a média dos valores de um vetor de inteiros de tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
float CalculaMedia(int *vetor, int tamanho)
{
    int total=0; 
    float media=0;
    for(int i = 0; i < tamanho; i++)
    {
        total += vetor[i];
    }

    media = total/(float)tamanho;

    return media;
}

/**
 * Libera a memória alocada para um vetor de inteiros.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(int *vetor)
{
    if(vetor != NULL)
    {
        free(vetor);
    }
    
}

