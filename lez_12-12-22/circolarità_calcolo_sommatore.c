#include <stdio.h>
#include <limits.h>

int main()
{
    unsigned short int v = 0;

    while(1)
    {
        v++;
        if(v == 0)
        {
            printf("\n v = 0");
            break;
        }        
        else 
        {
            printf("\n%d", v);
        }
    }

    return 1;
}