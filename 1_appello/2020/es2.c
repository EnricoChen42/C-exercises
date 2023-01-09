#include <stdio.h>
#include <stdio.h>
#define N 5

typedef int riga[N];

void visibile(riga matrice[], int righe[], int colonne[])
{
    int maggprec, counter, i ,j, k;

    // maggiore righe
    for(i = 0; i < N; i++)
    {
        counter = 1;
        for(j = 1; j < N; j++)
        {
            maggprec = 1;
            for(k = j - 1; k >= 0 && maggprec; k--)
            {
                if(matrice[i][j] < matrice[i][k])
                {
                    maggprec = 0;
                }
            }

            if(maggprec)
                counter++;
        }
        righe[i] = counter;
    }

    // maggiore colonne
    for(j = 0; j < N; j++)
    {
        counter = 1;
        for(i = 1; i < N; i++)
        {
            maggprec = 1;
            for(k = i - 1; k >= 0; k--)
            {
                if(matrice[i][j] < matrice[k][j])
                {
                    maggprec = 0;
                }
            }

            if(maggprec)
                counter++;
        }

        colonne[j] = counter;
    }    
}

void stampa(int mat[])
{   
    printf("\n");
    for(int i = 0; i < N; i++)
    {
        printf(" %d", mat[i]);
    }
}

int main() 
{
    riga matrice[N] = {{4, 5, 2, 3, 1}, {3, 1, 4, 5, 2}, {1, 2, 5, 4, 3}, {5, 3, 1, 2, 4}, {2, 4, 3, 1, 5}};
    int righe[N], colonne[N], valori[N*N], ris;

    visibile(matrice, righe, colonne);

    printf("\nRighe:");
    stampa(righe);

    printf("\nColonne:");
    stampa(colonne);

}