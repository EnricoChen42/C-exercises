#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define EN_MAX 5
#define DIM_MARE 5
#define N_NAVI 5
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef struct st_nave{
    int r; // Indice di riga da 0 a DIM_MARE - 1
    int c; // Indice di colonna da 0 a DIM_MARE - 1
    int energia; // Da 0 a EN_MAX
} s_nave;

void setup(int mare[DIM_MARE][DIM_MARE], s_nave flotta[N_NAVI]);

void stampa_mare(int mare[DIM_MARE][DIM_MARE]);

void stampa_flotta(s_nave flotta[N_NAVI]);

void fuoco(int mare[DIM_MARE][DIM_MARE], s_nave flotta[N_NAVI], int *counter_shots);

void gameover(int *counter_shots);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int mare[DIM_MARE][DIM_MARE], counter_shots = 0;
    s_nave flotta[N_NAVI];

    setup(mare, flotta);

    stampa_mare(mare);

    stampa_flotta(flotta);

    fuoco(mare, flotta, &counter_shots);

    gameover(&counter_shots);

    return 0;
}

void setup(int mare[DIM_MARE][DIM_MARE], s_nave flotta[N_NAVI])
{
    int i, j;

    for(i = 0; i < DIM_MARE; i++)
    {
        for(j = 0; j < DIM_MARE; j++)
        {
            mare[i][j] = -1;
        }
    }   

    int temp1, temp2, identical;

    for(i = 0; i < N_NAVI; i++)
    {   
        do
        {
            identical = 0;
            temp1 = rand() % DIM_MARE;
            temp2 = rand() % DIM_MARE;

            for(j = i - 1; j >= 0; j--)
            {
                if(flotta[j].r == temp1 && flotta[j].c == temp2)
                    identical = 1;
            }
                    
        } while(identical == 1);

        flotta[i].r = temp1;
        flotta[i].c = temp2;
        flotta[i].energia = rand() % (EN_MAX + 1 - 1) + 1; // between 1 and 5
        mare[flotta[i].r][flotta[i].c] = i;
    }
}

void stampa_mare(int mare[DIM_MARE][DIM_MARE])
{
    printf("\nMare:");
    printf("\n         0    1    2    3    4");
    printf("\n------------------------------");
    
    for(int i = 0; i < DIM_MARE; i++)
    {
        printf("\n  %d  | ", i);
        for(int j = 0; j < DIM_MARE; j++)
        {
            if(mare[i][j] == -1)
                printf(" %d  ", mare[i][j]);
            else 
                printf(ANSI_COLOR_RED "  %d  " ANSI_COLOR_RESET, mare[i][j]);
        }
    }
}

void stampa_flotta(s_nave flotta[N_NAVI])
{
    printf("\n\nFlotta:");

    for(int i = 0; i < N_NAVI; i++)
    {
        printf("\nNave %d in (%d, %d). Energia = %d.", i, flotta[i].r, flotta[i].c, flotta[i].energia);
    }
}

void fuoco(int mare[DIM_MARE][DIM_MARE], s_nave flotta[N_NAVI], int *counter_shots)
{
    int temp1, temp2, counter_ships = N_NAVI, hit;
    printf("\n\nPartita:");

    while(counter_ships > 0)
    {   
        hit = 0;   
        temp1 = rand() % DIM_MARE;
        temp2 = rand() % DIM_MARE;

        printf("\nFuoco coordinate (%d, %d):", temp1, temp2);

        for(int i = 0; i < N_NAVI; i++)
        {
            if(temp1 == flotta[i].r && temp2 == flotta[i].c)
            {
                if(flotta[i].energia >= 2)
                {
                    (flotta[i].energia)--;  
                    printf(" Nave %d colpita! Energia rimanente = %d.", i, flotta[i].energia);
                }
                else if(flotta[i].energia == 1)
                {
                    (flotta[i].energia)--;
                    counter_ships--;
                    printf(" Nave %d colpita e affondata!", i);
                }
                else if(flotta[i].energia == 0)
                    printf(" Nave %d gia' affondata...", i);
                
                hit = 1;
                (*counter_shots)++;
            }
        }

        if(hit == 0)
            printf(" Acqua!");
    }
}

void gameover(int *counter_shots)
{
    printf("\n\nTutte le navi sono state affondate dopo %d colpi!", *counter_shots);
}


