#include <stdio.h>

void main()
{
    char nome_txt[20], nome_bin[20];
    int numero_txt, numero_bin;

    FILE *fp_txt, *fp_bin;

    scanf("%s", nome_txt); 
    scanf("%s", nome_bin);

    fp_txt = fopen(nome_txt, "r");
    fp_bin = fopen(nome_bin, "rb");

    // legge i valori nei file testuali
    fscanf(fp_txt, "%d", &numero_txt);
    // leggi i valori nei file binari
    fread(%numero_bin, sizeof(int), 1, fp_bin);
    //fread lo converte in binario 

    // funzione feof riconosce la fine del file
    while(!(feof(fp_txt) || feof(fp_bin)))
    {
        if(numero_txt == numero_bin)
            printf("")
    }
    
    fclose(fp_bin);
    fclose(fp_txt);
}