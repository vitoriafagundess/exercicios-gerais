#include <stdio.h>
#include "aluno.h"

int main()
{
    int qtd;
    scanf("%d", &qtd);
    tAluno armz[qtd];
    int n=0;
    for(int i=0; i < qtd; i++)
    {
        tAluno alune = LeAluno();
       
    
        if (VerificaAprovacao(alune))
        {
            armz[n] = alune;
            n++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for(int j= i + 1; j < n; j++)
        {
            if(ComparaMatricula(armz[i], armz[j])>0)
            {
                tAluno aux = armz[i];
                armz[i] = armz[j];
                armz[j] = aux;
            }
        }
    }

    for(int j =0; j<n; j++)
    {
        ImprimeAluno(armz[j]);
    }
    return 0;
}