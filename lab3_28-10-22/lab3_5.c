#include <stdio.h>
#include <string.h>

#define MAX 50

int main()
{
    char nome[MAX];
    int i, cont = 0, trov = 0;

    printf("Qual è il tuo nome? ");
    scanf("%s", nome);

    for(i = 0; i < MAX && trov == 0; i++)
        if(nome[i] == '\0')
            trov = 1;
        else if(nome[i] != '\0')
            cont++;

    printf("Ciao %s\n", nome);
    printf("Ho calcolato che la lunghezza del tuo nome e' di %d caratteri\n", cont);
    printf("Ok: la lunghezza calcolata cercando '\\0' = %d coincide con quella calcolata con strlen = %d.", cont, strlen(nome));
    return 0;
}