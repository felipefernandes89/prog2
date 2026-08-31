#include <stdio.h>   // Biblioteca para entrada e saída de dados (printf, fgets)
#include <string.h>  // Biblioteca para manipulação de strings (strstr, strcspn)
#include <ctype.h>   // Biblioteca para conversão de caracteres (tolower)

// FUNÇÃO 1: Converte um texto para minúsculas
// 'str' é um ponteiro que aponta para o texto original
// 'destino' é um ponteiro para onde vamos salvar o texto modificado
void para_minusculo(char *str, char *destino) {
    int i = 0; // Contador para andar letra por letra (índice)

    // Enquanto a letra atual no endereço str[i] não for o fim do texto ('\0')
    while (str[i] != '\0') {
        // Converte a letra atual para minúscula e guarda na mesma posição em 'destino'
        destino[i] = tolower((unsigned char)str[i]);
        i++; // Avança para a próxima letra (próxima gaveta da memória)
    }

    // Coloca o marcador de fim de string no final do texto de destino
    destino[i] = '\0';
}

// FUNÇÃO 2: Exigida pelo exercício
// Recebe os ponteiros para a 1ª string e a 2ª string
int ocorrencia(char str1[], char str2[]) {
    // Vetores de memória (arrays) para guardar as cópias em minúsculo
    char str1_lower[200];
    char str2_lower[200];

    // Converte a primeira string para minúsculas
    para_minusculo(str1, str1_lower);
    
    // Converte a segunda string para minúsculas
    para_minusculo(str2, str2_lower);

    // strstr procura a 2ª string dentro da 1ª
    // Se encontrar, retorna um ponteiro (endereço) diferente de NULL
    if (strstr(str1_lower, str2_lower) != NULL) {
        return 1; // Retorna 1 se encontrou a substring
    } else {
        return 0; // Retorna 0 se NÃO encontrou a substring
    }
}

// FUNÇÃO PRINCIPAL: Ponto de partida do programa
int main() {
    // Declara os dois espaços na memória para guardar os textos digitados
    char str1[200];
    char str2[200];

    // Pede ao usuário para digitar a primeira frase/palavra
    printf("Digite a primeira string (frase/palavra): ");
    fgets(str1, sizeof(str1), stdin); // Lê o texto do teclado e salva em str1
    str1[strcspn(str1, "\n")] = '\0'; // Remove o "Enter" (\n) que o fgets captura

    // Pede ao usuário para digitar a palavra a buscar
    printf("Digite a segunda string (substring): ");
    fgets(str2, sizeof(str2), stdin); // Lê o texto do teclado e salva em str2
    str2[strcspn(str2, "\n")] = '\0'; // Remove o "Enter" (\n) que o fgets captura

    // Chama a função ocorrencia passando os endereços de str1 e str2
    int resultado = ocorrencia(str1, str2);

    // Imprime a saída: 1 (se achar) ou 0 (se não achar)
    printf("%d\n", resultado);

    return 0; // Finaliza o programa com sucesso
}