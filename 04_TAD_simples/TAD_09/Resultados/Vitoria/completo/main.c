#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main()
{
    int n, i;

    scanf("%d", &n);
    tEmpresa empresas[n];

    for (i = 0; i < n; i++)
    {
        empresas[i] = leEmpresa();
    }


    for (i = 0; i < n; i++)
    {
        imprimeEmpresa(empresas[i]);
    }

    return 0;
}