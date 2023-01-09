#include <stdio.h>
#include <stdlib.h> /* atoi */
int main()
{
    char a = '0';
    char b = '2';
    char c = '4';

    char str[9];
    str[0] = a;
    str[1] = b;
    str[2] = c; 
    str[3] = '\0';

    printf("%s", str);

    // Converte la stringa in int
    int num = atoi(str); 

    printf("\n%d", num);

    
}