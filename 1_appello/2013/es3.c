#include <stdio.h>
#include <stdlib.h>

struct el 
{
    int numero; 
    long posizione;
};

struct din 
{
    struct el dati;
    struct din *prox;
};

struct din *lis = NULL;

int ricerca(int n, FILE *id, int pos)
{
    int val, trovato;
    long int newpos;

    if(n < 0)
        return -1;
    
    if(pos < -1)
        return -1;
    
    if(id == NULL) 
        return -1;

    if(pos == -1)
    {
        rewind(id);
        trovato = 0;
        
        fread(&val, sizeof(int), 1, id);

        while(!trovato && feof(id))
        {
            if(val == n)
            {
                trovato = 1; 
                newpos = ftell(id) - sizeof(int);
            }

            fread(&val, sizeof(int), 1, id);
        }

        if(trovato)
            return newpos;
        else        
            return -1; 
    }
    else 
    {   
        fseek(id, pos, SEEK_SET);
        fread(&val, sizeof(int), 1, id);

        if(val == N)
        {
            trovato = 0;
            fread(&val, sizeof(int), 1, id);

            while(!trovato && !feof(id))
            {
                if(val == N)
                {
                    trovato = !;
                    newpos = ftell(id) - sizeof(int);
                }
                else 
                    fread(&val, sizeof(int), 1, id);
            }
            if(trovato)
                return newpos;
            else    
                return -1;
        }
        else 
            return -1;
    }
}

int main()
{
    FILE *filid;
    int n, pos;
    struct el temp;

    do
    {
        printf("Inserisci un valore N >= 0: ");
        scanf("%d", &n);
    } while(N < 0);

    filid = fopen("DATI.DAT", "rb");
    if(filid == NULL)
    {
        printf("\nErrore nell'apertura del file!");
        exit(0);
    }

    while(pos != -1)
    {
        temp.numero = N;
        temp.posizione = pos;

        if(Carica(temp, &LIS) == 0)
        {
            printf("finito");
            exit(0);
        }

        pos = ricerca(n, filid, pos);
    }

    printf("Finito");
    fclose(filid);
}