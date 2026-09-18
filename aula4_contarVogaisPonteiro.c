#include <stdio.h>
#include <ctype.h>

int contarVogaisPonteiro(const char *str) {
    int contador = 0;
    const char *p = str; // 'p' aponta para o início da string

    while (*p != '\0') { // Enquanto o valor apontado por 'p' não for o fim da string
        char c = tolower((unsigned char)*p);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            contador++;
        }
        p++; // Avança o ponteiro para o próximo endereço de memória
    }

    return contador;
}