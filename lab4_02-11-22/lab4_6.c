#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C_LEN 10
#define P_MAX 15

int enqueue(int coda[C_LEN], int *n, int elem);

int dequeue(int coda[C_LEN], int *n);

void stampa_coda(int coda[C_LEN], int *n);

int main()
{
    srand(time(NULL));
    int coda[C_LEN], n = 0, elem, azione;

    for(int i = 0; i < P_MAX; i++) 
    {
        azione = rand() % 2;

        if(azione == 1)
        {   
            printf("Passo %d di %d. INGRESSO ->", i + 1, P_MAX);
            elem = rand() % 10;
            enqueue(coda, &n, elem);
        }
        
        if(azione == 0)
        {
            printf("Passo %d di %d. USCITA -> ", i + 1, P_MAX);
            dequeue(coda, &n);
        }
    }

    return 0;
}

int enqueue(int coda[C_LEN], int *n, int elem)
{
    if(*n == C_LEN)
    {
        printf(" Coda piena! Nessun ingresso.");
        stampa_coda(coda, n);
        return -1;
    }

    if(*n != C_LEN)
    {
        coda[*n] = elem;
        (*n)++;
        printf(" Ingresso di %d riuscito.", elem);
        stampa_coda(coda, n);
        return 1;
    }

    
}

int dequeue(int coda[C_LEN], int *n)
{
    if(*n == 0)
    {
        printf(" Coda vuota! Nessuna uscita.");
        stampa_coda(coda, n);
        return -1;
    }

    if(*n != 0)
    {
        int temp;
        printf(" Uscita di %d avvenuta.", coda[0]);

        for(int i = 0; i < *n - 1; i++)
            coda[i] = coda[i + 1];
        (*n)--;
        stampa_coda(coda, n);
        return 1;
    }
}

void stampa_coda(int coda[C_LEN], int *n)
{
    if(*n == 0)
        printf(" Coda: <vuota>\n");

    if(*n != 0)
    {
        printf(" Coda:");
        
        for(int i = 0; i < *n; i++)
            printf(" %d", coda[i]);
        printf("\n");
    }
}