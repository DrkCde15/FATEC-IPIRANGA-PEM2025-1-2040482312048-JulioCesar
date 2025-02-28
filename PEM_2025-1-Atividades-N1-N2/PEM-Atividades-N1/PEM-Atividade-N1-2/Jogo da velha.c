/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Jogo da Velha                    *
* Data - 28/02/2025                                      * 
* Autor: Júlio César                                     *
*--------------------------------------------------------*/

#include <stdio.h>

char tabuleiro[3][3]; // Tabuleiro 3x3

void inicializarTabuleiro() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro() {
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int verificarVitoria(char jogador) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return 1;
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return 1;
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return 1;
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return 1;
    return 0;
}

int validarEntrada(int valor) {
    if (valor < 1 || valor > 3) {
        printf("Erro: O valor deve ser um número inteiro positivo entre 1 e 3. Tente novamente.\n");
        return 0; // Entrada inválida
    }
    return 1; // Entrada válida
}

int main() {
    int linha, coluna;
    char jogador = 'X';
    int jogadas = 0;

    inicializarTabuleiro();

    while (1) {
        exibirTabuleiro();

        // Solicitar linha
        while (1) {
            printf("Jogador %c, insira a linha (l: 1-3): ", jogador);
            if (scanf("%d", &linha) != 1 || !validarEntrada(linha)) {
                printf("Entrada inválida. Digite um número inteiro entre 1 e 3.\n");
                while (getchar() != '\n'); // Limpar o buffer de entrada
            } else {
                break; // Entrada válida
            }
        }

        // Solicitar coluna
        while (1) {
            printf("Jogador %c, insira a coluna (c: 1-3): ", jogador);
            if (scanf("%d", &coluna) != 1 || !validarEntrada(coluna)) {
                printf("Entrada inválida. Digite um número inteiro entre 1 e 3.\n");
                while (getchar() != '\n'); // Limpar o buffer de entrada
            } else {
                break; // Entrada válida
            }
        }

        // Verificar se a posição está livre
        if (tabuleiro[linha-1][coluna-1] != ' ') {
            printf("Posição já ocupada. Tente novamente.\n");
            continue;
        }

        // Fazer a jogada
        tabuleiro[linha-1][coluna-1] = jogador;
        jogadas++;

        // Verificar vitória
        if (verificarVitoria(jogador)) {
            exibirTabuleiro();
            printf("Jogador %c venceu!\n", jogador);
            break;
        }

        // Verificar empate
        if (jogadas == 9) {
            exibirTabuleiro();
            printf("Empate!\n");
            break;
        }

        // Alternar jogador
        jogador = (jogador == 'X') ? 'O' : 'X';
    }

    return 0;
}
