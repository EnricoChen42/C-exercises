#include <stdio.h>
#include <math.h>

int main()
{
    int num, i, j, ris;
    printf("\nnum (>=0)? ");
    scanf("%d", &num);

    for(i = 1; pow(10, i) < num ; i++) {}


    for(j = i - 1; j >= 0; j--)
    {
        ris = num / pow(10, j);
        switch(ris)
        {
            case(0): printf("Zero "); break;
            case(1): printf("Uno "); break;
            case(2): printf("Due "); break;
            case(3): printf("Tre "); break;
            case(4): printf("Quattro "); break;
            case(5): printf("Cinque "); break;
            case(6): printf("Sei "); break;
            case(7): printf("Sette "); break;
            case(8): printf("Otto "); break;
            case(9): printf("Nove "); break;
            default: printf("Errore! "); break;
        }
         
        num = num % (int) pow(10, j);
    }
    printf("\n\n");
}