#include <stdio.h>
#include "data.h"

int main()
{
    /*
    29/08/2023
    25/12/2023
    */

    tData d1, d2;
    scanf("%d/%d/%d", &d1.dia, &d1.mes, &d1.ano);
    scanf("%d/%d/%d", &d2.dia, &d2.mes, &d2.ano);

    /*
    Primeira data: 01 de Janeiro de 2000
    Segunda data: 31 de Dezembro de 2023
    A primeira data eh mais antiga
    A diferenca em dias entre as datas eh: 8765 dias
    
    */

    /*
    A primeira e/ou segunda data(s) invalida(s)
    */

    if(VerificaDataValida(d1) && VerificaDataValida(d2))
    {
        printf("Primeira data: ");
        ImprimeDataExtenso(d1);
        printf("Segunda data: ");
        ImprimeDataExtenso(d2);
        if(ComparaData(d1, d2) == 1)
            printf("A segunda data eh mais antiga\n");
        else if(ComparaData(d1,d2) == -1)
            printf("A primeira data eh mais antiga\n");
        else
            printf("As datas sao iguais\n");

        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(d1,d2));
    }
    else 
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    }
    return 0;
}