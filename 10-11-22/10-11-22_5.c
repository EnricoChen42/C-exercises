#include <stdio.h>

void main()
{
    FILE *fp;
    char oneword[100];
    char *char
    fp = fopen("TENLINES:TXT", "r");

    if(fp != NULL)
    {
        do
        {
            // mi restituisce un puntatore carattere
            c = fgets(oneword, 100, fp);
            // \n rimane incluso nella stringa

            if(c != NULL)
                printf("%s", oneword);
        } while(c != NULL);
    }
}