// Legge una sequqenza di 100 numeri e la visualizza in ordine inverso senza usare vettore

#include <stdio.h>
int i = 1, max = 5;

void sequenza()
{
	int numero;
	scanf("%d", &numero);

	if(i == max)
	{
		printf("-%d", numero);
        return; 

	}
	else 
	{
		i++;
		sequenza();
		printf("-%d", numero);
        return;
	}
}

void main()
{
	sequenza();
}

