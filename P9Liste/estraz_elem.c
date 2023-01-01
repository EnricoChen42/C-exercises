// Estrae dalla lista il primo elemnto con valore 5 e restituisce la lista 
// modificata e l'indirizzo dell'elemento

#include <stdio.h>
#include <stdlib.h>

struct el
{
    int info;
    struct el *next;
};

struct el *estrai(struct el *L, int num, struct el **e)
{
    // per la scansione
    struct el *current = L, *prec = NULL;

    // nel caso in cui la lista è vuota
    if(current == NULL)
    {
        *e = NULL;
        return NULL;
    }

    while(current != NULL)
    {
        // trova l'elemento num
        if(current -> info == num)
        {
            if(current == L) // prima posizione
            {
                L = current -> next;
                *e = current;
                return L; 
            }
            else // posizioni restanti
            {
                prec -> next = current -> next;
                *e = current;
                return L;
            }
        }
        else // non lo trova e passa al prossimo
        {
            prec = current;
            current = current -> next;
        }
    }

    // non ha trovato niente
    *e = NULL;
    return L;
}

int main()
{
    struct el *lista = NULL, *elemento;
    int num;

    lista = estrai(lista, 5, &elemento);
}