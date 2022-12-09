#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int t1, int v2)
{
    if(t1 > v2)
        return t1; 
    else 
        return v2;
}

char *s(char *t1, char *v2)
{
    char *r;
    int c = 0;
    int i;
    r = (char *) malloc(sizeof(char)*max(strlen(t1), strlen(v2)) + 2); // sizeof(char) == 4

    for(i = 0; t1[i] != '\0'; i++)
    {
        r[i] = ((t1[i] - 'a') + (v2[i] - 'a') + c) % 2 + 'a'; // BREAK qui
        c = ((t1[i] - 'a') + (v2[i] - 'a') + c) / 2;
    }

    r[i] = c + 'a';
    i++;
    r[i] = '\0';
    return r;
}

int main()
{
    printf("%s\n", s("ddab", "eflm"));
    printf("%s\n", s("aaaa", "bbbb"));
    return 0;
}