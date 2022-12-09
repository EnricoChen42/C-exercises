#include <stdio.h>
#define DIM_M 3

int mat[DIM_M][DIM_M], i, j;

int main()
{
    // Inserimento dei numeri da parte dell'utente
    for(i = 0; i < DIM_M; i++)
        for(j = 0; j < DIM_M; j++)
        {
            printf("matrice[%d][%d]? ", i, j);
            scanf("%d", &mat[i][j]);
        }


    printf("\nMatrice inserita:\n");
    for(i = 0; i < DIM_M; i++)
    {
        printf("\t");
        for(j = 0; j < DIM_M; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }

    printf("Matrice raddipiata:\n");
    for(i = 0; i < DIM_M; i++)
    {
        printf("  ");
        for(j = 0; j < DIM_M; j++)
        {
            printf("%d\t", mat[i][j]*2);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}