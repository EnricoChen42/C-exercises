#include <stdio.h>
#include <stdlib.h>
#define MAX 4

typedef struct
{
    char codice[10];
    char descrizione[100];
    int qta;
    int prezzo;
} articolo;

int main()
{
    articolo magazzino[MAX] = 
    {
        {"123123", "ajdh", 12, 12},
        {"624353", "ajdg", 1, 123},
        {"123276", "wefw", 5, 123},
        {"123677", "asfu", 3, 124}, 
    }, tmp;
    int i, j, k = 1, scambio, risp;


    /*Inserimento articoli*/ /*
    for(i = 0; i < MAX; i++)
    {
        printf("\nArticolo %d: ", i + 1);
        printf("\ncodice: ");
        scanf("%s", magazzino[i].codice);
        printf("\ndescrizione: " );
        scanf("%s", magazzino[i].descrizione);
        printf("\nquantita': " );
        scanf("%d", &magazzino[i].qta);
        printf("\nprezzo: " );
        scanf("%d", &magazzino[i].prezzo);
    }
*/

    /*Ordinamento rispetto alla quantita'*/
    scambio = 1;
    while(scambio)
    {
        scambio = 0;
        for(i = 0; i < (MAX - k); i++)
        {
            if(magazzino[i].qta > magazzino[i + 1].qta)
            {
                tmp = magazzino[i + 1];
                magazzino[i + 1] = magazzino[i];
                magazzino[i] = tmp;
                scambio = 1;
            }
        }
        k++;
    }

    /*Visualizzazione articoli ordinati*/
    printf("\nMagazzino ordinato per quantita'. \n");
        
    for(j = 0; j < MAX; j++)
    {
        printf("Articolo %d: \n", j + 1);
        printf("codice: %s\n", magazzino[i].codice);
        printf("descrizione: %s\n", magazzino[j].descrizione);
        printf("quantita': %d\n", magazzino[j].qta);
        printf("prezzo: %d\n\n", magazzino[j].prezzo);
    }

    return 0;
}