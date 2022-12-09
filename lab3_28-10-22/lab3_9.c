#include <stdio.h>
#include <string.h>

#define NAMELEN 10  
#define NANAGR 5

typedef struct
{
    char nome[NAMELEN];
    char genere;
    int eta;
} s_anagr;

int i, j, m = 0, f = 0, k = 0;

s_anagr v_finale[NANAGR + 1], v_anagr_m[NANAGR], v_anagr_f[NANAGR];

int main()
{
    s_anagr v_anagr[NANAGR] = 
    {
        {"Topolino", 'M', 47},
        {"Minni", '-', 47},
        {"Pluto", 'M', 17},
        {"Clarabella", '-', 17},
        {"Pippo", 'M', 26}
    };

    for(i = 0; i < NANAGR; i++)
    {    
        // vettore con tutti i maschi
        if(v_anagr[i].genere == 'M')
        {
            v_anagr_m[m] = v_anagr[i];
            m++;
        }
        // vettore con tutti le femmine
        else if(v_anagr[i].genere == 'F')
        {
            v_anagr_f[f] = v_anagr[i];
            f++;            
        }
    }

    v_finale[0] = v_anagr_m[0], v_finale[1] = v_anagr_f[0];

    // maschio più giovane
    for(i = 0; i < m && m > 0; i++)
        if(v_anagr_m[i].eta < v_finale[0].eta)
            v_finale[0] = v_anagr_m[i];

    // femmina più giovane
    for(i = 0; i < f && f > 0; i++)
        if(v_anagr_f[i].eta < v_finale[1].eta)
            v_finale[1] = v_anagr_f[i];
             
    // maschi con più di 25 anni
    for(i = 0; i < m && m > 0; i++)
        if(v_anagr_m[i].eta > 25)
        {
            v_finale[2+k] = v_anagr_m[i];
            k++;
        }
    
    if(m == 0)
    {
        strcpy(v_finale[0].nome, "N/A");
        v_finale[0].eta = -1;
        v_finale[0].genere = 'M';
    }
    else if(f == 0)
    {
        strcpy(v_finale[1].nome, "N/A");
        v_finale[1].eta = -1;
        v_finale[1].genere = 'F';
    }

    // stampa di v_finale
    for(i = 0; i < 2 + k; i++)
        printf("Cella %d: %s, %c, %d\n", i, v_finale[i].nome, v_finale[i].genere, v_finale[i].eta);
}