#include <stdio.h>
#include <stdlib.h>

int *cria_vetor(int *vet_original, int fator) { // Recebe um ponteiro/vetor
    int *novo = (int *) malloc(2 * sizeof(int)); // Aloca memória
    novo[0] = vet_original[0] * fator ;
    novo[1] = vet_original[1] * fator;
    
    return novo; // Retorna o ponteiro/endereço do novo vetor
}

int main(void) {
    int dados[2] = {5, 10};
    
    // Passa 'dados' (endereço) e recebe 'resultado' (endereço)
    int *resultado = cria_vetor(dados,2); 
    
    printf("Valores: %d, %d\n", resultado[0], resultado[1]); // Saída: 10, 20
    
    free(resultado);
    return 0;
}