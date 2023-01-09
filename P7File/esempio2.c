// Copia di un file in un altro file carattere per carattere

#include <stdio.h>
#include <stddef.h>

int main()
{
    FILE *fr, *fw;
    int c;

    fr = fopen("text.txt", "r");
    fw = fopen("newfile.txt", "w");

    if(fr == NULL && fw == NULL)
    {
        printf("Problema di apertura.");
        return 1;
    } 
    else 

    c = fgetc(fr);

    while(c != EOF)
    {
        fputc(c, fw);
        
    }

    fclose(fr);
    fclose(fw);

    return 0;
}   