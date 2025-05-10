/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Bubble Sort com Ponteiros.c      *
* Data - 10/05/2025                                      * 
* Autor: Júlio César                                     *
*--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (*(v + j) > *(v + j + 1)) {
                temp = *(v + j);
                *(v + j) = *(v + j + 1);
                *(v + j + 1) = temp;
            }
        }
    }
}

void imprimirVetor(int *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(v + i));
    }
    printf("\n");
}

int main() {
    int n, i;
    printf("Digite a quantidade de números: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    printf("Digite os %d números:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    bubbleSort(vetor, n);
    printf("Vetor ordenado com Bubble Sort:\n");
    imprimirVetor(vetor, n);

    free(vetor);
    return 0;
}
