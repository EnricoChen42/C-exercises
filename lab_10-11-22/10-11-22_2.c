#include <stdio.h>
#include <stdlib.h>

void main()
{
    char nome[20];
    int i, numero;

    FILE *fp;

    printf("\nNome File: ");
    scanf("%s", nome);

    // scrittura binaria
    fp = fopen(nome, "wb");

    if(fp == NULL)
        printf("\nErrore nell'apertura del file!");
    else
    {
        for(i = 0; i < 10; i++)
        {
            numero = rand() % 101- 60;

            //indirizzo della variabile, dimensione del tipo,  ,descrittore
            fwrite(&numero, sizeof(int), 1, fp);
        }
        fclose(fp);
    }

}