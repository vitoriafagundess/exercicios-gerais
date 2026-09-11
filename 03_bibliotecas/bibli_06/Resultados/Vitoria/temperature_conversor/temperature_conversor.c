#include "temperature_conversor.h"
#include <stdio.h>

/**
 * @brief Converte uma temperatura em Celsius para Kelvin.
 * @param temperature A temperatura em Celsius.
 * @return A temperatura em Kelvin.
 */
float convert_celsius_to_kelvin(float temperature)
{
    float kelvin;
    kelvin = temperature + 273.15;
    return kelvin;
}

/**
 * @brief Converte uma temperatura em Celsius para Fahrenheit.
 * @param temperature A temperatura em Celsius.
 * @return A temperatura em Fahrenheit.
 */
float convert_celsius_to_fahrenheit(float temperature)
{
    float fah;
    fah = (1.8 * temperature) + 32;
    return fah;
}

/**
 * @brief Converte uma temperatura em Kelvin para Celsius.
 * @param temperature A temperatura em Kelvin.
 * @return A temperatura em Celsius.
 */
float convert_kelvin_to_celsius(float temperature)
{
    float celsi;
    celsi = temperature-273.15;
    return celsi;
}

/**
 * @brief Converte uma temperatura em Kelvin para Fahrenheit.
 * @param temperature A temperatura em Kelvin.
 * @return A temperatura em Fahrenheit.
 */
float convert_kelvin_to_fahrenheit(float temperature)
{
    float kelvin;
    kelvin = temperature - 273.15;
    float temp;
    temp = (kelvin * 1.8) + 32;
    return temp;
}

/**
 * @brief Converte uma temperatura em Fahrenheit para Celsius.
 * @param temperature A temperatura em Fahrenheit.
 * @return A temperatura em Celsius.
 */
float convert_fahrenheit_to_celsius(float temperature)
{
    float cels;
    cels = (temperature - 32)/1.8;
    return cels;
}

/**
 * @brief Converte uma temperatura em Fahrenheit para Kelvin.
 * @param temperature A temperatura em Fahrenheit.
 * @return A temperatura em Kelvin.
 */
float convert_fahrenheit_to_kelvin(float temperature)
{
    float fah;
    float temp;
    fah = temperature - 32;
    temp = ((fah * (5/9.0)) + 273.15);
    return temp;
}
/**
 * @brief Converte uma temperatura usando uma função de conversão dada.
 * @param temperature A temperatura a ser convertida.
 * @param convert_func A função de conversão a ser usada.
 * @return A temperatura convertida.
 */
float convert_temperature(float temperature, float convert_func(float temperature))
{
    return convert_func(temperature);
}

