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

    printf("\n(1) E' stato creato con successo l'elemento {%d}.", v);
    printf("\n(2) L'indirizzo dell'elemento {%d} e': %p", v, temp);

    return temp;
}

struct el *push(struct el *L, struct el *e)
{
    if(e == NULL)
        return L;
    
    if(L == NULL)
    {
        printf("\n(3) E' stato inserito con successo l'elemento {%d} in testa alla lista.\n", e -> info);
        return e;
    }

    e -> next = L;
    L = e;

    printf("\n(3) E' stato inserito con successo l'elemento {%d} in testa alla lista.\n", L -> info);

    return L;
}

struct el *pop(struct el **L)
{
    struct el *temp;

    if(*L == NULL)
        return NULL;
    
    temp = *L;
    *L = temp -> next; 

    return temp;
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

struct el *ricerca(struct el *L, int valore)
{
    int trovato = 0, i = -1;

    if(L == NULL) 
        return NULL;

    while(L != NULL && !trovato) // boolean: trovato == 0 (False)
    {
        i++;
        if(L -> info == valore)
            trovato = 1;
        else   
            L = L -> next;
    }

    if(trovato) // boolean: trovato != 0 (True)
    {
        printf("E' stato trovato l'elemento {%d} in indice %d", valore, i);
        return L;    
    }
    else 
        return NULL;
}

struct el *ricerca_ultimo(struct el *L, int valore)
{
    struct el *temp = NULL;
    int i = -1;

    while(L != NULL)
    {
        i++;
        if(L -> info == valore)    
            temp = L;
        
        L = L -> next;    
    }

    if(temp != NULL)
        printf("E' stato trovato l'elemento {%d} in indice %d", valore, i);
    return temp;
}

int main()
{
    struct el *lista = NULL, *elemento = NULL;
    int num, opt = 1;

    printf("\n------ Liste dinamiche in C ------");    
    do
    {   
        printf("\nInserisci l'elemento nuovo in testa alla lista:  ");
        scanf("%d", &num);

        elemento = creael(num);
        lista = push(lista, elemento);

        printf("\nVuoi continuare (Si = 1 / No = 0)? ");
        scanf("%d", &opt);

    } while(opt != 0);

    printf("\n(4) Il processo di inserimento di elementi in testa alla lista è stata terminata con successo.");
    
    do
    {
        printf("\n\n------ Opzioni ------");
        printf("\n[0] Per uscire dal programma");
        printf("\n[1] Per visualizzare gli elementi della lista.");
        printf("\n[2] Per estrare un elemento dalla testa della lista.");
        printf("\n[3] Ricerca un elemento nella lista.");
        printf("\n[4] Ricerca ultimo che soddisfa una condizione.");
        printf("\nDigita i seguenti numeri per selezionare una delle opzioni: ");
        scanf("%d", &opt);

        if(opt == 1)
            visualizza(lista);
        
        if(opt == 2)
        {
            elemento = pop(&lista);
            printf("\nL'elemento che è stata estratto dalla testa della lista e': %d", elemento -> info);
        }

        if(opt == 3)
        {
            int valore;
            printf("\nInserisci il valore (primo) che vuoi cercare: ");
            scanf("%d", &valore);
            elemento = ricerca(lista, valore);
        }               

        if(opt == 4)
        {
            int valore;
            printf("\nInserisci il valore (ultimo) che vuoi cercare: ");
            scanf("%d", &valore);
            elemento = ricerca_ultimo(lista, valore);
        }       

    } while(opt != 0);
        
    return 0;
}