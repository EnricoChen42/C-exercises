// La funzione "cancella" estrae dalla lista lista e cancella dalla memoria tutti 
// gli elementi della lista on valore 5


#include <stdio.h>
#include <stdlib.h>

struct el
{
    int info;
    struct el *next;
};

struct el *cancella(struct el *L, int v)
{
    struct el *e;
    L = estrai(L, v, &e);

    while(e != NULL)   
    {
        free(e);
        L = estrai(L, v, &e);
    }
}

int main()
{
    struct el *lista;
    struct el *elemento;

    lista = cancella(lista, 5);
}