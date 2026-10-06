#include <stdio.h>
#include <stdlib.h>

/* =========================================================================
   TAREFA A: Função para rotação da matriz 90° no sentido horário (In-Place)
   ========================================================================= */
void rotacionar_matrix(int **matrix, int N) {
    // Etapa 1: Transposição da matriz (espelhamento pela diagonal principal)
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            // *( *(matrix + i) + j ) é equivalente a matrix[i][j]
            // *( *(matrix + j) + i ) é equivalente a matrix[j][i]
            int temp = *(*(matrix + i) + j);
            *(*(matrix + i) + j) = *(*(matrix + j) + i);
            *(*(matrix + j) + i) = temp;
        }
    }

    // Etapa 2: Inverter os elementos de cada linha (espelhamento horizontal)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N / 2; j++) {
            // *( *(matrix + i) + (N - 1 - j) ) é equivalente a matrix[i][N - 1 - j]
            int temp = *(*(matrix + i) + j);
            *(*(matrix + i) + j) = *(*(matrix + i) + (N - 1 - j));
            *(*(matrix + i) + (N - 1 - j)) = temp;
        }
    }
}

/* =========================================================================
   Funções auxiliares para Alocação e Liberação Segura de Memória
   ========================================================================= */
int** alocar_matriz(int N) {
    int **mat = (int**) malloc(N * sizeof(int*));
    if (mat == NULL) return NULL;

    for (int i = 0; i < N; i++) {
        *(mat + i) = (int*) malloc(N * sizeof(int));
        if (*(mat + i) == NULL) {
            // Libera as linhas já alocadas em caso de erro
            for (int k = 0; k < i; k++) {
                free(*(mat + k));
            }
            free(mat);
            return NULL;
        }
    }
    return mat;
}

void liberar_matriz(int **mat, int N) {
    if (mat != NULL) {
        for (int i = 0; i < N; i++) {
            free(*(mat + i));
        }
        free(mat);
    }
}

/* =========================================================================
   TAREFA B: Programa Principal
   ========================================================================= */
int main() {
    // 1. Abrir arquivo de entrada
    FILE *arq_in = fopen("matriz.txt", "r");
    if (arq_in == NULL) {
        printf("Erro ao abrir o arquivo matriz.txt!\n");
        return -1;
    }

    // 2. Ler a dimensão N
    int N;
    if (fscanf(arq_in, "%d", &N) != 1 || N <= 0) {
        printf("Erro ao ler a dimensão N do arquivo.\n");
        fclose(arq_in);
        return -1;
    }

    // 3. Alocar dinamicamente a matriz N x N
    int **matrix = alocar_matriz(N);
    if (matrix == NULL) {
        printf("Erro de alocação de memória!\n");
        fclose(arq_in);
        return -1;
    }

    // 4. Ler os elementos da matriz do arquivo usando notação de ponteiros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fscanf(arq_in, "%d", (*(matrix + i) + j)) != 1) {
                printf("Erro ao ler os elementos da matriz.\n");
                liberar_matriz(matrix, N);
                fclose(arq_in);
                return -1;
            }
        }
    }
    fclose(arq_in);

    // 5. Rotacionar a matriz 90° sentido horário in-place
    rotacionar_matrix(matrix, N);

    // 6. Abrir o arquivo de saída
    FILE *arq_out = fopen("resultado.txt", "w");
    if (arq_out == NULL) {
        printf("Erro ao criar o arquivo resultado.txt!\n");
        liberar_matriz(matrix, N);
        return -1;
    }

    // 7. Escrever N e a matriz rotacionada no arquivo resultado.txt
    fprintf(arq_out, "%d\n", N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fprintf(arq_out, "%d", *(*(matrix + i) + j));
            if (j < N - 1) {
                fprintf(arq_out, " "); // Espaço entre elementos da mesma linha
            }
        }
        fprintf(arq_out, "\n");
    }
    fclose(arq_out);

    // 8. Liberar a memória alocada
    liberar_matriz(matrix, N);

    printf("Matriz rotacionada com sucesso e salva em resultado.txt!\n");
    return 0;
}
