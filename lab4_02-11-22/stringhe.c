#include <stdio.h>
#include <string.h>

int main()
{
    char c = 'X';
    char a[] = "Politecnico";
    char *ptr1 = &c;
    char *ptr2 = a; // l'indirizzo del primo elemento dell'array
    char *ptr3 = &a[0];
    char *ptr4 = &a[6];
    char *ptr5 = a + 6;

    printf("%c - %c\n", *ptr1, ptr1[0]);
    printf("%c - %c - %c\n", *ptr2, ptr2[0], ptr2[4]);
    printf("%c\n", *ptr3);
    printf("%c - %c - %c\n", *ptr4, ptr4[0], ptr4[4]);
    printf("%c - %c - %c - %c - %c\n", *ptr5, ptr5[0], ptr3[6], *(ptr5 + 0), *(ptr3 + 6));

    // è sufficiente conoscere i valori relativi, non quelli assoluti per il calcolo corretto (ovvero il carattere 'b' dista 1 dal carattere 'a')
    char *t1;
    t1 = "abcd";
    printf("%d\n", t1[1] - 'a');
}

/*
- Una stringa in c non è altro che un array di caratteri
- Quindi un puntatore a una stringa è un puntatore a un array di caratteri
- e un puntatore a un array è lo stesso di un puntatore al suo primo elemento
*/
