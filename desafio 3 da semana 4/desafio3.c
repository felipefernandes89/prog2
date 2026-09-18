#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int L, C, M, N;

    // Leitura das dimensoes da plantacao e dos lotes
    scanf("%d %d %d %d", &L, &C, &M, &N);

    // Alocacao dinamica da matriz L x C
    int **matriz = (int **)malloc(L * sizeof(int *));
    for (int i = 0; i < L; i++) {
        matriz[i] = (int *)malloc(C * sizeof(int));
    }

    // Leitura do numero de margaridas em cada vaso
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int max_margaridas = 0;

    // Percorre a matriz de lote em lote (saltando M linhas e N colunas)
    for (int i = 0; i < L; i += M) {
        for (int j = 0; j < C; j += N) {
            
            int soma_lote = 0;

            // Soma todas as margaridas dentro do lote M x N atual
            for (int di = 0; di < M; di++) {
                for (int dj = 0; dj < N; dj++) {
                    soma_lote += matriz[i + di][j + dj];
                }
            }

            // Guarda o maior valor encontrado
            if (soma_lote > max_margaridas) {
                max_margaridas = soma_lote;
            }
        }
    }

    // Imprime apenas o resultado final
    printf("%d\n", max_margaridas);

    // Libera a memoria alocada para a matriz
    for (int i = 0; i < L; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}