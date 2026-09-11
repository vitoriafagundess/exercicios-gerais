#include <stdio.h>
#include "data.h"

int main()
{
    int d,m,a;

    //15/07/2006
    scanf("%d/%d/%d", &d,&m,&a);

    /*
    casos 
    Data informada: 15 de Julho de 2006
    O ano informado nao eh bissexto
    O mes informado possui 31 dias
    A data seguinte eh: 16/07/2006

    ou 

    A data informada eh invalida
    
    */

    if (verificaDataValida(d,m,a))
    {
        printf("Data informada: ");
        imprimeDataExtenso(d,m,a);

        if(verificaBissexto(a))
            printf("O ano informado eh bissexto\n");
        else 
            printf("O ano informado nao eh bissexto\n");

        printf("O mes informado possui %d dias\n", numeroDiasMes(m,a));

        printf("A data seguinte eh: ");
        imprimeProximaData(d,m,a);

    }
    else
        printf("A data informada eh invalida\n");
    
    return 0;
}