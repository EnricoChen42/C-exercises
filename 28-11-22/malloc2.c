#include <stdio.h>
#include <stdlib.h>

int main()
{
	int quanti, i, *p;
	scanf("%d", &quanti);
	p = (int *) malloc(quanti * sizeof(int));

	if(p == NULL)
		printf("Error!");

	for(i = 0; i < quanti; i++)
		p[i] = i; // oppure *(p + i) = i;

	for(i = 0; i < quanti; i++)
		printf("%d", p[i]); // oppure *(p + i);
}