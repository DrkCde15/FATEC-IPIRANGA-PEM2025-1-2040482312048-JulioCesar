/*-------------------------------------------------------*
 *                      FATEC Ipiranga                    *
 * Disciplina: Programaçao Estruturada e Modular          *
 *          Prof. Veríssimo                               *
 *--------------------------------------------------------*
 * Objetivo do Programa: Recursividade                    *
 * Data - 23/03/2025                                      *
 * Autor: Júlio César      	                          *
 *--------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

void ExplorerDirectory(const char *caminho, int nivel)
{
    struct dirent *entrada;
    DIR *Directory = opendir(caminho);

    if (Directory == NULL)
    {
        printf("Erro ao abrir diretorio: %s\n", caminho);
        return;
    }

    while ((entrada = readdir(Directory)) != NULL)
    {

        if (strcmp(entrada->d_name, ".") == 0 || strcmp(entrada->d_name, "..") == 0)
            continue;

        int i = 0;
        for (i = 0; i < nivel; i++)
        {
            printf("  ");
        }
        printf("|- %s\n", entrada->d_name);

        char Caminho_Novo[1024];
        snprintf(Caminho_Novo, sizeof(Caminho_Novo), "%s/%s", caminho, entrada->d_name);

        DIR *subdiretorio = opendir(Caminho_Novo);
        if (subdiretorio != NULL)
        {
            closedir(subdiretorio);
            ExplorerDirectory(Caminho_Novo, nivel + 1);
        }
    }
    closedir(Directory);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Use: %s <caminho_do_diretorio_para_consulta>\n", argv[0]);
        return 1;
    }

    printf("Estrutura de diretorios para: %s\n", argv[1]);
    ExplorerDirectory(argv[1], 0);
    return 0;
}
