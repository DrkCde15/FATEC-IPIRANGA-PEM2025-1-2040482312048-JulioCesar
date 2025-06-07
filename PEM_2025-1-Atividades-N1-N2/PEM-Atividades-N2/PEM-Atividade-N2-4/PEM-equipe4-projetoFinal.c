/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Projeto Final PEM.c              *
* Data - 10/06/2025                                      * 
* Autor: Júlio Santana, Alef Vicente e Larissa Costa     *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[100];
    char descricao[200];
    float preco;
    int estoque;
} Produto;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ordenarProdutosPorNome(Produto *produtos, int quantidade) {
    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void listarProdutos(Produto *produtos, int quantidade) {
    ordenarProdutosPorNome(produtos, quantidade);

    printf("\n=== LISTA DE PRODUTOS ===\n");
    for (int i = 0; i < quantidade; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Estoque: %d\n\n", produtos[i].estoque);
    }
}

void inserirProduto(Produto *produtos, int *quantidade) {
    if (*quantidade >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novo;

    printf("Digite o ID do produto: ");
    if (scanf("%d", &novo.id) != 1) {
        printf("ID invalido.\n");
        limparBufferEntrada();
        return;
    }

    // Verificar se ID já existe
    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].id == novo.id) {
            printf("Erro: Ja existe um produto com esse ID!\n");
            return;
        }
    }

    limparBufferEntrada(); // limpa buffer após scanf

    printf("Nome do produto: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Descricao do produto: ");
    fgets(novo.descricao, sizeof(novo.descricao), stdin);
    novo.descricao[strcspn(novo.descricao, "\n")] = '\0';

    printf("Preco unitario (use ponto, ex: 12.90): ");
    if (scanf("%f", &novo.preco) != 1) {
        printf("Entrada invalida. Use ponto em vez de virgula.\n");
        limparBufferEntrada();
        return;
    }

    printf("Quantidade em estoque: ");
    if (scanf("%d", &novo.estoque) != 1) {
        printf("Quantidade invalida.\n");
        limparBufferEntrada();
        return;
    }

    produtos[*quantidade] = novo;
    (*quantidade)++;
    printf("Produto inserido com sucesso!\n");
}

void comprarProduto(Produto *produtos, int *quantidade) {
    int id, quantidadeDesejada;
    printf("Digite o ID do produto que deseja comprar: ");
    if (scanf("%d", &id) != 1) {
        printf("ID invalido.\n");
        limparBufferEntrada();
        return;
    }

    for (int i = 0; i < *quantidade; i++) {
        if (produtos[i].id == id) {
            printf("Produto encontrado: %s (Estoque: %d)\n", produtos[i].nome, produtos[i].estoque);

            if (produtos[i].estoque == 0) {
                printf("Este produto esta sem estoque no momento.\n");
                return;
            }

            printf("Digite a quantidade desejada: ");
            if (scanf("%d", &quantidadeDesejada) != 1) {
                printf("Quantidade invalida.\n");
                limparBufferEntrada();
                return;
            }

            if (quantidadeDesejada <= 0) {
                printf("Quantidade deve ser maior que zero.\n");
                return;
            }

            if (quantidadeDesejada > produtos[i].estoque) {
                printf("Estoque insuficiente.\n");
                return;
            }

            produtos[i].estoque -= quantidadeDesejada;
            float total = quantidadeDesejada * produtos[i].preco;

            printf("Compra realizada! Total: R$ %.2f\n", total);
            printf("Estoque atual do produto '%s': %d unidades.\n", produtos[i].nome, produtos[i].estoque);

            if (produtos[i].estoque == 0) {
                printf("Aviso: O produto '%s' agora esta sem estoque.\n", produtos[i].nome);
            }

            return;
        }
    }

    printf("Produto inexistente.\n");
}

void menu() {
    Produto produtos[MAX_PRODUTOS];
    int quantidade = 0;
    int opcao;

    do {
        printf("\n=== MENU LOJA ELETRONICOS ===\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida.\n");
            limparBufferEntrada();
            continue;
        }

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &quantidade);
                break;
            case 2:
                listarProdutos(produtos, quantidade);
                break;
            case 3:
                comprarProduto(produtos, &quantidade);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);
}

int main() {
    menu();
    return 0;
}
