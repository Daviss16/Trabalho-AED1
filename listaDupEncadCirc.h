//selection sort
//merge sort


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct elemento *Lista;

typedef struct numeros{
    int id;
    int num;
} Numeros;

typedef struct nomes{
    int id;
    char nome[100];
} Nomes;

//Operações com a Lista
Lista* criaLista();
void liberaLista(Lista* licir);
int listaVazia(Lista* licir);
int listaCheia(Lista* licir);
int tamanhoLista(Lista* licir);
int insereIniLista(Lista* licir,void* dado,char tipo);
int removeIniLista(Lista* licir);
void imprimeLista(Lista* licir);

//operações de ordenação
int selectionSortCrescenteNum(Lista* licir,int tam);
int selectionSortDecrescenteNum(Lista* licir);



