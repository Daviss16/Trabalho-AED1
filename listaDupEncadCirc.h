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
void liberaLista(Lista* lilic);
int listaVazia(Lista* lilic);
int listaCheia(Lista* lilic);
int tamanhoLista(Lista* lilic);
int insereIniLista(Lista* lilic,void* dado,char tipo);
//int insereMeioLista(Lista* lilic,void* dado,char tipo);
//int insereFinaLista(Lista* lilic,void* dado,char tipo);
int removeIniLista(Lista* lilic);
//int removeMeiLista(Lista* lilic);
//int removeFinaLista(Lista* lilic);
void imprimeLista(Lista* lilic);
int buscaElemento(Lista* lilic,int pos);


//Operações auxiliares
//void iniciaListaVazia(Elem *vazio);


