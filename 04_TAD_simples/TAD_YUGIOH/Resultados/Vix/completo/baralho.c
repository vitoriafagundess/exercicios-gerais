#include<stdio.h>
#include<string.h>
#include "baralho.h"
#include "carta.h"
#define MAX_CARTAS 10

// /**
//  * @struct tBaralho
//  * @brief Estrutura que representa um baralho com um vetor de cartas.
//  */
// typedef struct Baralho {
//     int id;                      /**< Identificador do baralho. */
//     char duelista[32];           /**< Nome do duelista, ate 31 caracteres. */
//     tCarta cartas[MAX_CARTAS];   /**< Cartas cadastradas no baralho. */
//     int qtdCartas;               /**< Quantidade de cartas cadastradas. */
// } tBaralho;

/**
 * @brief Cria um baralho sem cartas com ID e duelista informados.
 * @param id Identificador do baralho.
 * @param duelista Nome do duelista.
 * @return O baralho criado com qtdCartas igual a zero.
 */
tBaralho CriaBaralho(int id, const char duelista[])
{
    tBaralho deck;
    deck.id = id;
    strcpy(deck.duelista, duelista);
    deck.qtdCartas =0;

    return deck;
}

/**
 * @brief Compara o ID de um baralho com um ID informado.
 * @param baralho Baralho a ser comparado.
 * @param id Identificador a ser comparado.
 * @return 1 se os IDs forem iguais, 0 caso contrario.
 */
int VerificaBaralho(tBaralho baralho, int id)
{
    if(baralho.id == id)
        return 1;
    else 
        return 0;
}

/**
 * @brief Adiciona uma carta ao final das cartas cadastradas.
 * @param baralho Baralho com vaga e sem carta de mesmo nome.
 * @param carta Carta a ser adicionada.
 * @return O baralho atualizado com a carta cadastrada.
 */
tBaralho AdicionaCarta(tBaralho baralho, tCarta carta)
{
    baralho.cartas[baralho.qtdCartas] = carta;
    baralho.qtdCartas ++;
    return baralho;
}

/**
 * @brief Fortalece uma carta existente no baralho.
 * @param baralho Baralho que contem a carta.
 * @param nome Nome da carta existente a fortalecer.
 * @param bonus Pontos de ataque a acrescentar.
 * @return O baralho com a carta atualizada.
 */
tBaralho FortaleceCartaBaralho(tBaralho baralho, const char nome[], int bonus)
{
    for (int i =0; i< baralho.qtdCartas; i++)
    {
        if(strcmp(nome, baralho.cartas[i].nome)== 0)
        {
            baralho.cartas[i] = FortaleceCarta(baralho.cartas[i], bonus);
        }
    }

    return baralho;
}

/**
 * @brief Imprime os dados do baralho e de suas cartas conforme o enunciado.
 * @param baralho Baralho a ser impresso.
 * @return Nenhum valor (funcao void).
 */
void ImprimeBaralho(tBaralho baralho)
{

    /*
    Baralho: ID
    Duelista: NOME
    Cartas: QUANTIDADE
    
    */
    printf("Baralho: %d\nDuelista: %s\nCartas: %d\n", baralho.id, baralho.duelista, baralho.qtdCartas);
    for(int i=0; i < baralho.qtdCartas;i++)
    {
        ImprimeCarta(baralho.cartas[i]);
    }
}

