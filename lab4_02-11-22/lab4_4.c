#include <stdio.h>
#include <string.h>
#define DIM 50

char result[DIM];

void estrazione(char orig[], char carat)
{
    int i, j = 0, counter = 0, start_copy = 0;

    for(i = 0; i < strlen(orig); i++)
    {   
        if(orig[i] == carat && counter != 2)
        {
            start_copy = 1;
            counter++;
        }

        if(start_copy == 1)
        {
            result[j] = orig[i];
            j++;
        }

        if(counter == 2)
            start_copy = 0;
    }
    result[j] = '\0';

}

int main()
{
    char orig[DIM], carat;
    printf("stringa in ingresso? ");
    fgets(orig, DIM, stdin);
    orig[strcspn(orig, "\n")] = 0;

    printf("carattere? ");
    scanf("%c", &carat);

    int lenght_orig = strlen(orig);
    
    estrazione(orig, carat);

    printf("sottostringa: %s", result);

    return 0;
}