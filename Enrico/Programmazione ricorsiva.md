Date: 28/11/22
Course: [[Fondamenti di Informatica]]

## Programmazione ricorsiva

### Esempio 1
```clike
// Fattoriale di un numero
#include <stdio.h>
#define ull unsigned long long

int fatt(int n)
{
	if(n == 0) // 0! = 1
		return(1);
	else
		return(n * fatt(n - 1));
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
```

Formulazione ricorsiva di algoritmi: 
- identificare uno o più sottocasi che definiscono la terminazione (in questo caso "n == 0");
- determinare il passo ricorsivo: sottocaso del problema tale per cui la soluzione del sottocaso = alla soluzione del problema, ma su un insieme ridotto di casi

### Esempio 3
```clike
/* Legge una sequqenza di 100 numeri e la visualizza in ordine inverso senza usare vettore*/

#include <stdio.h>

int i = 1, max = 100;

void sequenza
{
	int numero; // Se la variabile fosse globale scanf lo sovrascriverebbe
	scanf("%d", &numero);

	if(i == max)
	{
		printf("-%d", numero);
		return; //facoltativo
		// the function is declared as returning void. So there is no value returned. So when you use return, it exits the fuction and back to the caller.
	}
	else 
	{
		i++;
		sequenza();
		printf("-%d", numero);
		return; //facoltativo
	}
}

void main()
{
	sequenza();
}
```

Se un'istanza di sequenza() finisce di eseguire tutto il sottoprogramma, allora, ridà il controllo all'istanza precedente ed è per questo che i "return" possono essere omessi.

### Stack e RDA con blocchi e ricorsione
Se un RDA dello Stack non trova un dato, lo cerca nell'area di globale, risalendo di un livello.

```clike
// Indicare, rispettando il formato di stampa previsto che cosa apparirà in video.

#include <stdio.h>

void f(int y, int lim)
{
	if(y == lim)
		return;
		
	if(y < lim)
	{
		printf("\ny = %d lim = %d", y, lim);
		return;
	}
	printf("\ny = %d", y);
	f(y-2, lim);
	printf("\n%d", y);
}

int main()
{
	f(12, 6);
	printf("\nfine attivazione");
}
```

Output:
```clike

y = 12
y = 10
y = 8
8
10
12
fine attivazione
```


## Strutture dati dinamiche

Esempi già visti d uso dei puntatori:
```clike
int a;
int *p = &a, *q;
...
q = p;
p = NULL;

if(p == q) // o (p == NULL)
	(*p) = 3;
```

Dinamiche: 
- a struttura nota a compile-time (tipo);
- creazione e deallocazione gestite dal programmatore;
- referenza solo tramite indirizzo (puntatore) perché non hanno nome

### Creazione e distribuzione variabili dinamiche
```clike
void malloc(sizeof(int))
```
- `sizeof()` restituisce quanti byte occupa un tipo di variabile;
- `malloc()` (Memory ALLOCation):
1) alloca nell'area di Heap degli spazi contigui di memoria. Quanto? In base al parametro che gli viene assegnato (`sizeof(int) output: 4`);
2) Restituisce un puntatore void (di nessun tipo) che punta a questi spazi. In particolare, contiene l'indirizzo del primo byte allocato dalla `malloc`.

Però, abbiamo bisogno di un puntatore associato a un tipo di dato e quindi eseguiamo un casting:
```clike
p = (int *) malloc(sizeof(int));
```

### Esempio 1
```clike
#include <stdio.h>

int main
{
	int *vet, dim;

	printf("Inserire il numero di elementi:  ");
	scanf("%d", &dim);

	p = (int *) malloc(dim * sizeof(int)); //es: 10 (elementi) * 4 (byte) = 40 byte
}
```

BIsogna poi controllare l'esito della malloc:
```clike
void test()
{
	if(p == NULL) 
		return;
}
```


### Allocazione e deallocazione nell'area di HEAP
- La possibile allocazione di blocchi "potenzialmente" di dimensione variabile permette di avere degli spazi heap ancora liberi, ma che sono frammentati in dei blocchi liberi troppo piccoli.
- Nel linguaggio C non ci sono meccanismi automatici di gestione dell'area di heap e spetta al programmare il compito di gestirlo

### Allocazione di un vettore di dimensione dinamica

```clike
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
```

### Gestione memoria e problemi
```clike
typedef struct {int a; int b;} rec;

p = (rec *) malloc(sizeof(rec));
if(p == NULL)
	printf("Error!");

q = (rec *) malloc(sizeof(rec));
if(q == NULL)
	printf("Error!");

(*p).a = 3; oppure p -> a = 3;
(*q).a = 3; oppure q -> a = 3;
```

a) produzione diretta di garbase: variabile dinamica irrangiungibile
```clike
p = q;
```

b) generazione dangling reference: puntatore con indirizzo non valido 
```clike
freqq(q);
p -> a = 2;
p -> a = 2;
// errore in esecuzione
```
c) produzione indiretta di garbage:
quando il sottoprogramma termina, lo stack viene deallocato mentre nell'area di Heap l'area di memoria rimane.

```clike
void P()
{
	int *p;
	p = (int *) malloc(sizeof(int));
}

int main()
{
	P();
}
```

d) produzione indiretta di dangling reference:
le varaibili nell'area globale esistono fino alla fine dell'esecuzione del programma. Quando il sottoprogramma termina, lo stack viene deallocato però così il puntatore p punta a un'area di dati che non esiste più
```clike
int *p;

void F()
{
	int n; 
	p = &n;
}

int main()
{
	F();
}
```

