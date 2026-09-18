#include <stdio.h>
#include <stdlib.h> // Necessário para usar malloc e free

// Função que recebe um vetor original, seu tamanho e um fator de multiplicação
int *cria_vetor_multiplicado(int *vet, int tam, int fator) {
    // 1. Aloca dinamicamente memória para o novo vetor no Heap
    int *novo_vetor = (int *) malloc(tam * sizeof(int));
    
    // 2. Verifica se a alocação foi bem-sucedida
    if (novo_vetor == NULL) {
        printf("Erro ao alocar memoria!\n");
        return NULL; // Retorna NULL indicando falha
    }
    
    // 3. Preenche o novo vetor multiplicando cada elemento do vetor original
    for (int i = 0; i < tam; i++) {
        novo_vetor[i] = vet[i] * fator;
    }
    
    // 4. Retorna o ponteiro para a área de memória recém-criada
    return novo_vetor;
}

int main(void) {
    int dados[] = {10, 20, 30, 40}; // Vetor estático original
    int tamanho = 4;
    int multiplicador = 3;
    
    // Chama a função e armazena o ponteiro retornado
    int *resultado = cria_vetor_multiplicado(dados, tamanho, multiplicador);
    
    // Se a alocação deu certo, imprime os valores
    if (resultado != NULL) {
        printf("Vetor multiplicado: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", resultado[i]); // Acessa os elementos normalmente com []
        }
        printf("\n");
        
        // LIBERAÇÃO: Sempre liberar a memória alocada dinamicamente
        free(resultado);
    }
    
    return 0;
}