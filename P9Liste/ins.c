#include <stdio.h>
#include <stdlib.h>

struct el
{
    int info;
    struct el *next;
};

struct el *creael(int num)
{
    struct el *temp;
    temp = malloc(sizeof(struct el));

    if(temp == NULL)
        return NULL;
    
    temp -> info = num;
    temp -> next = NULL;

    printf("\nElemento creato.");
    printf("\nIndirizzo: %p", temp);
    return temp;
}

struct el *push(struct el *L, struct el *e)
{
    // controllo se l'elemento esiste
    if(e == NULL)
        return L;

    // controllo se la lista sia vuota o meno
    if(L == NULL)
        return e;

    // l'elemento creato da "creael" deve puntare all'elemento puntato da L
    e -> next = L;

    // L deve puntare all'elemento creato da "creael"
    L = e;

    return L;
}

void visualizza(struct el *L)
{
    printf("\nLista:");
    for(int i = 0; L != NULL; i++)
    {
        printf("\nElemento %d -> info: %d", i, L -> info);

        if(i == 0)
            printf(" (testa)");

        L = L -> next;
    }
    printf(" (coda)");
}

struct el *ricerca_primo_valel(struct el *L, int valel)
{
    while(L != NULL)
    {
        if(L -> info == valel)
        {
            printf("\nL'elemento con valore %d e' stato trovato.", valel);
            return L;
        }
        
        L = L -> next;
    }

    printf("\nL'elemento con valore %d NON e' stato trovato.", valel);
    return NULL;
}

struct el *ins_dopo_val(struct el *L, struct el *valnew, int valel)
{
    struct el *succ, *current;

    if(L == NULL)
        return NULL;

    current = ricerca_primo_valel(L, valel);

    // se valnew è l'ultimo nodo
    if(current -> next == NULL)
        return L;

    succ = current -> next;

    current -> next = valnew;
    valnew -> next = succ;

    return L;
}

int main()
{
    struct el *lista = NULL, *elemento = NULL;
    int opt = 1, valnew, valel = 5, num;
    
    do
    {
        printf("\nInserisci un elemento: ");
        scanf("%d", &num);

        elemento = creael(num);
        lista = push(lista, elemento);

        printf("\nL'elemento è stato inserito in testa con successo!");
        printf("\nVuoi continuare (Si = 1; No = 0)? ");
        scanf("%d", &opt);

    } while(opt != 0);

    visualizza(lista);

    printf("\nInserisci l'elemento che vuoi mettere subito dopo al primo della lista che contiene il valore 5? ");
    scanf("%d", &valnew);

    elemento = creael(valnew);
    lista = ins_dopo_val(lista, elemento, valel);

    visualizza(lista);
    
    return 0;
}