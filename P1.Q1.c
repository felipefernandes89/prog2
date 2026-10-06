#include <stdio.h>
#include <stdlib.h>

int** criaMatrizZero(int lin, int col) {
    int** mat = (int**) malloc(lin * sizeof(int*));
    if (mat == NULL) return NULL;

    for (int i = 0; i < lin; i++) {
        *(mat + i) = (int*) malloc(col * sizeof(int));
        if (*(mat + i) == NULL) {
            for (int k = 0; k < i; k++) {
                free(*(mat + k));
            }
            free(mat);
            return NULL;
        }

        for (int j = 0; j < col; j++) {
            *(*(mat + i) + j) = 0;
        }
    }
    return mat;
}