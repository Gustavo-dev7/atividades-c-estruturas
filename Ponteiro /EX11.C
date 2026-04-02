#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, *v, soma = 0;
    float media;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    
    v = (int*)malloc(n * sizeof(int));
    if(v == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }
    
    printf("Digite %d valores:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", v + i);
        soma += *(v + i);
    }
    
    media = (float)soma / n;
    printf("Média: %.2f\n", media);
    
    free(v);
    return 0;
}
