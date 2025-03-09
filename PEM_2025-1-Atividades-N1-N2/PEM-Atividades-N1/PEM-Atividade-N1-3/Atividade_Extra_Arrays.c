/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Atividade - Extra - Arrays       *
* Data - 09/03/2025                                      * 
* Autor: Júlio César                                     *
*--------------------------------------------------------*/

#include <stdio.h>

// Função para mostrar o endereço de cada elemento do array
void mostrar_enderecos(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Endereço do elemento %d: %p\n", array[i], (void*)&array[i]);
    }
}

// Função para encontrar o maior elemento do array
int maior_elemento(int *array, int tamanho) {
    int maior = array[0];
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > maior) {
            maior = array[i];
        }
    }
    return maior;
}

// Função para somar os elementos do array
int soma_elementos(int *array, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += array[i];
    }
    return soma;
}

// Função para modificar os valores do array
void modificar_array(int *array, int tamanho) {
    int novos_valores[] = {10, 20, 6, 16, 30};
    for (int i = 0; i < tamanho; i++) {
        array[i] = novos_valores[i];
    }
}

// Função para mostrar os novos valores do array e a posição da memória
void mostrar_novos_valores(int *array, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Novo valor do elemento %d: %d (Endereço: %p)\n", i, array[i], (void*)&array[i]);
    }
}

int main() {
    int array[] = {5, 10, 3, 8, 15};
    int tamanho = sizeof(array) / sizeof(array[0]);

    // Exibir endereços dos elementos do array
    printf("Endereços dos elementos do array:\n");
    mostrar_enderecos(array, tamanho);

    // Exibir maior elemento do array
    int maior = maior_elemento(array, tamanho);
    printf("\nMaior elemento do array: %d\n", maior);

    // Exibir soma dos elementos do array
    int soma = soma_elementos(array, tamanho);
    printf("\nSoma dos elementos do array: %d\n", soma);

    // Modificar o array para novos valores
    modificar_array(array, tamanho);
    printf("\nArray modificado:\n");
    mostrar_novos_valores(array, tamanho);

    return 0;
}
