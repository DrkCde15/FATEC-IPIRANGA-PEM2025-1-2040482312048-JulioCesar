/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Variáveis Compostas Homogêneas.c *
* Data - 23/02/2024                                      * 
* Autor: Júlio César                                     *
*--------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATOS 50
#define MAX_NOME 100

// Estrutura para armazenar os dados de um candidato
typedef struct {
    char nome[MAX_NOME];
    float notas_PE[4];  // Notas da Prova Escrita (4 notas)
    float notas_AC[5];  // Notas da Análise Curricular (5 notas)
    float notas_PP[10]; // Notas da Prova Prática (10 notas)
    float notas_EB[3];  // Notas da Entrevista em Banca Avaliadora (3 notas)
    float NF;           // Nota Final
} Candidato;

// Função para calcular a média de notas excluindo a maior e a menor
float calcular_media_excluindo_extremos(float notas[], int num_notas) {
    float maior = notas[0], menor = notas[0], soma = 0.0;
    for (int i = 0; i < num_notas; i++) {
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
        soma += notas[i];
    }
    soma -= (maior + menor); // Exclui maior e menor
    return soma / (num_notas - 2); // Retorna a média
}

// Função para calcular a Nota Final (NF)
float calcular_nota_final(Candidato c) {
    float media_PE = calcular_media_excluindo_extremos(c.notas_PE, 4);
    float media_AC = calcular_media_excluindo_extremos(c.notas_AC, 5);
    float media_PP = calcular_media_excluindo_extremos(c.notas_PP, 10);
    float media_EB = calcular_media_excluindo_extremos(c.notas_EB, 3);
    
    return (media_PE * 0.3) + (media_AC * 0.1) + (media_PP * 0.4) + (media_EB * 0.2);
}

int main() {
    Candidato candidatos[MAX_CANDIDATOS];
    int num_candidatos = 0;

    // Receber os dados dos candidatos
    while (num_candidatos < MAX_CANDIDATOS) {
        printf("\nDigite o nome do candidato %d (ou 'fim' para encerrar): ", num_candidatos + 1);
        fgets(candidatos[num_candidatos].nome, MAX_NOME, stdin);
        candidatos[num_candidatos].nome[strcspn(candidatos[num_candidatos].nome, "\n")] = 0;  // Remove a quebra de linha

        if (strcmp(candidatos[num_candidatos].nome, "fim") == 0) {
            break;
        }

        // Entradas de notas
        printf("Digite as 4 notas da Prova Escrita (PE):\n");
        for (int i = 0; i < 4; i++) {
            printf("n%d: ", i + 1);
            scanf("%f", &candidatos[num_candidatos].notas_PE[i]);
        }
        while (getchar() != '\n'); // Limpa o buffer de entrada

        printf("Digite as 5 notas da Analise Curricular (AC):\n");
        for (int i = 0; i < 5; i++) {
            printf("n%d: ", i + 1);
            scanf("%f", &candidatos[num_candidatos].notas_AC[i]);
        }
        while (getchar() != '\n'); // Limpa o buffer de entrada

        printf("Digite as 10 notas da Prova Pratica (PP):\n");
        for (int i = 0; i < 10; i++) {
            printf("n%d: ", i + 1);
            scanf("%f", &candidatos[num_candidatos].notas_PP[i]);
        }
        while (getchar() != '\n'); // Limpa o buffer de entrada

        printf("Digite as 3 notas da Entrevista em Banca Avaliadora (EB):\n");
        for (int i = 0; i < 3; i++) {
            printf("n%d: ", i + 1);
            scanf("%f", &candidatos[num_candidatos].notas_EB[i]);
        }
        while (getchar() != '\n'); // Limpa o buffer de entrada

        // Calcula a Nota Final do candidato
        candidatos[num_candidatos].NF = calcular_nota_final(candidatos[num_candidatos]);

        num_candidatos++; // Incrementa o número de candidatos
    }

    // Ordenar os candidatos pela Nota Final (NF) de forma decrescente
    for (int i = 0; i < num_candidatos - 1; i++) {
        for (int j = i + 1; j < num_candidatos; j++) {
            if (candidatos[i].NF < candidatos[j].NF) {
                // Trocar candidatos[i] com candidatos[j]
                Candidato temp = candidatos[i];
                candidatos[i] = candidatos[j];
                candidatos[j] = temp;
            }
        }
    }

    // Exibir os 15 melhores candidatos
    printf("\nClassificacao dos 15 melhores candidatos:\n");
    for (int i = 0; i < (num_candidatos < 15 ? num_candidatos : 15); i++) {
        printf("%d. %s - Nota Final: %.2f\n", i + 1, candidatos[i].nome, candidatos[i].NF);
    }

    return 0;
}
