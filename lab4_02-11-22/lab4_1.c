#include <stdio.h>

float conversione(float);

int main()
{
    float gradi_f, gradi_c;

    printf("Temperatura in gradi Fahrenheit? ");
    scanf("%f", &gradi_f);

    gradi_c = conversione(gradi_f);

    printf("Conversione: %.3f Fahrenheit = %.3f Celsius", gradi_f, gradi_c);
}

float conversione(float gradi_f)
{
    return((gradi_f - 32) * 5.0 / 9.0);
}