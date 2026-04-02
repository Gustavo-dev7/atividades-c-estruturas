#include <stdio.h>

int maiorElemento(int *v, int n) {
    int maior = *v;
    for(int i = 1; i < n; i++) {
        if(*(v + i) > maior) {
            maior = *(v + i);
        }
    }
    return maior;
}

int main() {
    int v[] = {3, 7, 2, 9, 5};
    int n = sizeof(v) / sizeof(v[0]);
    printf("Maior elemento: %d\n", maiorElemento(v, n));
    return 0;
}
