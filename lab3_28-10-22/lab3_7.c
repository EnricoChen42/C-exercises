#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define DIMR 3

int mat1[DIMR][DIMR], mat2[DIMR*2][DIMR*2], i, j, k, w;

int main()
{
    srand(time(NULL));
    for(i = k; i < DIMR; i++)
        for(j = 0; j < DIMR; j++)
            mat1[i][j] = rand() % 10;
            
    for(i = 0; i < DIMR; i++)
    {
        for(j = 0; j < DIMR; j++)
            printf("%d ", mat1[i][j]);
        printf("\n");
    }
    printf("\n\n");

    // primo quadrante
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {   
            mat2[i][j] = mat1[i][j];
        }
    }


    // secondo quadrante
    k = 0;
    for(i = 0; i < 3; i++)
    {
        w = 2;
        for(j = 3; j < 6; j++)
        {
            mat2[i][j] = mat1[k][w];
            w--;
        }
        k++;
    }

    // terzo quadrante
    k = 2;
    for(i = 3; i < 6; i++)
    {
        w = 0;
        for(j = 0; j < 3; j++)
        {
            mat2[i][j] = mat1[k][w];
            w++;
        }
        k--;
    }

    // quarto quadrante
    k = 2;
    for(i = 3; i < 6; i++)
    {
        w = 2;
        for(j = 3; j < 6; j++)
        {
            mat2[i][j] = mat1[k][w]; 
            w--;
        }
        k--;
    }

    for(i = 0; i < DIMR*2; i++)
    {
        for(j = 0; j < DIMR*2; j++)
            printf("%d ", mat2[i][j]);
        printf("\n");
    }

    return 0;
}