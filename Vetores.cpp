#include<stdio.h>
#include<stdlib.h>

#define MAX_VETOR 50

void InserirOrdenado(int vetor[], int tam, int x){
    int pos = tam;
    while (pos > 0 && x < vetor[pos-1]) {
        vetor[pos] = vetor[pos - 1];
        pos -= 1;
    }
    vetor[pos] = x;
}

void ImprimirVetor(int vetor[], int tamanho){
    if (tamanho = 0){
        printf("vetor está vazio\n");
        return;
    }

    printf("%d elementos", tamanho);
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










int main(){

    return 0;
}
