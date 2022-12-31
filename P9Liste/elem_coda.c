#include <stdio.h>
#include <stdlib.h>

struct el
{
    int info;
    struct el *next;
};

struct el *creael(int v)
{
    struct el *temp;
    temp = malloc(sizeof(struct el));

    if(temp == NULL)
        return NULL;

    temp -> info = v;
    temp -> next = NULL;

    return temp;
}

struct el *insertincoda(struct el *e, struct el *L)
{
    struct el *temp;

    if(e == NULL)
        return L;
    
    if(L == NULL)
        return e;

    // temp deve puntare a ultimo
    temp = L;

    // affinché temp arrivi all'ultimo nodo
    while(temp -> next != NULL)
        temp = temp -> next;

    // impongo che l'ultimo nodo abbia come nodo successivo non più NULL ma l'elemento e
    temp -> next = e;

    return L;
}

int main()
{
    struct el *lista;
    struct el *elemento;

    elemento = (6);
    lista = insertincoda(elemento, lista);
}