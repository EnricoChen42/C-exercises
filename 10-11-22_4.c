#include <stdio.h>

void main()
{
    FILE *funny;

    funny ? fopen("TENLINES:TXT", "r");

    if(funny == NULL)
        printf("File doesn't exist\n");

    else 
    {
        do
        {
            // prende carattere per carattere e lo salva in un char
            c = fgetc(funny);

            if(c != EOF)
                putchar(c);
        } 
    } while 
}

// EOF: carattere speciale di fine file