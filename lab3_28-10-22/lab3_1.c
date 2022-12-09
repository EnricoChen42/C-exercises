#include <stdio.h>
#define DIM_PIT 10

int i, j, k;

int main()
{
    printf("Tavola Pitagorica %d x %d\n", DIM_PIT, DIM_PIT);

    printf("           1       2       3       4       5       6       7       8       9      10\n");

    printf("--------------------------------------------------------------------------------------\n");

    for(i = 1; i <= DIM_PIT; i++)
    {
        k = 1;
        for(j = 1; j <= DIM_PIT; j++)
        {
            if(k == 1 && i != DIM_PIT)
                printf("   %d|\t", i);
            else if(k == 1 && i == DIM_PIT) 
                printf("  %d|\t", i);
            
            k++;

            if((i*j) % 5 == 0 && (i*j) % 7 == 0)
                printf("%3d*\t", i*j);
            else 
                printf("%4d\t", i*j);
        }
        printf("\n");
    }

    return 0;
}