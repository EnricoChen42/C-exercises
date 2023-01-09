#include <stdio.h>
#include <stdlib.h>
#define L 7

struct el 
{
    int val;
    struct el *next;
};

struct el *inscoda(struct el *lis, int num);
void visualizza(struct el *lis);

int main()
{
    struct el *lis1 = NULL, *lis2 = NULL; // Funzione solo se *lis2 = NULL
    int test[L] = {12, 7, -5, 30, 37, 65, -999}, ris;

    for(int i = 0; i < L; i++)
        lis1 = inscoda(lis1, test[i]);

    printf("\nLista1:");
    visualizza(lis1);

}

struct el *inscoda(struct el *lis, int num)
{
    struct el *e = malloc(sizeof(struct el)), *temp = lis;
    
    if(e == NULL)
        lis = NULL;

    e -> val = num;
    e -> next = NULL;
    
    if(lis == NULL)
        lis = e;

    while(temp -> next != NULL) // Errore: while(temp != NULL)
        temp = temp -> next;
    temp -> next = e;
    
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
