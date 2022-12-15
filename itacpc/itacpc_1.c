#include <stdio.h>
#include <string.h>

void stampa(char v1[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%s", &v1);
    
    
}
int main()
{
    int n;
    printf("Inserisci un numero:\n");
    scanf("%d", &n);
    fflush(stdin);


    char v1[n];

    for(int i = 0; i < n; i++)
    {
        printf("Inserisci una disugualianza:\n");
        scanf("%s", &v1[i]);
    }

    stampa(v1, n);

    return 0;
}