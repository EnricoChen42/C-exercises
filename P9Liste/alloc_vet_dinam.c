#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quanti, i, *p;
    printf("\nQuanti elementi vuoi inserire? ");
    scanf("%d", &quanti);

    p = malloc(quanti * sizeof(int));

    for(i = 0; i < quanti; i++)
        p[i] = i; // *(p + i) = 0;

    for(i = 0; i < quanti; i++)
        printf("%d ", p[i]); // *(p + 1);

}