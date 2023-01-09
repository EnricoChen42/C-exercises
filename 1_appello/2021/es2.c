#include <stdio.h>
#include <stdlib.h>
#define DIM 7

struct el 
{
    int val;
    struct el *next;
};

struct el *inscoda(struct el *lis, int num);
void visualizza(struct el *lis);
int trasp(struct el *lis1, struct el **lis2);

int main()
{
    struct el *lis1 = NULL, *lis2 = NULL; // Funzione solo se *lis2 = NULL
    int test[DIM] = {12, 7, -5, 30, 37, 65, -999}, ris;

    for(int i = 0; i < DIM; i++)
        lis1 = inscoda(lis1, test[i]);
 
    printf("\nLista1:");
    visualizza(lis1);
    ris = trasp(lis1, &lis2);

    printf("\nLista2:");    
    visualizza(lis2);
}

struct el *inscoda(struct el *lis, int num)
{
    struct el *e = (struct el *) malloc(sizeof(struct el)), *ultimo;

    if(e == NULL)
        return NULL;

    e -> val = num;
    e -> next = NULL;
    
    if(lis == NULL)
    {
        ultimo = e;
        return e;
    }
    
    ultimo -> next = e;
    ultimo = e;

    return lis;
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


int trasp(struct el *lis1, struct el **lis2)
{

    if(*lis2 != NULL)
    {
        printf("\nLista2 non e' vuota!");
        return 0;
    }

    struct el *current = lis1, *succ = current -> next;
    
    while(succ != NULL)
    {
        if(current -> val > succ -> val)
            *lis2 = inscoda(*lis2, current -> val); 
        current = succ;
        succ = succ -> next;
    }

    return 1;
}
