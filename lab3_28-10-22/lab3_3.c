#include <stdio.h>
#include <string.h>

#define DIM1 5
#define DIM2 4
int v1[DIM1], v2[DIM2], i, j, in[DIM2], k = 0, l, lun;

int main()
{
    printf("Primeo vettore:\n");

    for(i = 0; i < DIM1; i++)
    {
        printf("Inserisci il %d° numero: ", i+1);
        scanf("%d", &v1[i]);
    }

    printf("Secondo vettore:\n");

    for(i = 0; i < DIM2; i++)
    {
        printf("Inserisci il %d° numero: ", i+1);
        scanf("%d", &v2[i]);
    }

    printf("vettore1:");

    for(i = 0; i < DIM1; i++)
        printf(" %d", v1[i]);
    printf("\n");

    printf("vettore2:");

    for(i = 0; i < DIM2; i++)
        printf(" %d", v2[i]);
    printf("\n");

    for(j = 0; j < DIM2; j++)
        for(i = 0; i < DIM1; i++)
            if(v2[j] == v1[i])
            {
                in[k] = v1[i];
                for(l = 0; l < DIM1; l++)
                    if(v1[l] == in[k])
                        v1[l] = '*';
                k++;
            }

    printf("Intersezione:");
    for(i = 0; i < k; i++)
        printf(" %d", in[i]);
    
    return 0;
}