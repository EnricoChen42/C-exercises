#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("NUmero di parametri passati: %d", argc);

    for(int i = 0; i < argc; i++)
    {
        printf("\nargv[%d]: '%s'", i, argv[i]);
    }

    int num = atoi(argv[1]);

    printf("Il numero inserito come primo parametro: %d\n", num);

    if(num % 2 == 0)
        printf("\nNumero pari.");
    else 
        printf("\nNUmero dispari.");

    return 0;
}

/*
gcc <nomefile>.c  
./a.exe (in Windows)
./a (in Linux)
*/