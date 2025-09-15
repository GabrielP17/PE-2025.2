#include<stdio.h>
#include<stdlib.h>

#define MAX_VETOR 50

void InserirOrdenado(int vetor[], int tam, int x) {
    int pos = tam;
    while (pos > 0 && x < vetor[pos - 1]) {
        vetor[pos] = vetor[pos - 1];
        pos -= 1;
    }
    vetor[pos] = x;
}

void ImprimirVetor(int vetor[], int tamanho){
    if (tamanho == 0){
        printf("vetor está vazio\n");
        return;
    }

    printf("%d elementos: [", tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("%d", vetor[i]);
        if (i < tamanho-1 ){
            printf(", ");
        }
    }
    printf("]\n");
}

int BuscaBinaria(int vetor[], int tamanho, int valor){
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) /2;

        if (vetor[meio] == valor){
            return meio;
        } else if(vetor[meio] < valor){
            inicio = meio + 1;
        }else {
            fim = meio - 1;
        }
    }
    return -1;
}

void removerElemento(int vetor[], int *tamanho, int valor) {
    int posicao = BuscaBinaria(vetor, *tamanho, valor);
    
    if (posicao == -1) {
        printf("elemento não encontrado");
        return;
    }
    
    for (int i = posicao; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("elemento removido\n");
}



int main(){
    int vetor[MAX_VETOR];
    int tamanho = 0;
    int opcao;

    do {
        printf("digite o tamanho do vetor (3-50): ");
        scanf("%d", &tamanho);

        if (tamanho < 3 || tamanho > MAX_VETOR){
            printf("tamanho invalido, tente novamente\n");
        }
    }while (tamanho < 3 || tamanho > MAX_VETOR);
    
    printf("\npreencha o vetor com %d valores:\n", tamanho);
    for(int i = 0; i < tamanho; i++){
        printf("digite o valor %d: ", i + 1);
        scanf("%d", &vetor[i]);

        if(i > 0){
            InserirOrdenado(vetor, i, vetor[i]);
        }
    }

    do {
        printf("\n  -MENU-\n");
        printf("1- imprimir vetor\n");
        printf("2- consultar elemento (busca binaria)\n");
        printf("3- remover elemento\n");
        printf("4- inserir elemento\n");
        printf("0- sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);


        if (opcao == 1){
            ImprimirVetor(vetor, tamanho);
        }
        else if(opcao == 2){
            int valor, posicao;
            printf("digite o valor para consulta: ");
            scanf("%d", &valor);
            posicao = BuscaBinaria(vetor, tamanho, valor);
            if (posicao == -1) {
                printf("elemento %d nao encontrado\n", valor);
            } else {
                printf("elemento %d encontrado na posicao %d\n", valor, posicao);
            }
        }
        else if (opcao == 3) {
            int valor;
            printf("digite o valor a ser removido: ");
            scanf("%d", &valor);
            removerElemento(vetor, &tamanho, valor);
        }
        else if (opcao == 4) {
            int valor;
            if (tamanho >= MAX_VETOR) {
                printf("erro: vetor esta cheio\n");
            } else {
                printf("digite o valor a ser inserido: ");
                scanf("%d", &valor);
                InserirOrdenado(vetor, tamanho, valor);
                tamanho++; 
                printf("valor %d inserido\n", valor);
            }
        }
        else if (opcao == 0) {
            printf("saindo\n");
        }
        else {
            printf("opcao invalida\n");
        }

    }while (opcao != 0);
    
    return 0;
}
