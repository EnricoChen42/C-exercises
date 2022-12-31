#include <stdio.h>
#include <stdlib.h>
#define N 4

typedef unsigned int riga[N];

int geodist(int s1, int s2)
{
    return abs(s2 - s1);
}

void confronto(int diag, int dist)
{
    if(diag < dist)
        printf("\nDiagonale vince.");
    else 
        printf("\nDiagonale perde.");
}

int main()
{
    riga M[N] = { {4, 10, 5, 1}, {0, 2, 6, 0}, {7, 4, 12, 8}, {0, 7, 8, 0} };

    int i, j, dist , diag = 0;

    if(N == 1)
    {
        printf("\nN = 1: la matrice è degenere.");
        return -1;
    }

    // Calcolo lunghezza diagonale
    for(i = 0; i < N - 1; i++)
            diag = diag + geodist(M[i][i], M[i + 1][i + 1]);
    printf("\nLa lunghezza della diagonale e': %d", diag);

    // Calcolo lunghezza riga
    for(i = 0; i < N - 1; i++)
    {
        dist = 0;
        for(j = 0; j < N - 1; j++)
        {
            dist = dist + geodist(M[i][j], M[i][j + 1]);
        }       
        
        printf("\nLa riga %d e' lunga: %d", i, dist);
        confronto(diag, dist);
    }

    // Calcolo lunghezza colonna
    for(i = 0; i < N - 1; i++)
    {
        dist = 0;
        for(j = 0; j < N - 1; j++)
        {
            dist = dist + geodist(M[i][j], M[i][j + 1]);
        }
        printf("\nLa colonna %d e' lunga: %d", i, dist);
        confronto(diag, dist);
    }        

    return 0;
}