#ifndef CARTA_H
#define CARTA_H

/**
 * @struct tCarta
 * @brief Estrutura que representa uma carta de monstro.
 */
typedef struct Carta {
    char nome[32];       /**< Nome sem espacos, com ate 31 caracteres. */
    char atributo[16];   /**< Atributo sem espacos, com ate 15 caracteres. */
    int ataque;          /**< Pontos de ataque, inteiro nao negativo. */
} tCarta;

/**
 * @brief Cria uma carta com nome, atributo e ataque informados.
 * @param nome Nome da carta.
 * @param atributo Atributo da carta.
 * @param ataque Pontos de ataque iniciais.
 * @return A carta criada.
 */
tCarta CriaCarta(const char nome[], const char atributo[], int ataque);

/**
 * @brief Compara o nome de uma carta com um nome informado.
 * @param carta Carta a ser comparada.
 * @param nome Nome a ser comparado.
 * @return 1 se os nomes forem iguais, 0 caso contrario.
 */
int VerificaCarta(tCarta carta, const char nome[]);

/**
 * @brief Aumenta os pontos de ataque de uma carta.
 * @param carta Carta a ser fortalecida.
 * @param bonus Quantidade inteira a acrescentar ao ataque.
 * @return A carta com o ataque atualizado.
 */
tCarta FortaleceCarta(tCarta carta, int bonus);

/**
 * @brief Imprime os dados de uma carta conforme o formato do enunciado.
 * @param carta Carta a ser impressa.
 * @return Nenhum valor (funcao void).
 */
void ImprimeCarta(tCarta carta);

#endif
