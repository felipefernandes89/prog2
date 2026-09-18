#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função que verifica se str2 é substring de str1 (case-insensitive)
int ocorrencia(const char *str1, const char *str2) {
    int i, j;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Se a busca for maior que o texto, é impossível conter
    if (len2 > len1) {
        return 0;
    }

    // Percorre a str1 até onde ainda é possível caber a str2
    for (i = 0; i <= len1 - len2; i++) {
        // Para cada posição i em str1, tenta comparar com str2
        for (j = 0; j < len2; j++) {
            // Converte ambos para minúsculas antes de comparar
            if (tolower((unsigned char)str1[i + j]) != tolower((unsigned char)str2[j])) {
                break; // Se encontrou uma letra diferente, interrompe este loop interno
            }
        }

        // Se o loop 'j' chegou ao final de len2, significa que todas as letras bateram!
        if (j == len2) {
            return 1;
        }
    }

    // Se percorreu toda a str1 e não encontrou a sequência
    return 0;
}

int main() {
    char str1[100];
    char str2[100];

    // 1. Recebe a primeira string
    fgets(str1, sizeof(str1), stdin);
    // Remove o caractere de quebra de linha ('\n') inserido pelo fgets
    str1[strcspn(str1, "\n")] = '\0';

    // 2. Recebe a segunda string
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0';

    // 3. Executa a função e imprime o resultado
    int resultado = ocorrencia(str1, str2);
    printf("%d\n", resultado);

    return 0;
}