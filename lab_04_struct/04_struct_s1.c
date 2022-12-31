#include <stdio.h>
#define max 5

typedef struct 
{
	char nome[40];
	char cognome[40];
	int matricola;
	int voto;

} studente;

int main()
{
	int i, voto, search_mat, trovato = 0, k;

	studente classe[max] = 
    {    
        {"Harry", "Potter",17593, 0}, 
        {"Hermione", "Granger", 27573,0},
	    {"Tony", "Stark", 16553, 0},
        {"John", "Snow", 18595, 0},
        {"Frodo", "Baggins", 12715, 0}
    };
	
	printf("Dammi la matricola dello studente per inserire il suo voto: ");
	scanf("%d", &search_mat);

	printf("\nChe voto ha preso? ");
	scanf ("%d", &voto);
	
	for (i = 0; trovato == 0 && i < max; i++)
    {
		if(classe[i].matricola == search_mat)
        {
			trovato = 1;
			classe[i].voto = voto;
            k = i;
		}	
	}

	if(trovato != 0)
    {
		printf("\nHai inserito la valutazione allo studente %s %s.", classe[k].nome, classe[k].cognome);
		printf("\nLa sua matricola  e: %d", classe[k].matricola);
		printf("\nLa sua valutazione  e: %d.", classe[k].voto);
	}
	else
		printf("\nLa matricola non corrisponde a nessuno studente.");

    return 0;
}