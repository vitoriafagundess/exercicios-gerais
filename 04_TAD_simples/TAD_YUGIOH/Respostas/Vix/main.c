#include <stdio.h>
#include "carta.h"
#include "baralho.h"

int main(){

    int n, op;
    scanf("%d", &n);
    tBaralho deck[n];
    int qtddeck = 0;
    tBaralho b;
    tCarta c;


    do{
        scanf("%d", &op);
        if(op  == 1)
        {
            
            scanf(" %d %s", &b.id, b.duelista);
            if(qtddeck < n)
                deck[qtddeck] = CriaBaralho(b.id, b.duelista);    
            
            qtddeck++;
        }
        else if(op == 2)
        {
            int achou = 0;

            scanf(" %d %s %s %d", &b.id, c.nome, c.atributo, &c.ataque);
            
            for(int i =0; i < qtddeck; i++)
            {
                if(VerificaBaralho(deck[i], b.id))
                {
                    for(int j =0 ; j < deck[i].qtdCartas; j++)
                    {
                        if(VerificaCarta(deck[i].cartas[j], c.nome))
                        {
                           achou = 1;
                           break;
                        }
                    }

                    if(achou == 1)
                    {
                        printf("ERRO: carta %s ja existe no baralho %d\n",c.nome, b.id);
                    }
                    else if(deck[i].qtdCartas < MAX_CARTAS)
                    {
                        deck[i] = AdicionaCarta(deck[i],c);
                    }
                        break;
                }
                    
            }
            
            
            
        }
        else if(op == 3)
        {
            int bonus;
            scanf(" %d %s %d", &b.id, c.nome, &bonus);
            for(int i = 0; i < qtddeck; i++)
            {
                if(VerificaBaralho(deck[i], b.id))
                {
                    deck[i] = FortaleceCartaBaralho(deck[i], c.nome, bonus);
                }
                
            }


        }
        else if(op == 4)
        {
            printf("===| Relatorio de Baralhos |===\n");
            for (int i = 0; i < qtddeck; i++)
            {
                ImprimeBaralho(deck[i]);
            }
        }

    }while(op != 0);





    return 0;
}
