// Inserimento elemento creato in testa alla lista per indirizzo

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
        return temp;

    temp -> info = v;
    temp -> next = NULL;

    printf("\n(1) E' stato creato con successo il nuovo elemento: %d.", temp -> info);
    printf("\n(2) L'indirizzo dell'elemento [%d] e': %p", v, temp);

    return temp;
}

struct el *push(struct el *L, struct el *e)
{
    if(e == NULL)
        return L;
    
    if(L == NULL)
    {
        printf("\n(3) E' stato inserito con successo l'elemento nuovo in testa alla lista.\n");
        return e;
    }

    e -> next = L;
    L = e;

    printf("\n(3) E' stato inserito con successo l'elemento nuovo in testa alla lista.\n");

    return L;
}

void visualizza(struct el *L)
{
    for(int i = 0; L != NULL; i++)
    {
        printf("\nElemento %d -> info: %d", i, L -> info);
        L = L -> next;
    }
}

int main()
{
    struct el *lista = NULL;
    struct el *elemento;
    int n;

    do
    {   
        printf("\nInserisci l'elemento nuovo in testa della lista: ");
        scanf("%d", &n);
        elemento = creael(n);
        lista = push(lista, elemento);
    } while(getchar() != EOF);

    printf("\nIl processo di inserimento di elementi in testa alla lista è stata terminata con successo.");

    visualizza(lista);
}