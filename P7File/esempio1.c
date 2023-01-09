// Lettura file a caratteri e visualizzazione

#include <stdio.h>
#include <stddef.h> /* NULL */

int main()
{
    FILE *fp;
    char c;
    fp = fopen("newfile.txt", "r");

    if(fp == NULL)
    {
        printf("IL file non puo' essere aperto\n");
        return 1;
    }

    // Potrebbe esserci come primo carattere EOF
    c = fgetc(fp);
    while(c != EOF)
    {
        putchar(c);
        c = fgetc(fp);  
    }
    fclose(fp);

    return 0;
}