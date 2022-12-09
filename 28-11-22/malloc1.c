#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *vet, dim;

	printf("Inserire il numero di elementi:  ");
	scanf("%d", &dim);

	vet = (int *) malloc(dim * sizeof(int));
}