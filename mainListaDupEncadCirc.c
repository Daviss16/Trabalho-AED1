#include "listaDupEncadCirc.h"

int main() {
    Lista* NumPoint = criaLista();
    Lista* nomesPoint = criaLista(); // Lista separada para nomesPoint, já comentada no código
    int quantidadeElem,quantidadeNomes;
    char opcao;

    printf("Deseja printar as saidas se o numero de entrada for menor que 100 S/N?\n");
    scanf("%c",&opcao);
    
    printf("Digite a quantidade de Numeros de entrada\n");
    scanf("%d",&quantidadeElem);
    insereAleatoriosLista(NumPoint,quantidadeElem);

    clock_t inicio, fim;
    double tempo_execucao;

    printf("-------------Teste Selection Sort--------------\n");
    
    if(quantidadeElem < 101 && opcao == 's'){
        printf("\nMostrando Lista Ordenada Aleatoriamente\n");
        imprimeLista(NumPoint);
    }
    
    printf("\n-> Selection sort com entrada Aleatoria Ordenando Crescente com N = %d:\n",quantidadeElem);

    // Medir tempo de execução para Selection Sort crescente (números) com entrada aleatoria
    inicio = clock();
    int tamanho = tamanhoLista(NumPoint);
    selectionSortCrescenteNum(NumPoint, tamanho);
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Aleatoria.\n");

    if(quantidadeElem < 101 && opcao == 's'){
        printf("\nMostrando Lista Ordenada Crescente Selection Sort\n");
        imprimeLista(NumPoint);
    }

    printf("\n-> Selection sort com entrada Ordenada Crescente Ordenando Crescente com N = %d:\n",quantidadeElem);

    // Medir tempo de execução para Selection Sort crescente (números) com entrada ordenada crescente
    inicio = clock();
    tamanho = tamanhoLista(NumPoint);
    selectionSortCrescenteNum(NumPoint, tamanho);
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Ordenada Crescente.\n");

    printf("\n-> Selection sort com entrada Crescente Ordenando Decrescente com N = %d:\n",quantidadeElem);

    // Medir tempo de execução para Selection Sort decrescente (números) com entrada ordenada crescente
    inicio = clock();
    tamanho = tamanhoLista(NumPoint);
    selectionSortDecrescenteNum(NumPoint);
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Decrescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Ordenada Crescente.\n");

    if(quantidadeElem < 101 && opcao == 's'){
        printf("\nMostrando Lista Ordenada Decrescente Selection Sort\n");
        imprimeLista(NumPoint);
    }

    esvaziaLista(NumPoint);

    
    printf("\n-------------Teste Merge Sort--------------\n");

    insereAleatoriosLista(NumPoint,quantidadeElem);
    
    if(quantidadeElem < 101 && opcao == 's'){
        printf("\nMostrando Lista Ordenada Aleatoriamente\n");
        imprimeLista(NumPoint);
    }

    printf("\n-> Merge sort com entrada Aleatoria Ordenando Crescente com N = %d:\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort crescente (números) Com dados Aleatorios
    inicio = clock();
    mergeSortNum(NumPoint, 'c');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Aleatorios.\n");
    
    if(quantidadeElem < 101 && opcao == 's'){
        printf("\nMostrando Lista Ordenada Crescente Merge Sort\n");
        imprimeLista(NumPoint);
    }

    printf("\n-> Merge sort com entrada Ordenada Crescente Ordenando Crescente com N = %d:\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort crescente (números) com dados Ordenados Crescente
    inicio = clock();
    mergeSortNum(NumPoint, 'c');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Crescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Ordenados Crescente.\n");

    printf("\n-> Merge sort com entrada Ordenada Crescente Ordenando Decrescente com N = %d:\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort Decrescente (números) com dados Ordenados Crescente
    inicio = clock();
    mergeSortNum(NumPoint, 'd');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Decrescente: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Ordenados Crescente.\n");

    if(quantidadeElem < 101 && opcao == 's'){
        printf("\nMostrando Lista Ordenada Decrescente Merge Sort\n");
        imprimeLista(NumPoint);
    }

    esvaziaLista(NumPoint);
    
    printf("\n\nDigite um N menor que 1000000\n");
    scanf("%d",&quantidadeNomes);
    lerNomesArquivo(nomesPoint,quantidadeNomes);

    
    printf("\n-------------Teste Selection Sort Com Nomes--------------\n");

    if(quantidadeNomes < 101 && opcao == 's'){
        printf("\nMostrando Lista com Nomes Ordenada Aleatoriamente.\n");
        imprimeLista(nomesPoint);
    }

    printf("\n-> Selection sort com entrada N = %d Nomes Ordenando Crescente\n",quantidadeNomes);
    
    // Medir tempo de execução para Selection Sort crescente (nomesPoint) com entrada aleatoria
    inicio = clock();
    selectionSortCrescenteString(nomesPoint);
    fim = clock();
    
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Crescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Aleatoria.\n");

    if(quantidadeNomes < 101 && opcao == 's'){
        printf("\nMostrando Lista com Nomes Ordenada Crescente Selection Sort.\n");
        imprimeLista(nomesPoint);
    }

    esvaziaLista(nomesPoint);
    lerNomesArquivo(nomesPoint,quantidadeNomes);

    printf("\n-> Selection sort com entrada N = %d Nomes Ordenando Decrescente\n",quantidadeNomes);

    // Medir tempo de execução para Selection Sort crescente (nomesPoint) com entrada aleatoria
    inicio = clock();
    selectionSortDecrescenteString(nomesPoint);
    fim = clock();
    
    
    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Selection Sort Decrescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada Aleatoria.\n");

    if(quantidadeNomes < 101 && opcao == 's'){
        printf("\nMostrando Lista com Nomes Ordenada Decrescente Selection Sort.\n");
        imprimeLista(nomesPoint);
    }
    esvaziaLista(nomesPoint);


    printf("\n-------------Teste Merge Sort Com Nomes--------------\n");

    lerNomesArquivo(nomesPoint,quantidadeNomes);
    
    if(quantidadeNomes < 101 && opcao == 's'){
        printf("\nMostrando Lista com Nomes Ordenada Aleatoriamente.\n");
        imprimeLista(nomesPoint);
    }

    printf("\n-> Merge sort com N = %d Nomes e Ordenando Crescente\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort crescente (Nomes) com entrada de dados Aleatorias
    inicio = clock();
    mergeSortString(nomesPoint, 'c');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Crescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Aleatorios.\n");

    if(quantidadeNomes < 101 && opcao == 's'){
        printf("\nMostrando Lista com Nomes Ordenada Crescente Merge Sort.\n");
        imprimeLista(nomesPoint);
    }

    esvaziaLista(nomesPoint);
    lerNomesArquivo(nomesPoint,quantidadeNomes);
    printf("\n-> Merge sort com N = %d Nomes Ordenando Decrescente\n",quantidadeElem);
    
    // Medir tempo de execução para Merge Sort Decrescente (Nomes) com entrada de dados Aleatorias
    inicio = clock();
    mergeSortString(nomesPoint, 'd');
    fim = clock();

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao do Merge Sort Decrescente com Nomes: %.6f segundos\n", tempo_execucao);
    printf("Com entrada de dados Aleatoria.\n");
    
    if(quantidadeNomes < 101 && opcao == 's'){
        printf("\nMostrando Lista com Nomes Ordenada Decrescente Merge Sort.\n");
        imprimeLista(nomesPoint);
    }
   
    liberaLista(NumPoint);
    liberaLista(nomesPoint);

    return 0;
}
