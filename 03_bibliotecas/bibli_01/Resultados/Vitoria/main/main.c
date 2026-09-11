#include <stdio.h>
#include "esfera_utils.h"

int main()
{
    //Area: 352.81
    //Volume: 623.30

    float raio;
    
    scanf("%f", &raio);

    printf("Area: %.2f\n Volume: %.2f", calcula_area(raio), calcula_volume(raio));

    return 0;
}