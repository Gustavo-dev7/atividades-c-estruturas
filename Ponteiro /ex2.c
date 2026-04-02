#include <stdio.h>

int main() {
    int n = 5;
    int *p = &n;
    
    printf("Valor original: %d\n", n);
    *p = 20;
    printf("Valor após alteração: %d\n", n);
    
    return 0;
}
