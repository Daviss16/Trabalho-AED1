#include "listaDupEncadCirc.h"

int main(){
    Lista* point = criaLista();
    Numeros num[10] = {
        {1,45},{2,65},{3,35},{4,47},{5,55},{6,665},{7,75},{8,85},{9,95},{10,615}
    };
    Nomes name[10] = {
        {1,"rango"},{2,"sapo"},{3,"macaco"},{4,"rato"},{5,"elefante"},
        {6,"tigre"},{7,"leao"},{8,"ogro"},{9,"passaro"},{10,"orca"}
    };

    for(int i = 0;i<10;i++){
        if(!insereIniLista(point,&num[i],'i')){
            printf("Erro ao colocar na Lista.\n");
        }
    }

    for(int i = 0;i<10;i++){
        if(!insereIniLista(point,&name[i],'n')){
            printf("Erro ao colocar na Lista.\n");
        }
    }

    imprimeLista(point);

    removeIniLista(point);
    removeIniLista(point);

    printf("-------------------------------\n");
    imprimeLista(point);

    liberaLista(point);
    return 0;
}