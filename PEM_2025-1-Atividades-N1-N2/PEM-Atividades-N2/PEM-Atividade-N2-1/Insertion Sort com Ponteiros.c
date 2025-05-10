/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Insertion Sort com Ponteiros.c   *
* Data - 10/05/2025                                      * 
* Autor: Júlio César                                     *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = *(v + i);
        j = i - 1;
        while (j >= 0 && *(v + j) > chave) {
            *(v + j + 1) = *(v + j);
            j--;
        }
        *(v + j + 1) = chave;
    }
}

void imprimirVetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    insertionSort(vetor, n);
    printf("Vetor ordenado com Insertion Sort:\n");
    imprimirVetor(vetor, n);

    free(vetor);
    return 0;
}
