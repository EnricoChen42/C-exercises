
Date: [[22-11-22]]
Course: [[Fondamenti di Informatica]]
```clike
void F1(int x) //x parametro formale definiscono nomi nuovi e vengono aggiunti ai dati locali (d) -> l'inzieme dei nomi formali
{
	T d; 
	{int c; ... blocco3
	             {int f = 4, blocco4}
	}
	x = 3;
	T = 4;
	J = 5;
	F1(4);
}

int main()
{
	T a; //T appartiene all'insieme dei nomi locali definiti nel main
	// Per isolare all'interno della funzione, una porzione di codice indipendente
	{int b; ... blocco1} // variabili locali che sono validi solo all'interno del blocco
	{char c; ... blocco2}
}
```
Non usare una soluzione ricorsiva nell'esame!

### FUNZIONI
Non ammette che una f sia definita all'interno di una funzione. Dal punto di vista gerarchico stanno sullo stesso piano e per usarli bisogna prima definirli. 
I nomi stessi di funzioni appartenti all'area dati globale dei nomi definiti.

### BLOCCHI
I blocchi sono definitii in modo sequenziali e vengono esecuti in modo sequenziale. 

### VARIABILI
Definire le variaibli nell'area locale dove serve veramente, piusttosto che nell'area globale. Quando la funzione finisce la sua esecuzione, dealloca l'area di dati per le variabili.

#### Regola di base:
- il blocco/funzione coincide con il campo di validità dei suoi  nomi 
locali; (i nomi locali sono utilizzabili dove sono stati definiti);
- se un blocco/funzione contiene altri blocchi, il campo di validità dei 
nomi del blocco/funzione più esterno si estende ai blocchi innestati; (eredità)
- il campo di validità dei nomi globali coincide con l'intero programma. 
- I nomi locali globali sono definiti e richiamabili in tutte le funzioni.

Esercizio possibile: definire la struttura gerarchicha del campo di validità di un codice

Regola campo di validità non è sufficiente:
```clike
int i;
int main()
{
	int i; i = 3
}
```
Funzione anche se ci sono due 'i'. Nel main vediamo entrambi le variabili e quindi è presente un margine di ambiguità.
 
Dato un nome N in un'istruzione I di un blocco/funzione S: 
- si cerca definizione di N tra quelle locali al blocco/funzione S  
- se non esiste in S si cerca definizione nel blocco/funzione nel quale è 
stato dichiarato il blocco S; la navigazione può proseguire sino al 
blocco più esterno; 
- se non la si trova si cerca tra i nomi globali; 
- la ricerca termina quando: 
- si trova la prima definizione per il nome  
- la definizione per il nome non viene trovata nella navigazione 
-> Trova la 'i' locale e "nascode" l'altra 'i' globale.

 
**Avvertenza:** una volta trovata l’associazione va verificata la congruenza semantica tra definizione e uso. Una congruenza tra il nome utilizzata nell'istruzione (i = 3;) e la definizione (int i;). -> l'oggetto

### Allocazione e tempo di vita delle variaibli (RDA e stack)
Variabili globali  
- allocate staticamente dal compilatore a inizio esecuzione 
- tempo di vita = tempo di esecuzione del programma; 

Ogni funzione ha un area locale -> se ci sono 10 funzioni dovremmo teoricamente allocare 10 aree locali. Un fenomeno recorsivo è data dal caso quando una funzione invoca se stesso (autoricorsivo) per un numero di volta "infinito" (finito: satura la memoria). Andare ad allocare l'area locale per ogni funzione non è fattibile in modo statico. Allocare tutte le funzioni contemporaneamnte all'inizio dell'esecuzione del programma non è efficiente.
Approccio dinamico: il dato viene allocato e deallocato solo quando serve -> ottimizzazione

### Variabili locali di un blocco/funzione  
 
Linguaggi senza ricorsione  
- Approccio statico: compilatore alloca tutte le variabili locali 
- Approccio dinamico: allocazione delle variabili locali quando il 
blocco entra in esecuzione (tempo di vita =  tempo di esecuzione del blocco/funzione)
Più veloce il primo, ma il secondo usa meno memoria


### Il record di attivazione (RDA:
Area di dati dedicata al singolo sottoprogramma/blocco
- valore di ritorno una funzione (return)
- parametri della funzione funzione
- registro per rerenziare variabili locali: come raggiungere dei dati allocati nello stack
- indirizzo di ritorno: permette il ritorno dal sottoprogramma al main
- variabili locali;
- link statico per lo scope (non trattato oltre): regole del campo di validità

### L'area Stack
RDA allocato/deallocato nello stack in modo automatico. Attivazione dall'alto verso il basso. 
SP = state pointer per muoversi nello stack fissato nell'indirizzo 1000
Estendiamo il linguaggio assembly  

### Estendiamo il linguaggio Assembly
Istruzioni:  
[W:] ADD oper1,oper2     somma in oper2  
[W:] MOV oper1, oper2       copia in oper2 
[W:] BR  I        salta all’istruzione in parola con etichetta I 
[W:] BREQ oper, I:   se oper =0 allora SALTA a istruzione I 
[W:] JTS I      eseguire funzione che inizia all’etichetta I 
[W:] RTS        ritorno da funzione 
[W:] EXIT         termina esecuzione programma 
[W:] READ  oper:   carica valore letto da tastiera in oper 
[W:] WRITE oper:   scrive su video valore in oper 
Modalità di indirizzamento operandi 