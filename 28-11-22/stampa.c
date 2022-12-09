// Indicare, rispettando il formato di stampa previsto che cosa apparirà in video.

#include <stdio.h>

void f(int y, int lim)
{
    if(y == lim)
        return;
    
    if(y < lim)
    {
        printf("\ny = %d lim = %d", y, lim);
        return;    
    }

    printf("\ny = %d", y);
    f(y-2, lim); 
    printf("\n%d", y);
}

int main()
{
    f(12, 6);
    printf("\nfine attivazione");
}