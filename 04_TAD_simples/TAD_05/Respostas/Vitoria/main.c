#include <stdio.h>
#include "conta.h"


int main(){

    int maxcont, n, contacadast =0;
    scanf("%d", &maxcont);
    tConta c[maxcont],co;

    do {

        scanf("%d", &n);
       

        if(n == 1)
        {
            float valor;
            scanf("%d %f", &co.numero, &valor);
            for (int i=0; i<contacadast; i++)
            {
                if(VerificaConta(c[i], co.numero)== 1)
                {
                c[i] =  SaqueConta(c[i], valor);
                }   
            }
                 
        }
        else if(n == 2)
        {
            float valor;
            scanf("%d %f", &co.numero, &valor);
            for(int j = 0; j < contacadast; j++)
            {
                 if(VerificaConta(c[j], co.numero) == 1)
            {
               c[j] =  DepositoConta(c[j], valor);
            }
            }
           

        }
        else if(n == 3)
        {
                
                scanf("%s %s", co.user.nome, co.user.cpf);
                scanf("%d", &co.numero);
                if(contacadast < maxcont)
                {
                    c[contacadast] = CriaConta(co.numero, co.user);
                    contacadast += 1;
                }
            
               
        }
        else if(n == 4)
        {
                // printf("\nDEBUG: contas cadastradas = %d\n", contacadast);
                printf("===| Imprimindo Relatorio |===\n");
                for(int i= 0; i < contacadast; i++)
                {
                    ImprimeConta(c[i]);
                }
        }

    }while(n != 0);






    
}