#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main(){

    int n;

    scanf("%d\n", &n);
    int *vet = CriaVetor(n);
    LeVetor(vet, n);

    float media = CalculaMedia(vet, n);
    printf("%.2f\n", media);

    LiberaVetor(vet);
    return 0;

}