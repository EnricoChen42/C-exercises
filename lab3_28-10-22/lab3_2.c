#include <stdio.h>

#define DIMV 5
int v[DIMV], n;

int main()
{
    
    for(n = 0; n < DIMV; n++)
    {
        printf("Il vettore contiene n=%d. Numero per cella? ", n);
        scanf("%d", &v[n]);
    }    

    printf("Il vettore contiene n=%d. Il vettore e' pieno.\n", n);

    printf("Vettore con n=%d numeri:", n);

    for(n = 0; n < DIMV; n++)
        printf(" %d", v[n]);
}