#include <stdio.h>
#include <string.h>

#define TENTATIVI 10
#define MAX 30

int i, j, lun, esc = 0, con, tot = 0, ten = 0;
char ind[MAX], let, cop[MAX], tra[MAX];

int main()
{
    printf("\n---- Il gioco dell'impiccato ----\n\n");

    // Inserimento della parola da indovinare
    printf("Inserisci una parola da indovinare: ");
    scanf("%s", ind);  
    getchar();
    printf("\n");

    // Numero di caratteri della parola
    lun = strlen(ind);

    // Nuovo vettore con tutto '_'
    for(i = 0; i < lun; i++)
        tra[i] = '_';

    while(esc == 0)
    {
        // Inserimento della lettera da parte del giocatore
        printf("Inserisci una lettera: ");
        scanf("%c", &let);
        getchar();

        con = 0;

        // Sostituisco la lettera indovinata con '*'
        for(i = 0; i < lun && con == 0; i++)
        {
            if(ind[i] == let)
            {   
                tra[i] = ind[i];
                ind[i] = '*';
                con = 1;
                tot++;
                if(tot == lun)
                    esc = 1;
            }
        }

        // Stampo il risultat

        if(con == 1)
        {
            if(esc == 0)
                printf("- Hai indovinato una lettera: %s\n\n", tra); 
            else if(esc == 1)
                printf("- Congratulazioni! Hai completato la parola: %s\n\n", tra);
        }
        else if(con == 0)
        {
            ten++;
            if(ten < TENTATIVI)
            {
                
                printf("- La lettera è sbagliata: %s. Riprova.\n", tra);
                printf("Ti rimangono %d tentativi.\n\n", TENTATIVI-ten);
              
                if(ten == 1)
                {
                    printf("--+--\n\n");
                }
                else if(ten == 2)
                {
                    printf("  |\n  |\n  |\n--+--\n\n");
                }
                else if(ten == 3)
                {
                    printf("  +-+\n  |/\n  |\n  |\n  |\n  |\n  |\n  |\n--+--\n\n");
                }
                else if(ten == 4)
                { 
                    printf("  +-+----+\n  |/     |\n  |\n  |\n  |\n  |\n  |\n  |\n--+--\n\n");
                }
                else if(ten == 5)
                {
                    printf("  +-+----+\n  |/     |\n  |      0\n  |\n  |\n  |\n  |\n  |\n--+--\n\n");
                }
                else if(ten == 6)
                {
                    printf("  +-+----+\n  |/     |\n  |      0\n  |      +\n  |\n  |\n  |\n  |\n--+--\n\n");
                }
                else if(ten == 7)
                { 
                    printf("  +-+----+\n  |/     |\n  |      0\n  |    --+--\n  |\n  |\n  |\n  |\n--+--\n\n");
                }
                else if(ten == 8)
                {
                    printf("  +-+----+\n  |/     |\n  |      0\n  |    --+--\n  |      |\n  |\n  |\n  |\n--+--\n\n");
                }
                else if(ten == 9)
                {
                    printf("  +-+----+\n  |/     |\n  |      0\n  |    --+--\n  |      |\n  |     /\n  |    /\n  |\n--+--\n\n");
                }
            }
            else if(ten == TENTATIVI)
            {
                    printf("Hai perso! Hai finito il numero di tentativi.\n\n");
                    printf("  +-+----+\n  |/     |\n  |      0\n  |    --+--\n  |      |\n  |     / \\ \n  |    /   \\ \n  |\n--+--\n\n");
                    esc = 1;
            }
        }
    } 

    return 0;
}


/*

1) 

--+--

2)

  |
  |
  |
--+--

3)

  +-+
  |/     
  |
  |
  |
  |
  |
  |
--+--

4) 

  +-+----+
  |/     |
  |
  |
  |
  |
  |
  |
--+--

5)

  +-+----+
  |/     |
  |      0
  |
  |
  |
  |
  |
--+--

6) 

  +-+----+
  |/     |
  |      0
  |      +
  |
  |
  |
  |
--+--

7)

  +-+----+
  |/     |
  |      0
  |    --+--
  |
  |
  |
  |
--+--

8)

  +-+----+
  |/     |
  |      0
  |    --+--
  |      |
  |
  |
  |
--+--

9)

  +-+----+
  |/     |
  |      0
  |    --+--
  |      |
  |     / 
  |    /
  |
--+--

10)

  +-+----+
  |/     |
  |      0
  |    --+--
  |      |
  |     / \
  |    /   \
  |
--+--

*/




