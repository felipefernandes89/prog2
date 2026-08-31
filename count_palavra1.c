#include <stdio.h>
#include <string.h>

int count_palavras(char *str){
    int i=0;

    while (str[i] != '\0'){
        i++;
    } return i;
}

int main(){
    char texto[50];
    printf("digite um texto: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';
    int total = count_palavras(texto);

    // Exibe o resultado da contagem
    printf("O texto digitado tem %d caracteres.\n", total);

    return 0;
}