#include <stdio.h>
#define ull unsigned long long

int main()
{
    ull a, b = 2, temp, cont = 0, k = -1, fat = 0, ris;
    scanf("%llu", &a);
    temp = a;

    while(temp != 1)
    {
        if(temp % b == 0)
        {
            printf("%llu / %llu = ", temp, b);
            temp = temp / b;
            printf("%llu\n", temp);
            cont++;

            if(k != b)
            {   
                fat++;
                k = b;
            }
        }
        else if(temp % b != 0)
            b++;
    }

    //da sistemare
    int n = cont, d = cont - fat;

    if(d == 0)
    {
        for(int i = n - 1; i != 0; i--)
        {
            n = n * i;
            ris = n;
        }
    }
    else if(d != 0)
    {
        for(int i = n - 1; i != 0; i--)
            n = n * i;

        for(int i = d - 1; i != 0; i--)
            d = d * i;
        
        ris = n / d;
    }
    printf("cont = %llu, fat = %llu\n", cont, fat);

    printf("%llu", ris + 1);

    return 0;
}