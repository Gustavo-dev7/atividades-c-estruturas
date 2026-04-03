#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int **matriz;
    
    // Aloca matriz 5x5
    matriz = (int **) malloc(5 * sizeof(int *));
    for (i = 0; i < 5; i++) {
        matriz[i] = (int *) malloc(5 * sizeof(int));
    }
    
    // Preenche com os índices (i*5 + j)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            matriz[i][j] = i * 5 + j;
        }
    }
    
    // Imprime a matriz
    printf("Matriz 5x5:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Libera memória
    for (i = 0; i < 5; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
    return 0;
}
