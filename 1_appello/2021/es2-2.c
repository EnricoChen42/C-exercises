#include <stdio.h>
#include <stdlib.h>
#define DIM 7

struct el 
{
    int val;
    struct el *next;
};

void inscoda(struct el **lis, int num);
void visualizza(struct el *lis);

int main()
{
    struct el *lis1 = NULL, *lis2 = NULL; // Funzione solo se *lis2 = NULL
    int test[DIM] = {12, 7, -5, 30, 37, 65, -999}, ris;

    for(int i = 0; i < DIM; i++)
        inscoda(&lis1, test[i]);
 
    printf("\nLista1:");
    visualizza(lis1);
}

void inscoda(struct el **lis, int num)
{
    struct el *e = (struct el *) malloc(sizeof(struct el)), *ultimo;

    if(e == NULL)
        *lis = NULL;

    e -> val = num;
    e -> next = NULL;
    
    if(*lis == NULL)
    {
        ultimo = e;
        *lis = e;
    }
    
    ultimo -> next = e;
    ultimo = e;

}

void visualizza(struct el *lis)
{
    for(int i = 0; lis != NULL; i++)
    {
        if(i == 0)
            printf(" %d", lis -> val);
        else
            printf(" -> %d", lis -> val);

        lis = lis -> next;
    }
}


