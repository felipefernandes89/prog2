#include <stdio.h>
#include <string.h>

// Função que recebe o ponteiro da string e conta as letras
int meu_strlen(char *str) {
    int contador = 0;

    // Enquanto o caractere apontado por str[contador] não for o nulo ('\0')
    while (str[contador] != '\0') {
        contador++; // Incrementa a contagem e vai para a próxima posição de memória
    }

    return contador; // Retorna a quantidade total de letras
}

int main() {
    char texto[200]; // Espaço reservado na memória para o texto do usuário

    // Pede ao usuário para digitar uma palavra ou frase
    printf("Digite um texto: ");
    fgets(texto, sizeof(texto), stdin); // Lê o texto do teclado

    // Remove a tecla "Enter" (\n) que o fgets captura no final
    texto[strcspn(texto, "\n")] = '\0';

    // Chama a função passando o ponteiro do texto lido
    int total = meu_strlen(texto);

    // Exibe o resultado da contagem
    printf("O texto digitado tem %d caracteres.\n", total);

    return 0;
}