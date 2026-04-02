#include <stdio.h>

void soma(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}

int main() {
    int a = 10, b = 20, resultado;
    soma(&a, &b, &resultado);
    printf("%d + %d = %d\n", a, b, resultado);
    return 0;
}
