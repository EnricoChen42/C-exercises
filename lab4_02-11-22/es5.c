#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DIM 3

typedef float t_matrice[DIM][DIM];

int dentro(int r, int c)
{
    if( r>=0 && r<DIM && c>=0 && c<DIM)
    {
        return 1;
    } else 
    {
        return 0;
    }
     
}

float media(int matr_orig[DIM][DIM], int i, int j)
{
    float smedia;
    int s[8];
    int l=0, r, c, k, m=0;

            for ( r=i-1 ; r < i+2; r++)
            {
                for ( c = j-1; c< i+2; c++)


                {
                    if( dentro(r, c)==1 )
                    {
                        s[l]=matr_orig[r][c];
                        l++;
                    }
                    

                }
            }
    
    for(k=0; k<l; k++)
    {
        m=m+s[k];

    }    
    
    smedia = m / l;


    return smedia;
}

void calcola(t_matrice matr_media, int matr_orig[DIM][DIM])
{
    int i, j;
    for ( i = 0; i < DIM; i++ )
    {
        for ( j = 0; j < DIM; j++ ) 
        {
            matr_media[i][j] = media(matr_orig, i, j); // matr_orig = l'indirizzo del primo elemento della matrice
            
        }
        
    }
    
}

int main()
{
    t_matrice matr_media;
    int matr_orig[DIM][DIM];
    int i, j;

    srand(time(NULL));

    for ( i = 0; i < DIM; i++)
    {
        for ( j = 0; j < DIM; j++)
        {
            matr_orig[i][j]= rand() % 10;
        }
        
    }
    
    calcola(matr_media, matr_orig);

    printf("La matrice originale è:\n");
    for ( i = 0; i < DIM; i++)
    {
        for ( j = 0; j < DIM; j++)
        {
            printf("%d\t", matr_orig[i][j]);
        }
        printf("\n");
        
    }
    
    printf("La matrice media è:\n");
    for ( i = 0; i < DIM; i++)
    {
        for ( j = 0; j < DIM; j++)
        {
            printf("%f\t", matr_media[i][j]);
        }
        printf("\n");
        
    }

    return 0;
}

