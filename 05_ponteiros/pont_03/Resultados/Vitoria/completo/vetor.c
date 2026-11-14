#include <stdio.h>
#include "vetor.h"

/*/

4  numero de vetores
4   quantos elementos vao ter no vetor
11 100 3 7 elementos do vetor 
7   quantos elementos tem no prox vetor
7 4 3 2 1 5 6  elementos do vetor
5
4 1 3 2 3 
4
1 1 1 1


*/
/**
 * @brief Lê dados do usuário e armazena em um vetor.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e lê do usuário os valores a serem armazenados no vetor.
 * 
 * @param vet Ponteiro para o vetor que receberá os valores lidos.
 * @param tam Tamanho do vetor.
 */
void LeDadosParaVetor(int * vet, int tam)
{
   
    for (int i =0; i < tam; i++)
    {
        scanf("%d", &vet[i]);
    }
}

/**
 * @brief Imprime os dados de um vetor na tela.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e imprime na tela os valores armazenados no vetor.
 * 
 * @param n Ponteiro para o vetor a ser impresso.
 * @param tam Tamanho do vetor.
 */
void ImprimeDadosDoVetor(int * n, int tam)
{
    for(int i =0; i < tam; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}

/**
 * @brief Troca o valor de duas variáveis se o segundo for menor que o primeiro.
 * 
 * 
 * Obs.: Essa função tem o comportamento de encontrar o menor valor no vetor vet de tamanho tam, 
 *  se esse valor for menor do que o valor apontado por paraTrocar, realiza uma troca. 
 *  Ao final da execução, a variável apontada por paraTrocar terá o menor valor encontrado no vetor vet.
 * 
 * @param vet Ponteiro para o vetor a ser percorrido.
 * @param tam Tamanho do vetor.
 * @param paraTrocar Ponteiro para a variável que armazenará o índice do menor valor encontrado.
 */
void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar)
{
    int menor=vet[0], achou =0;
    for (int i =0; i <tam ; i++)
    {
        if(vet[i]< menor)
        {
            menor = vet[i];
            achou = i;
        }
    }   

    if(menor < *paraTrocar)
    {
        vet[achou] = *paraTrocar;
        *paraTrocar = menor;
    }
}

/**
 * @brief Ordena um vetor em ordem crescente.
 * 
 * Esta função recebe como parâmetro um vetor e seu tamanho, e ordena os valores do vetor em ordem crescente.
 * 
 * @param vet Ponteiro para o vetor a ser ordenado.
 * @param tam Tamanho do vetor.
 */
void OrdeneCrescente(int * vet, int tam)
{
    int aux=0;
    for (int i = 0; i < tam-1; i++)
    {
      for (int j = i+1; j < tam; j++)
      {
        if(vet[i] > vet[j])
        {
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
      }
    
    }
}

