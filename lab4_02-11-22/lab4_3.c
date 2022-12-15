#include <stdio.h>
#define TXTL 20

typedef struct {
    int anno;
    int mese;
    int giorno;
} s_data;

typedef struct {
    s_data data;
    char meteo[TXTL];
} s_bollettino;

int gg_mese[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, y_verifica_data, y_anno_bisestile;

int anno_bisestile(int anno);

int verifica_data(s_data data);

int giorni_da_capdanno(s_data data);

void ins_bollettino(s_bollettino *bollettino);

void stampa_bollettino(s_bollettino *bollettino);

int main()
{
    printf("Inserimento dei dati di un bollettino Meteo");
    s_bollettino bollettino;
    
    ins_bollettino(&bollettino);

    if(y_verifica_data == 1)
    {
        printf("\nLa data e' corretta.");
        stampa_bollettino(&bollettino);
    }

    if(y_verifica_data == 0)
        printf("\nLa data e' incorretta.");
    
    return 1;
}

void ins_bollettino(s_bollettino *bollettino)
{ 
    printf("\nMeteo? ");
    fflush(stdin);
    scanf("%s", &bollettino -> meteo);

    printf("Anno? ");
    fflush(stdin);
    scanf("%d", &bollettino -> data.anno);    

    printf("Mese? ");
    fflush(stdin);
    scanf("%d", &bollettino -> data.mese);

    printf("Giorno? ");
    fflush(stdin);
    scanf("%d", &bollettino -> data.giorno);

    y_verifica_data = verifica_data(bollettino -> data);
}

int anno_bisestile(int anno)
{
    // Le condizioni affinché un anno sia bisestile
    if(anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0))
        return 1;
    return 0;
}

int verifica_data(s_data data)
{   
    // Verifica se l'anno è corretto
    if(data.anno < 2000)
    {
        printf("Anno %d incorretto.", data.anno);
        return 0;
    }
    printf("Anno %d corretto.", data.anno);

    // Verifica se il mese è corretto
    if(data.mese < 1 || data.mese > 12)
    {
        printf("\nMese %d incorretto.", data.mese);
        return 0;
    }
    printf("\nMese %d corretto.", data.mese);

    // Verifica se è un anno bisestile
    y_anno_bisestile = anno_bisestile(data.anno);

    // Se l'anno è bisestile, febbraio ha 29 giorni invece che 28
    if(y_anno_bisestile == 1)
        gg_mese[1] = 29;
  
    // Verifica se il giorno è corretto
    if(data.giorno < 1 || data.giorno > gg_mese[data.mese - 1])
    {
        printf("\nGiorno %d incorretto.", data.giorno);
        return 0;
    }
    printf("\nGiorno %d corretto.", data.giorno);

    return 1;
}

int giorni_da_capodanno(s_data data)
{
    int giorni_tot = 0, i;

    for(i = data.mese; i >= 1; i--)
    {
        if(i == data.mese)
            giorni_tot += data.giorno;
        else
            giorni_tot += gg_mese[i];

    }
    return giorni_tot;
}

void stampa_bollettino(s_bollettino *bollettino)
{
    printf("\nBollettino Meteo %d/%d/%d: %s.", bollettino -> data.giorno, bollettino -> data.mese, bollettino -> data.anno, bollettino -> meteo);

    if(y_anno_bisestile == 1)
        printf("\nL'anno %d e' bisestile.", bollettino -> data.anno);
    
    printf("\nSono trascorsi %d giorni dall'inizio dell'anno.", giorni_da_capodanno(bollettino -> data));
}