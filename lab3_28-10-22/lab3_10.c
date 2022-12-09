#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NMAX 100

int main()
{
    srand(time(NULL));
    int v1[NMAX], v2[10], i, k, dec0_9 = 0, dec10_19 = 0, dec20_29 = 0, dec30_39 = 0, dec40_49 = 0, dec50_59 = 0, dec60_69 = 0, dec70_79 = 0, dec80_89 = 0, dec90_99 = 0;

    for(i = 0; i < NMAX; i++)
        v1[i] = rand() % 100;

    for(i = 0; i < NMAX; i++)
        switch(v1[i] / 10)
        {
            case 0: dec0_9++; break;
            case 1: dec10_19++; break;
            case 2: dec20_29++; break;
            case 3: dec30_39++; break;
            case 4: dec40_49++; break;
            case 5: dec50_59++; break;
            case 6: dec60_69++; break;
            case 7: dec70_79++; break;
            case 8: dec80_89++; break;
            case 9: dec90_99++; break;
        }

    v2[0] = dec0_9;
    v2[1] = dec10_19;
    v2[2] = dec20_29;
    v2[3] = dec30_39;
    v2[4] = dec40_49;
    v2[5] = dec50_59;
    v2[6] = dec60_69;
    v2[7] = dec70_79;
    v2[8] = dec80_89;
    v2[9] = dec90_99;

    printf("\n");
    for(i = 0, k=0; i < 10; i++, k+=10)
        printf("- Ci sono %d numeri compresi tra %d..%d\n", v2[i], k, k+9);        

    printf("\n");

    return 0;
}