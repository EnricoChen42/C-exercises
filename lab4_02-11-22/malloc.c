#include <stdio.h> // printf, scanf, NULL
#include <stdlib.h> // malloc, free, rand 
#include <time.h> // time()

int main()
{
    int i, n;
    char *buffer;

    printf("Lunghezza della stringa? ");
    scanf("%d", &i);

    buffer = (char *) malloc(i + 1); // sizeof(char) == 1; stringa + '\0'
    if(buffer == NULL) exit(1); // 1 == errore
    srand(time(NULL)); // se non ci fosse, il programma generebbe lettere sempre uguali ad ogni esecuzione

    for(n = 0; n < i; n++)
        buffer[n] = rand() % 26 + 'a'; // generazione di numeri tra 0 e 2 + traslazione di 97 == 'a' (ASCII)
    buffer[i] = '\0';

    printf("Stringa RANDOM: %s\n", buffer);
    free(buffer);

    return 0;
}
