/* Autore: Mattia Braguti
Data: 12-11-2022
Scopo del programma: ceterminare se la matrice è una valida soluzione al sudoku.
Il controllo sulle righe sembra funzionare, ma non quello sulle colonne. Sbaglio nel metodo risolutivo o nella scrittura del codice?
Su internet ho trovato qualcuno che fa la verifica con la somma della riga o della colonna, sembra più efficiente ma non so se si attiene alla consegna.
*/

#include <stdio.h>

int sudoku[9][9] = 
{ 
    {1,2,3,4,5,6,7,8,9}, 
    {4,5,6,7,8,9,1,2,3}, 
    {7,8,9,1,2,3,4,5,6}, 
    {2,3,4,5,6,7,8,9,1}, 
    {5,6,7,8,9,1,2,3,4}, 
    {8,9,1,2,3,4,5,6,7}, 
    {3,4,5,6,7,8,9,1,2}, 
    {6,7,8,9,1,2,3,4,5}, 
    {9,1,2,3,4,5,6,7,8}
};

int supporto[9];
int i, j, n, c = 0, ripetuto = 0;


void 


void main()
{
    // Controllo numeri righe.

    printf("\nControllo soluzione sulle righe:\n"); 
    
    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)    
            supporto[j] = sudoku[i][j];
    
        for(j = 0; j < 9; j++)
        {
            for (n = 0; n < 9; n++)
            {
                if(sudoku[i][j] == supporto[n])
                    c++;    
                
                if(c > 1)
                    ripetuto = 1;
            }
            c = 0;
        }

        if(ripetuto == 1)
            printf("- Soluzione del Sudoku non valida! Si corregga la riga %d\n", i+1);
        else if(ripetuto == 0)
            printf("- Riga %d ok.\n", i + 1);
        
        ripetuto = 0;
    }

    // Controllo numeri colonne

    printf("\nControllo soluzione sulle colonne:\n"); 
    
    for(j = 0; j < 9; j++)
    {
        for(i = 0; i < 9; i++)    
            supporto[i] = sudoku[i][j];
    
        for(i = 0; i < 9; i++)
        {
            for (n = 0; n < 9; n++)
            {
                if(sudoku[i][j] == supporto[n])
                    c++;    
                
                if(c > 1)
                    ripetuto = 1;
            }
            c = 0;
        }

        if(ripetuto == 1)
            printf("- Soluzione del Sudoku non valida! Si corregga la colonna %d.\n", j+1);
        else
            printf("- Colonna %d ok.\n", j + 1);
        
        ripetuto = 0;
    }
    printf("\n");
}

 
    

