#include <stdio.h> 
#include <stdlib.h> 

struct el { int val; struct el *next; }; 
struct el *LIS1, *LIS2; 
 
int TRASP(struct el *lista1, struct el **lista2)  
{
    struct el *nuovo, *ultimo = NULL; 
    if (*lista2 != NULL) {printf("Lista2 non vuota!\n");return 0;} 

    //lista1 vuota o con 1 elemento 
    if ((lista1 == NULL)||(lista1->next ==NULL)) return 1; 

 
    //scansione della lista 

    while (lista1 -> next != NULL) //finchè esiste successivo 
    {
        if (lista1 -> val > (lista1 -> next) -> val)  
        {
            nuovo = (struct el *) malloc (sizeof (struct el) ); 
            
            if (nuovo == NULL) 
            {
                printf("Out of memory!\n");
                return 0;
            } 

            nuovo -> val = lista1 -> val;nuovo -> next = NULL; 

            //inserimento in coda senza riscansione lista2 ogni volta 
            if (ultimo == NULL) {*lista2 = nuovo; ultimo=nuovo;} 

        else {ultimo -> next = nuovo; ultimo=nuovo;} 
        } 

        lista1 = lista1 -> next; 
    } 
    return 1; 
} 
 
//PER TEST: Stampa una lista 

void stampalista(struct el *l)  
{
    while(l != NULL) 
    {
        printf("%d -> ", l -> val); 
        l = l -> next;
    } 

    printf("NULL\n"); 
} 
 
//PER TEST: Inserisce elemento in coda 
struct el* inscoda(struct el *l, int val) 
{ 
    struct el *nuovo, *prec; 
    nuovo = (struct el*) malloc(sizeof(struct el)); 
    
    if (nuovo == NULL) 
    { 
        printf("Out of memory!\n"); 
        return l; 
    } 

    nuovo -> val = val; 
    nuovo -> next = NULL; 

    //caso lista vuota 
    if (l == NULL) 
        return nuovo; 

    prec = l; 
    while(prec -> next != NULL) 
        prec = prec -> next; 
  
    prec -> next = nuovo; 
    
    return l; 
} 
 

//PER TEST: main esercizio 2 

#define L 7 
int main() 
{ 
    int i, ris, test[L] = {12, 7, -5, 30, 28, 65, -999}; 
  
    //reset lista 
    LIS1 = LIS2 = NULL; 
    for (i = 0; i < L; i++) 
        LIS1 = inscoda(LIS1, test[i]); 
 
    printf("Lista di partenza LIS1:\n"); 
    stampalista(LIS1); 

    ris = TRASP(LIS1, &LIS2); 
        
    printf("Lista degli elementi che sono maggiori del successivo LIS2:\n"); 
    stampalista(LIS2);
}