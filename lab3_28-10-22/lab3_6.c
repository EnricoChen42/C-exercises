#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int v1[MAX], v2[MAX], v3[MAX], n, i, j = 0, k;
    srand(time(NULL));

    printf("Lunghezza effettiva (1-10)? ");
    scanf("%d", &n);

    // generazione di numeri casuali
    for(i = 0; i < n; i++)
    {    
        v1[i] = rand() % 10;
        v2[i] = rand() % 10;
    }
    
    k = n - 1; 
    for(i = 0; i < n; i++)
    {
        v3[i] = v1[i] + v2[k];
        k--;
    }

    printf("vettore1: ");
    for(i = 0; i < n; i++)
        printf("%d\t", v1[i]);

    printf("\nvettore2: ");
    for(i = 0; i < n; i++)
        printf("%d\t", v2[i]);

    printf("\nvettore3: ");
    for(i = 0; i < n; i++)
        printf("%d\t", v3[i]);

    return 0;
}