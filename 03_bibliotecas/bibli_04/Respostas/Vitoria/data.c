#include "data.h"
#include <stdio.h>

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano)
{
    if (mes >= 1 && mes <= 12)
    {
        if((1 <= dia) && (dia <= numeroDiasMes(mes,ano)))
            return 1;
        else 
            return 0;
    }
    else 
        return 0;
}

/**
 * @brief Imprime uma data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeData(int dia, int mes, int ano)
{
    printf("%02d/%02d/%d\n", dia, mes, ano);
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês da data.
 */
void imprimeMesExtenso(int mes)
{
    switch (mes)
    {
    case 1:
        printf("Janeiro");
        break;
    case 2:
        printf("Fevereiro");
        break;
    case 3:
        printf("Março");
        break;
    case 4:
        printf("Abril");
        break;
    case 5:
        printf("Maio");
        break;
    case 6:
        printf("Junho");
        break;
    case 7:
        printf("Julho");
        break;
    case 8:
        printf("Agosto");
        break;
    case 9:
        printf("Setembro");
        break;
    case 10:
        printf("Outubro");
        break;
    case 11:
        printf("Novembro");
        break;
    case 12:
        printf("Dezembro");
        break;
    default:
        break;
    }
}

/**
 * @brief Imprime uma data por extenso no formato "DD de NOME_DO_MES de AAAA".
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano)
{
    /*
    19 de Julho de 2023
    */
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano)
{
    if ((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0)))
        return 1;
    else
        return 0; 
}


/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano)
{
    if (mes == 1)
        return 31;
    else if (mes == 2)
    {
        if(verificaBissexto(ano))
            return 29;
        else 
            return 28;
    }
    else if (mes == 3)
        return 31;
    else if (mes == 4)
        return 30;
    else if (mes == 5)
        return 31;
    else if(mes == 6)
        return 30;
    else if (mes == 7)
        return 31;
    else if (mes == 8)
        return 31;
    else if (mes == 9)
        return 30;
    else if (mes == 10)
        return 31;
    else if(mes == 11)
        return 30;
    else if (mes == 12)
        return 31;
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda e 0 se as datas são iguais.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2)
        return 1;
    else if(ano1 < ano2)
        return -1;

    if(mes1 > mes2)
        return 1;
    else if(mes1 < mes2)
        return -1;
    
    if(dia1 > dia2)
        return 1;
    else if(dia1 < dia2)
        return -1;
    else
        return 0;
       
}

/**
 * @brief Calcula o número de dias até o início de um determinado mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return Retorna o número de dias até o início do mês.
 */
int calculaDiasAteMes(int mes, int ano)
{
    int i, total=0;
    for(i = 1; i < mes; i++)
    {
        total += numeroDiasMes(i,ano);
    }

    return total;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if(comparaData(dia1,mes1,ano1,dia2,mes2, ano2) == 0)
        return 0;
    
    // se a primeira data for menor(exemplo: 2020 x 2025), para nao ficar negativo inverte, ja que a diferença de dias das datas vai continuar sendo a mesma
    if(comparaData(dia1,mes1,ano1,dia2,mes2,ano2) == -1)
    {
        return calculaDiferencaDias(dia2,mes2,ano2,dia1,mes1,ano1);
    }

    //se chegou ate aqui é pq a primeira data é maior (1) futuro, (data 2) passado
    int diff = 0;
    
    //duas datas no mesmo ano
    if (ano1 == ano2)
    {
        diff = (calculaDiasAteMes(mes1,ano1) + dia1) - (calculaDiasAteMes(mes2,ano2) + dia2);
    }
    
    //anos diferentes
    else
    {
        for (int i = ano2+1; i< ano1; i++)
        {
            if(verificaBissexto(i))
                diff += 366;
            else
                diff += 365;
        }

        //calculando dias da maior data(1) 
        diff += (calculaDiasAteMes(mes1,ano1) + dia1) ;
    
        int totalanos2;
        //dias restante da menor data(2) subtrai do ano os meses que ja foram ate pq o for ja conta o meio termo caso tenha se passado anos
        if(verificaBissexto(ano2))
            totalanos2 = 366;
        else
            totalanos2 = 365;
        
        diff += (totalanos2 - (calculaDiasAteMes(mes2,ano2) + dia2));
    }

    return diff;
}

/**
 * @brief Imprime a próxima data no formato DD/MM/AAAA.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeProximaData(int dia, int mes, int ano)
{
    dia++;

    if(dia > numeroDiasMes(mes, ano))
    {
        dia = 1;
        mes++;
        if(mes > 12)
        {
            mes = 1;
            ano++;
        }
    }
    imprimeData(dia,mes,ano);
}

