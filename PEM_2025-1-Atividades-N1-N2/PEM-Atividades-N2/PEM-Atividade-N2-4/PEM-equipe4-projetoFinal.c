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
    char nome[50];
    char descricao[100];
    float preco;
    int estoque;
} Produto;

// Prototipos das funcoes
void inserirProduto(Produto *produtos, int *numProdutos);
void listarProdutos(Produto *produtos, int numProdutos);
void ordenarProdutosPorNome(Produto *produtos, int numProdutos);
void simularCompra(Produto *produtos, int numProdutos);
int buscarProdutoPorId(Produto *produtos, int numProdutos, int id);
void limparBufferEntrada();

int main() {
    Produto produtos[MAX_PRODUTOS];
    int numProdutos = 0;
    int opcao;

    do {
        printf("\n=== MENU LOJA ELETRONICOS ===\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Comprar produto\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &numProdutos);
                break;
            case 2:
                listarProdutos(produtos, numProdutos);
                break;
            case 3:
                simularCompra(produtos, numProdutos);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

void inserirProduto(Produto *produtos, int *numProdutos) {
    if (*numProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto *p = &produtos[*numProdutos];

    printf("\nDigite o ID do produto: ");
    scanf("%d", &p->id);
    limparBufferEntrada();

    printf("Nome do produto: ");
    fgets(p->nome, sizeof(p->nome), stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';

    printf("Descricao do produto: ");
    fgets(p->descricao, sizeof(p->descricao), stdin);
    p->descricao[strcspn(p->descricao, "\n")] = '\0';

    printf("Preco unitario: ");
    scanf("%f", &p->preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &p->estoque);
    limparBufferEntrada();

    (*numProdutos)++;
    printf("Produto inserido com sucesso!\n");
}

void listarProdutos(Produto *produtos, int numProdutos) {
    if (numProdutos == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    ordenarProdutosPorNome(produtos, numProdutos);

    printf("\n=== LISTA DE PRODUTOS ===\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Descricao: %s\n", produtos[i].descricao);
        printf("Preco: R$ %.2f\n", produtos[i].preco);
        printf("Estoque: %d\n\n", produtos[i].estoque);
    }
}

void ordenarProdutosPorNome(Produto *produtos, int numProdutos) {
    Produto temp;
    for (int i = 0; i < numProdutos - 1; i++) {
        for (int j = 0; j < numProdutos - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void simularCompra(Produto *produtos, int numProdutos) {
    if (numProdutos == 0) {
        printf("\nNenhum produto disponivel para compra.\n");
        return;
    }

    int id, quantidade;
    printf("\nDigite o ID do produto que deseja comprar: ");
    scanf("%d", &id);

    int indice = buscarProdutoPorId(produtos, numProdutos, id);
    if (indice == -1) {
        printf("Produto inexistente.\n");
        return;
    }

    Produto *p = &produtos[indice];

    printf("Produto encontrado: %s (Estoque: %d)\n", p->nome, p->estoque);
    printf("Digite a quantidade desejada: ");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return;
    }

    if (quantidade > p->estoque) {
        printf("Estoque insuficiente.\n");
    } else {
        float total = p->preco * quantidade;
        p->estoque -= quantidade;
        printf("Compra realizada com sucesso!\n");
        printf("Total da compra: R$ %.2f\n", total);
    }
}

int buscarProdutoPorId(Produto *produtos, int numProdutos, int id) {
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].id == id) {
            return i;
        }
    }
    return -1;
}

// Funcao para limpar buffer de entrada (stdin)
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
