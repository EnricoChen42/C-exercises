#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 3

typedef float t_matrice[DIM][DIM];

void calcola(t_matrice matr_media, int matr_orig[DIM][DIM]);

int dentro(int r, int c);

float media(int matr_orig[DIM][DIM], int i, int j);

void riempimento(int matr_orig[DIM][DIM]);

void stampa(t_matrice matr_media, int matr_orig[DIM][DIM]);

int main()
{
    int matr_orig[DIM][DIM];
    t_matrice matr_media;

    riempimento(matr_orig);

    calcola(matr_media, matr_orig);

    stampa(matr_media, matr_orig);

    return 0;
}

void riempimento(int matr_orig[DIM][DIM])
{
    srand(time(NULL));

    for(int i = 0; i < DIM; i++)
        for(int j = 0; j < DIM; j++)
            matr_orig[i][j] = rand() % 10;
}
systems
void calcola(t_matrice matr_media, int matr_orig[DIM][DIM])
{
    int i, j;

    for(i = 0; i < DIM; i++)
    {
        for(j = 0; j < DIM; j++)
        {
            matr_media[i][j] = media(matr_orig, i, j);
        }
    }
}

int dentro(int r, int c)
{
    if((r >= 0 && r <= 2) && (c >= 0 && c <= 2))
    {
        return 1;
    }
    else 
        return 0;
}

float media(int matr_orig[DIM][DIM],int i, int j)
{
    int h, k, counter = 0;
    float media = 0;

    // Verifica se le caselle adiacenti sono all'interno della matrice

    for (h = -1; h <= 1; h++)
    {
        for(k = -1; k <= 1; k++)
        {
            if((dentro(i + h, j + k) == 1) && (h != 0 || k != 0))
            {
                media += matr_orig[i + h][j + k];
                counter++;
            }
        }
    }
    media = media / counter;
    return media; 
}

void stampa(t_matrice matr_media, int matr_orig[DIM][DIM])
{
    printf("Matrice:\n");
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            printf(" %d", matr_orig[i][j]);
        }
        printf("\n");
    }


    printf("\nMatrice delle medie:\n");
    for(int i = 0; i < DIM; i++)
    {
        for(int j = 0; j < DIM; j++)
        {
            printf("%.2f\t", matr_media[i][j]);
        }
        printf("\n");
    }
}





