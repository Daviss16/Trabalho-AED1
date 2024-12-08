#include "listaDupEncadCirc.h"

struct elemento{
    Numeros dadoNum;
    Nomes dadoNome;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

Lista *criaLista(){
    Lista* licir = (Lista*)malloc(sizeof(Lista));
    if(licir == NULL){ 
        printf("Erro ao criar Lista,encerrando programa.\n");
        exit(1);
    }
    *licir = NULL;
    return licir;
}

void liberaLista(Lista *licir){
    if(licir != NULL && (*licir) != NULL){
        Elem *aux,*no = *licir;
        while((*licir) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(licir);
    }
}

int listaVazia(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 1;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 1;
    }
    return 0;
}

int listaCheia(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        printf("A Lista esta cheia.\n");
        return 1;
    }
    free(no);
    return 0;
}

int tamanhoLista(Lista *licir){
    if(licir == NULL || (*licir) == NULL) return 0;
    Elem *no = *licir;
    int count = 0;
    do{
        count ++;
        no = no->prox;
    }while(no != (*licir)); 
    return count;
}

int insereIniLista(Lista *licir, void *dado, char tipo){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    Elem *no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        printf("Erro ao criar no.\n");
        return 0;
    }
    //iniciaListaVazia(no);
    no->dadoNome.id = 0;
    strcpy(no->dadoNome.nome, "\0");
    no->dadoNum.id = 0;
    no->dadoNum.num = 0;
    switch (tipo) {
    case 'i': 
        no->dadoNum = *(Numeros*)dado;
        break;

    case 'n':
        no->dadoNome = *(Nomes*)dado;
        break;
    default:
        printf("Opção de dado não existe, excluindo o no, tente novamente.\n");
        free(no);
        return 0;
    }
    if((*licir)==NULL){
        *licir = no;
        no->prox = no;
        no->ant = no;
    }
    else{
        Elem *aux = *licir;
        while(aux->prox != (*licir)){
            aux = aux->prox;
        }
        aux->prox->ant = no;
        no->ant = aux->prox;
        aux->prox = no;
        no->prox = (*licir);
        *licir = no;
    }
    return 1;
}

int removeIniLista(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    if((*licir) == (*licir)->prox){
        free(*licir);
        *licir = NULL;
        return 1;
    }
    Elem *atual = *licir;
    while(atual->prox != (*licir)){
        atual = atual->prox;
    }
    Elem *no = *licir;
    atual->prox = no->prox;
    no->prox->ant = atual;
    *licir = no->prox;
    free(no);
    return 1;
}

void imprimeLista(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return ;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return ;
    }

    printf("A lista possui %d nos.\n\n",tamanhoLista(licir));
    Elem *no = *licir;
    //int ind = 1;
    do{
        //printf("no numero %d:\n",ind);
        if(no->dadoNum.num != 0)
            printf("Valor %d\n",no->dadoNum.num);
        if(strlen(no->dadoNome.nome) != 0)
            printf("Nome: %s\n",no->dadoNome.nome);
        //ind++;
        no = no->prox;
    }while(no != (*licir));
}

int selectionSortCrescenteNum(Lista *licir, int tam){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    Elem *aux = (*licir),*aux2,*menorNo;
    for(int i = 0; i < (tam - 1);i++){
        aux2 = aux->prox;
        menorNo = aux;
        while(aux2 != (*licir)){
            if(aux2->dadoNum.num < menorNo->dadoNum.num){
                menorNo = aux2;
            }
            aux2 = aux2->prox;
        }
        if(aux != menorNo){
            Numeros temporario = aux->dadoNum;
            aux->dadoNum = menorNo->dadoNum;
            menorNo->dadoNum = temporario;
        }
        aux = aux->prox;
    }
    return 1;
}

int selectionSortDecrescenteNum(Lista *licir){
    if(licir == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*licir) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    Elem *aux = (*licir),*aux2,*maiorNo;
    do{
        aux2 = aux->prox;
        maiorNo = aux;
        while(aux2 != (*licir)){
            if((aux2->dadoNum.num > maiorNo->dadoNum.num)&&(strlen(aux2->dadoNome.nome) != 0)){
                maiorNo = aux2;
            }
            aux2 = aux2->prox;
        }
        if(maiorNo->dadoNum.num != aux->dadoNum.num){
            Numeros temporario = aux->dadoNum;
            aux->dadoNum = maiorNo->dadoNum;
            maiorNo->dadoNum = temporario;
        }
        aux = aux->prox;
        
    }while(aux->prox != (*licir));
    return 1;
}

/*void iniciaListaVazia(Elem *vazio){
    if(vazio == NULL){
        printf("Elemento não criado.\n");
        return ;
    }
    vazio->dadoNome.id = 0;
    strcpy(vazio->dadoNome.nome, "\0");
    vazio->dadoNum.id = 0;
    vazio->dadoNum.num = 0;

    isso é de outra função
    if(strlen(aux->dadoNome.nome) != 0){
            aux = aux->prox;
        }
}*/
