#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main()
{
    short int v = 0;

    while(1)
    {
        v++;
        printf("\n%d", v);
        if(v <= 0)
            sleep(1);
        
        if(v == 0) {
            printf("\n v = 0");
            break;
        }
    }
}