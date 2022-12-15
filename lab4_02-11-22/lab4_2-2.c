#include <stdio.h>	
#include <stdlib.h>
#include <time.h>
	
/*dichiarazioni funzioni */
int genera_matrice(int mat[2][2], int *somma_elementi);
int genera_matrice2(int mat[2][2], int *determinante);
void genera_matrice3(int mat[2][2], int *determinante, int *somma_elementi);
	
int main() 
{	
    int mat[2][2], determinante, somma_elementi, i, j;
        
    //"Es4.2 - Generazione e analisi di una matrice quadrata 2 x 2.\n";
    printf("Es4.2 - Generazione e analisi di una matrice quadrata 2 x 2.\n");
    srand(time(NULL));
        
    //soluzione 1	
    determinante = genera_matrice(mat, &somma_elementi);

    //soluzione 2	
    //somma_elementi = genera_matrice2(mat, &determinante);
        
    //soluzione 3
    //genera_matrice3(mat, &determinante, &somma_elementi);

    printf("Matrice 2 x 2:\n");	
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            printf("%2d", mat[i][j]);        
        }
        printf("\n");
    }

    printf("Determinante = %d\nSomma elementi = %d\n", determinante, somma_elementi);
    return 0;	
}

//soluzione 1: ritorna il determinante e riceve come parametro l'indirizzo della variabile somma	
int genera_matrice(int mat[2][2], int *somma_elementi) 
{
    int i, j, determinante;
    *somma_elementi = 0;

    for (i = 0; i < 2; i++) 
    {	
        for (j = 0; j < 2; j++) 
        {
            mat[i][j] = rand() % 10;
            *somma_elementi = *somma_elementi + mat[i][j];
        }
    }
        
    determinante = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    return determinante;
}
	
//soluzione 2: ritorna la somma e riceve il determinante per indirizzo
int genera_matrice2(int mat[2][2], int *determinante) 
{
    int i, j, somma_elementi = 0;	
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {
            mat[i][j] = rand() % 10;
            somma_elementi = somma_elementi + mat[i][j];
        }
    }
    *determinante = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    return somma_elementi;
}
	
//soluzione 3: riceve sia il determinante che la somma per indirizzo
void genera_matrice3(int mat[2][2], int * determinante, int * somma_elementi) 
{	
    int i, j;	
    * somma_elementi = 0;	
    for (i = 0; i < 2; i++) 
    {
        for (j = 0; j < 2; j++) 
        {	
            mat[i][j] = rand() % 10;
            * somma_elementi = * somma_elementi + mat[i][j];
        }
    }
    * determinante = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
}