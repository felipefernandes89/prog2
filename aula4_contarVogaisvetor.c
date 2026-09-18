#include <stdio.h>
#include <ctype.h>

/*
Exercício 2
• Faça uma função que receba uma string
como parâmetro e retorne o número de
vogais desta.
– Apresente duas versões da função: uma usando
vetores e outra utilizando ponteiros.
*/

int contarVogaisVetor(const char str[]) {
    int contador = 0;
    int i; // Declaração da variável fora do for para compatibilidade total

    for (i = 0; str[i] != '\0'; i++) {
        char c = tolower(str[i]); // Cast de segurança para o tolower
        
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
    }

    return contador;
}

int main() {
    char frase[100];

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    int totalVogais = contarVogaisVetor(frase);
    printf("Total de vogais na frase: %d\n", totalVogais);

    return 0;
}