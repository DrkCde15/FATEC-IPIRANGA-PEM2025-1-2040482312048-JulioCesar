#include <stdio.h>
#include <windows.h>
 
void ExplorerDirectory(const char *caminho, int nivel) {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    char path[1024];
 
    snprintf(path, sizeof(path), "%s\\*", caminho);  // adiciona o curinga para listar todos os arquivos/pastas
 
    hFind = FindFirstFile(path, &findFileData);
 
    if (hFind == INVALID_HANDLE_VALUE) {
        printf("Erro ao abrir o diretório: %s\n", caminho);
        return;
    }
 
    do {
        if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0)
            continue;
 
        for (int i = 0; i < nivel; i++) {
            printf("  ");
        }
 
        printf("|- %s\n", findFileData.cFileName);
 
        // Se for diretório, faz recursão
        if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            char novoCaminho[1024];
            snprintf(novoCaminho, sizeof(novoCaminho), "%s\\%s", caminho, findFileData.cFileName);
            ExplorerDirectory(novoCaminho, nivel + 1);
        }
    } while (FindNextFile(hFind, &findFileData) != 0);
 
    FindClose(hFind);
}
 
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <caminho_do_diretorio>\n", argv[0]);
        return 1;
    }
 
    printf("Estrutura de diretórios para: %s\n", argv[1]);
    ExplorerDirectory(argv[1], 0);
    return 0;
}
