#include "listaDupEncadCirc.h"

struct elemento{
    Numeros dadoNum;
    Nomes dadoNome;
    struct elemento *prox;
    struct elemento *ant;
};

typedef struct elemento Elem;

Lista *criaLista(){
    Lista* lilic = (Lista*)malloc(sizeof(Lista));
    if(lilic == NULL){ 
        printf("Erro ao criar Lista,encerrando programa.\n");
        exit(1);
    }
    *lilic = NULL;
    return lilic;
}

void liberaLista(Lista *lilic){
    if(lilic != NULL && (*lilic) != NULL){
        Elem *aux,*no = *lilic;
        while((*lilic) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(lilic);
    }
}

int listaVazia(Lista *lilic){
    if(lilic == NULL){
        printf("A Lista não existe.\n");
        return 1;
    }
    if((*lilic) == NULL){
        printf("A Lista esta vazia.\n");
        return 1;
    }
    return 0;
}

int listaCheia(Lista *lilic){
    if(lilic == NULL){
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

int tamanhoLista(Lista *lilic){
    if(lilic == NULL || (*lilic) == NULL) return 0;
    Elem *no = *lilic;
    int count = 0;
    do{
        count ++;
        no = no->prox;
    }while(no != (*lilic)); 
    return count;
}

int insereIniLista(Lista *lilic, void *dado, char tipo){
    if(lilic == NULL){
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
    if((*lilic)==NULL){
        *lilic = no;
        no->prox = no;
        no->ant = no;
    }
    else{
        Elem *aux = *lilic;
        while(aux->prox != (*lilic)){
            aux = aux->prox;
        }
        aux->prox->ant = no;
        no->ant = aux->prox;
        aux->prox = no;
        no->prox = (*lilic);
        *lilic = no;
    }
    return 1;
}

int removeIniLista(Lista *lilic){
    if(lilic == NULL){
        printf("A Lista não existe.\n");
        return 0;
    }
    if((*lilic) == NULL){
        printf("A Lista esta vazia.\n");
        return 0;
    }

    if((*lilic) == (*lilic)->prox){
        free(*lilic);
        *lilic = NULL;
        return 1;
    }
    Elem *atual = *lilic;
    while(atual->prox != (*lilic)){
        atual = atual->prox;
    }
    Elem *no = *lilic;
    atual->prox = no->prox;
    no->prox->ant = atual;
    *lilic = no->prox;
    free(no);
    return 1;
}

void imprimeLista(Lista *lilic){
    if(lilic == NULL){
        printf("A Lista não existe.\n");
        return ;
    }
    if((*lilic) == NULL){
        printf("A Lista esta vazia.\n");
        return ;
    }

    printf("A lista possui %d nos.\n\n",tamanhoLista(lilic));
    Elem *no = *lilic;
    int ind = 1;
    while(no->prox != (*lilic)){
        printf("no numero %d:\n",ind);
        if(no->dadoNum.num != 0)
            printf("Valor %d\n",no->dadoNum.num);
        if(strlen(no->dadoNome.nome) != 0)
            printf("Nome: %s\n",no->dadoNome.nome);
        ind++;
        no = no->prox;
    }
}

int buscaElemento(Lista *lilic, int pos){
    
    return 0;
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
}*/
