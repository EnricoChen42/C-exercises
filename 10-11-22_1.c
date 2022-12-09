#include <stdio.h>
#include <stdlib.h>

void main()
{
    char nome[20];
    int i, numero;
    
    //descrittore del file
    FILE *fp;

    printf("\nNome FIle: ");
    scanf("%s", nome);

    //si puù omettere l'estensione del file
    fp = fopen(nome, "w");

    //puntatore NULL quando tente di accedere a uno spazio di memoria riservata (e.s. sistema operativo) o l'indirizzo è vuoto
    if(fp == NULL)
        printf("\nErrore nell'apertura del file!"); 
    else {
        for(i = 0; i < 10; i++)
        {
            numero = rand() % 101 - 50;
            //devo dirgli su quale file scrivere, dandoli il descrittore
            fprintf(fp, "%d\n", numero);
        }
        fclose(fp); //chiude il file
    }     
}

/* 
file:
- binari
- testuali

r - aprire un file in modalità lettura
w - apre o crea un file di testo in modalità scrittura
a - apre un file in modalità "aggiungi"
r+ - apre un file sia in lettura che in scrittura
a+ - apre un file sia in lettura che in scrittura
w+ - apre un file sia in lettura che in scrittura
*/