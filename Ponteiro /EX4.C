#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10, b = 20;
    printf("Antes: a = %d, b = %d\n", a, b);
    troca(&a, &b);
    printf("Depois: a = %d, b = %d\n", a, b);
    return 0;
}
