#include <stdio.h>
#include <string.h>
#include "data.h"
#include "area.h"
#include "morador.h"
#include "reserva.h"

int main()
{
    int qtd_areas, qtd_moradores, qtd_reservas;
    Area areas[10];
    Morador moradores[100];
    Reserva reservas[100];

    scanf("%d\n", &qtd_areas);

    for (int i=0; i < qtd_areas; i++)
    {
        areas[i] = lerArea();
    }

    scanf("%d\n", &qtd_moradores);
    for(int i =0; i < qtd_moradores; i++)
    {
        moradores[i] = lerMorador();
    }

    

    /*
    2 (quantidade de reservas a serem solicitadas)
    A1 (ID da área comum solicitada)
    126.458.235-32 (CPF do morador que está solicitando a reserva)
    04/10/2024 (Data da reserva)
    20 (Número de convidados
    
    */

    scanf("%d\n", &qtd_reservas);
    int nresRealizada =0; //quantas reservas foram aprovadas de fato

    for(int i=0; i < qtd_reservas; i++)
    {
        char idarea[MAX_TAM_ID];
        char cpfmorador[MAX_TAM_CPF];
        Data datareserva;
        int qtdconvidados;

        scanf(" %[^\n]", idarea);
        scanf(" %[^\n]", cpfmorador);
        datareserva = lerData();
        scanf("%d", &qtdconvidados);


        int achou_area =0, achou_morador =0;
        //encontrando o id solicitado 
        Area areaID_encontrada ;
        for(int j=0; j <qtd_areas; j++)
        {
            if(verificaIdArea(areas[j], idarea)== 1)
            {
                areaID_encontrada = areas[j];
                achou_area =1;
                break;
            }
        }

        Morador cpfencontrado;
        for (int k =0; k < qtd_moradores; k++)
        {
            if(verificaCPFMorador(moradores[k], cpfmorador) == 1)
            {
                cpfencontrado = moradores[k];
                achou_morador =1;
                break;
            }
        }

        if( achou_area && achou_morador && verificaSolicitacaoReserva(reservas,nresRealizada, cpfencontrado, areaID_encontrada, datareserva, qtdconvidados) == 1)
        {
            reservas[nresRealizada] = criaReserva(cpfencontrado, areaID_encontrada,datareserva, qtdconvidados);

            imprimeReserva(reservas[nresRealizada]);
            nresRealizada++;
        }
    }


    return 0;
}