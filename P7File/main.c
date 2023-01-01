#include <stdio.h>


int main()
{
    // fptr = file pointer
    FILE *fptr;

    // "r" = read mode
    fptr = fopen("text.txt", "r");

    char content[1000];

    if(fptr != NULL)
    {
        printf("\nFIle Open Successful.");

        // reads the file and stores in the content array
        // only reads the first sentene at a time
        while (fgets(content, 1000, fptr))
        {
            printf("%s", content);
        }
        
        // to close the file
        fclose(fptr);
        printf("\nFile Closed Successful");
    }
    else    
        printf("\nFile Open Unsuccessful.");

    // "w" = write mode
    // Se il file non esiste lo crea, se no sovrascrive tutto
    fptr = fopen("newfile.txt", "w");
    fputs("Hello World", fptr);
    fputs("\nI just want to say thank you to everybody.", fptr);
    fclose(fptr);

    return 0;
}