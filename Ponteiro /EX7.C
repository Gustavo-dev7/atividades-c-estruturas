#include <stdio.h>

int somaVetor(int *v, int n) {
    int soma = 0;
    for(int i = 0; i < n; i++) {
        soma += *(v + i);
    }
    return soma;
}

int main() {
    int v[] = {1, 2, 3, 4, 5};
    int n = sizeof(v) / sizeof(v[0]);
    printf("Soma: %d\n", somaVetor(v, n));
    return 0;
}
