#include <stdio.h>
#define ull unsigned long long

int fatt(int n)
{
    if(n == 0) // 0! = 1
        return(1); 
    else 
        return(n  * fatt(n - 1));
}

void main()
{
    int n, r;
    printf("\nvalore di n: ");
    scanf("%llu", &n);
    r = fatt(n);
    printf("il fattoriale di %llu è %llu", n, r);
    
}

// Bisogna stare attenti a inseriri numeri piccoli (n <= 33),
// perché il fattore di n cresce molto rapidamente al crescere di n.
// Se no, il programma va in overflow e restituisce zero.