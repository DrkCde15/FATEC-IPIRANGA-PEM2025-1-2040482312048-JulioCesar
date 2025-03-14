/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Jogo da Velha                    *
* Data - 14/03/2025                                      * 
* Autor: Júlio César                                     *
*--------------------------------------------------------*/


#include <stdio.h>
#include <string.h>

#define RUAS 3
#define GONDOLAS 10
#define MAX_PRODUTO 10

// Definição da estrutura para armazenar as informações do produto
typedef struct {
    char codigo[6];  // Código do produto (ex: S123)
    int quantidade;  // Quantidade de itens estocados
} Produto;

// Função para inicializar o estoque
void inicializar_estoque(Produto (*estoque)[GONDOLAS]) {
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            strcpy(estoque[i][j].codigo, "");
            estoque[i][j].quantidade = 0;
        }
    }
}

// Função para estocar um produto no armazém
void estocar_produto(Produto (*estoque)[GONDOLAS], int rua, int gondola, const char *codigo, int quantidade) {
    if (estoque[rua][gondola].quantidade == 0) {
        strcpy(estoque[rua][gondola].codigo, codigo);
        estoque[rua][gondola].quantidade = quantidade;
        printf("Produto %s estocado na Rua %c, Gôndola %d.\n", codigo, 'A' + rua, gondola + 1);
    } else {
        printf("Gôndola %d da Rua %c já está ocupada pelo produto %s.\n", gondola + 1, 'A' + rua, estoque[rua][gondola].codigo);
    }
}

// Função para retirar um produto do estoque
void retirar_produto(Produto (*estoque)[GONDOLAS], const char *codigo, int quantidade) {
    for (int i = 0; i < RUAS; i++) {
        for (int j = 0; j < GONDOLAS; j++) {
            if (strcmp(estoque[i][j].codigo, codigo) == 0) {
                if (estoque[i][j].quantidade >= quantidade) {
                    estoque[i][j].quantidade -= quantidade;
                    printf("Retirada de %d unidades do produto %s da Rua %c, Gôndola %d.\n", quantidade, codigo, 'A' + i, j + 1);
                    if (estoque[i][j].quantidade == 0) {
                        printf("Gôndola %d da Rua %c está agora vazia.\n", j + 1, 'A' + i);
                    }
                } else {
                    printf("Quantidade insuficiente de %s no estoque.\n", codigo);
                }
                return;
            }
        }
    }
    printf("Produto %s não encontrado no estoque.\n", codigo);
}

int main() {
    Produto estoque[RUAS][GONDOLAS];
    inicializar_estoque(estoque);

    // Estocagem de produtos
    estocar_produto(estoque, 0, 9, "S123", 50);  // Estoca na Rua A, Gôndola 10
    estocar_produto(estoque, 1, 3, "B456", 30);  // Estoca na Rua B, Gôndola 4

    // Retirada de produtos
    retirar_produto(estoque, "S123", 10);  // Retira 10 unidades de S123

    return 0;
}
