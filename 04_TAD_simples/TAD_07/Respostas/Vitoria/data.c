#include <stdio.h>
#include "data.h"


// typedef struct Data {
//     int dia;
//     int mes;
//     int ano; 
// } tData;

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 * 
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano)
{
    tData d;
    d.dia = dia;
    d.mes = mes;
    d.ano =ano;
    return d;
}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data)
{
    if(data.mes >= 1 && data.mes <= 12)
    {
        if(data.dia >= 1 && data.dia <= NumeroDiasMes(data))
            return 1;
        else 
            return 0;
    }
    else 
        return 0;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data)
{
    if(data.mes == 1)
        printf("Janeiro");
    else if(data.mes == 2)
        printf("Fevereiro");
    else if(data.mes == 3)
        printf("Março");
    else if(data.mes == 4)
        printf("Abril");
    else if(data.mes == 5)
        printf("Maio");
    else if(data.mes == 6)
        printf("Junho");
    else if(data.mes == 7)
        printf("Julho");
    else if(data.mes == 8)
        printf("Agosto");
    else if(data.mes == 9)
        printf("Setembro");
    else if(data.mes == 10)
        printf("Outubro");
    else if(data.mes == 11)
        printf("Novembro");
    else if(data.mes  == 12)
        printf("Dezembro");
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data)
{
    //29 de Agosto de 2023
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);

}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data)
{
    if((data.ano % 400) == 0 || ((data.ano % 4) == 0 && (data.ano % 100) != 0))
        return 1;
    else 
        return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data)
{
    
    switch (data.mes)
    {
    case 1:
        return 31;
        break;
    case 2:
        if(VerificaBissexto(data))
            return 29;
        else 
            return 28;
        break;
    case 3:
        return 31;
        break;
    case 4:
        return 30;
        break;
    case 5:
        return 31;
        break;
    case 6:
        return 30;
        break;
    case 7:
        return 31;
        break;
    case 8:
        return 31;
        break;
    case 9:
        return 30;
        break;
    case 10:
        return 31;
        break;
    case 11:
        return 30;
        break;
    case 12:
        return 31;
        break;

    default:
        return 0;
        break;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2)
{
    if(data1.ano > data2.ano)
        return 1;
    else if(data1.ano < data2.ano)
        return -1;
    
    if(data1.mes > data2.mes)
        return 1;
    else if(data1.mes < data2.mes)
        return -1;
    
    if(data1.dia > data2.dia)
        return 1;
    else if(data1.dia < data2.dia)
        return -1;
    
    else 
        return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data)
{
    int i, total=0;
    for(i =1; i < data.mes; i++)
    {
        tData temp = CriaData(data.dia, i, data.ano);
        total += NumeroDiasMes(temp);
    }

    return total;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2)
{
    if(ComparaData(data1,data2) == 0)
        return 0;
    
    if(ComparaData(data1,data2) == -1)
    {
        return (CalculaDiferencaDias(data2,data1));
    }

    // se passou é pq data1 > data 2 retorno é 1
    int  diff =0;

    //mesmo ano
    if(data1.ano == data2.ano)
    {
        diff = (CalculaDiasAteMes(data1) + data1.dia) - (CalculaDiasAteMes(data2) + data2.dia);
        return diff;
    }
    else 
    {
        //verificar se tem anos completos entre essas datas
        for(int i = data2.ano + 1; i < data1.ano; i++)
        {
            tData temp = CriaData(data2.dia, data2.mes, i);
            if(VerificaBissexto(temp))
                diff += 366;
            else 
                diff += 365;
        }
        //maior ano
        diff += CalculaDiasAteMes(data1) + data1.dia;
        
        int totalanos2;

        if(VerificaBissexto(data2))
            totalanos2 = 366;
        else 
            totalanos2 = 365;
        
        diff += (totalanos2 - (CalculaDiasAteMes(data2) + data2.dia));

        return diff;
    }


}

