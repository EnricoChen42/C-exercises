#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stampa_matrice(int mat[][2])
{
    int i, j;
    printf("Matrice 2 x 2:\n");
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
            printf(" %d", mat[i][j]);    
        printf("\n");
    }
}

int genera_matrice(int mat[][2], int *det, int *sum)
{
    int i, j;
    for(i = 0; i < 2; i++)
        for(j = 0; j < 2; j++)
        {
            mat[i][j] = rand() % 10;
            *sum = *sum + mat[i][j];
        }

    *det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}  

int main()
{
    int mat[2][2], det, sum = 0; 
    srand(time(NULL));

    genera_matrice(mat, &det, &sum); // mat = indirizzo del primo elemento dell'array
    stampa_matrice(mat);

    printf("Determinante = %d\n", det);
    printf("Somma elementi = %d", sum);
}
