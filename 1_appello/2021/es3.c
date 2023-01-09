#include <stdio.h>
#include <stdlib.h> // atoi()
#include <string.h>

#define N 1000

int main(int argc, char *argv[]) // argc è un vettore di stringhe
{   
    if(argc - 1 != 4)
    {
        printf("Mancano alcuni parametri.");
        return -1;
    }

    // argv[0] = <percorsofile>
    int l1 = atoi(argv[1]), l2 = atoi(argv[2]), l3 = atoi(argv[3]), l4 = atoi(argv[4]);
    
    FILE *fp;
/*
    char nomefile[50];
    printf("\nInserisci il nome del file da aprire: ");
    scanf("%s", nomefile);
*/
    fp = fopen("file.txt", "r");

    // controllare se il file è stato aperto correttamente
    if(fp == NULL)
    {
        printf("Errore di apertura del file.");
        return -1;
    }

    int numcifre, vet[N], i, num, k = 0;
    char str[9]; // numero massimo di cifre in un numero: 9 + carattere terminatore: '\0'

    // il file potrebbe essere vuoto e quindi avere come primo carattere EOF

    numcifre = fgetc(fp) - '0';  // errore: numcifre = fgetc(fp) => outpui: valore decimale ASCII del carattere in questione
    while(!feof(fp)) // feof(fp) è una funzione
    {
        for(i = 0; i < numcifre; i++)
        {
            str[i] = fgetc(fp);
        }

        str[i] = '\0'; // carattere terminatore in ultima posizione 
        num = atoi(str); // converte una stringa in un valore integer

        /*
        Alternativa:
        num = c - '0' // diffrenza dei valori decimali in ASCII tra un eventuale carattere (numero) e il carattere zero => distanza tra i due caratteri => numero cercato

        Errore: 
        il casting (int) str ritorna come valore il valore decimale ASCII e NON il numero cercato. 

            (int) char a = '1';
            printf("%d", a); // output: 49
        */
 
        // condizione affinché un numero sia valido
        if((num >= l1 && num <= l2) || (num > l3 && num < l4))
        {
            printf("\nIl numero %d e' valido.", num);

            // rapprensenta una situazione di POTENZIALE pericolo di sfondamento del vettore. Il programma però deve continuare a scandire il file e uscire dal ciclo while perché i casi sono due:
            // - potrebbe essere che ci siano altri numeri che soddisfano la condizione e solo in questo caso ci sarebbe uno sfondamento del vettore perché il programma non riuscirebbe più caricare valori in VET essendo pieno
            // - potrebbe essere che non ci NON ci siano più numeri che soddisfano la condizione e quindi il programma scandisce il file fino alla fine (EOF), termina normalmente e il vettore rimane pieno senza sfondarlo
            if(k == N) 
            {
                printf("\nIl vettore VET e' pieno.");
                k++;
            }
            else if(k == N + 1)
            {
                printf("\nSfondamento del vettore VET.");
                return -1;
            }
            else
            {
                vet[k] = num;
                k++;
            }
        }
        else
        {
            printf("\nnumFuori: %d", num);
        }

        strcpy(str, " "); // Per resettare la stringa str con str[0] = " " e str[1] = '\0'
        numcifre = fgetc(fp) - '0';
    }
    return 1;
}