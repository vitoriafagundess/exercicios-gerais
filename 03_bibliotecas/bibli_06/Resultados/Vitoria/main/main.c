#include <stdio.h>
#include "temperature_conversor.h"

int main()
{
    float temp;
    char atual, desejada;

    scanf("%f", &temp);
    getchar();
    scanf("%c %c", &atual, &desejada);

    float resultado;

    if(atual == 'c' && desejada == 'k')
    {
        resultado = convert_temperature(temp,convert_celsius_to_kelvin);
        printf("Temperature: %.2fK", resultado);   
    }
    else if(atual == 'c' && desejada == 'f')
    {
        resultado = convert_temperature(temp,convert_celsius_to_fahrenheit);
        //Temperature: -17.78Cº
        //Temperature: 212.00Fº
        //Temperature: 298.15K
        printf("Temperature: %.2fFº", resultado);
    }
    else if(atual == 'k' && desejada == 'c')
    {
        resultado = convert_temperature(temp,convert_kelvin_to_celsius);
        //Temperature: -17.78Cº
        //Temperature: 212.00Fº
        //Temperature: 298.15K
        printf("Temperature: %.2fCº", resultado);
    }
    else if(atual == 'k' && desejada == 'f')
    {
        resultado = convert_temperature(temp,convert_kelvin_to_fahrenheit);
        //Temperature: -17.78Cº
        //Temperature: 212.00Fº
        //Temperature: 298.15K
        printf("Temperature: %.2fFº", resultado);
    }
    else if(atual == 'f' && desejada == 'c')
    {
        resultado = convert_temperature(temp,convert_fahrenheit_to_celsius);
        //Temperature: -17.78Cº
        //Temperature: 212.00Fº
        //Temperature: 298.15K
        printf("Temperature: %.2fCº", resultado);
    }
    else if(atual == 'f' && desejada == 'k')
    {
        resultado = convert_temperature(temp,convert_fahrenheit_to_kelvin);
        //Temperature: -17.78Cº
        //Temperature: 212.00Fº
        //Temperature: 298.15K
        printf("Temperature: %.2fK", resultado);
    }

    return 0;
}