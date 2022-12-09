#include <stdio.h>
#include <string.h>

#define NAMELEN 21
#define NANAGR 5

typedef struct {
  char nome[NAMELEN]; 
  char genere[1];
  int eta;
} s_anagr;

s_anagr v_anagr[NANAGR] = { 
    {"Topolino", 'M', 47} ,
    {"Minni", 'F', 37} ,
    {"Pluto", 'M', 17} ,
    {"Clarabella", 'F', 27}
    ,{"Pippo", 'M', 26} 
};

s_anagr v_supporto[NANAGR+1];

int i, j;
char stringM ='M'; char stringF ='F';

s_anagr v_finale[NANAGR+1];

int main()
{
  
  j=0;  
  for ( i = 0; i < NANAGR; i++)
  {
    if( strcmp(v_anagr[i].genere, &stringM ) == 0)
    {
      v_supporto[j]=v_anagr[i];
      j++;
    }

  }

  for ( i = 0; i < j; i++)
  {
    if (v_supporto[i].eta>v_supporto[i+1].eta && i+1!=j)
    {
      v_supporto[0]=v_supporto[i+1];
    }
    
  } 

  v_finale[0]=v_supporto[0];

  // Seleziono la donna più giovane
  //Perché questo e' l'unico che funziona? :(

  j=0;  
  for ( i = 0; i < NANAGR; i++)
  {
    if( strcmp(v_anagr[i].genere, &stringF ) == 0)
    {
        v_supporto[j]=v_anagr[i];
        j++;
    }

  }

  for ( i = 0; i < j; i++)
  {
    if (v_supporto[i].eta>v_supporto[i+1].eta && i+1!=j)
    {
      v_supporto[0]=v_supporto[i+1];
    }
    
  }

  v_finale[1]=v_supporto[0];
  
  // Selezione degli uomini con più di 25 anni.
  j=2;
  for ( i = 0; i < NANAGR; i++)
  {
    if ( strcmp(v_anagr[i].genere, &stringM) == 0  && v_anagr[i].eta>25 && j<NANAGR+1 )
    {
      v_finale[j]=v_anagr[i];
      j++;
    }
    
  }
  
  // Stampo a terminale l'elenco anagrafico finale

  printf("Elenco Anagrafiche:\n");
  for ( i = 0; i < NANAGR; i++)
  {
    printf("Nome: %s\tGenere: %s\t Eta': %d\n", v_finale[i].nome, v_finale[i].genere, v_finale[i].eta);
  }
  

  return 0;
}