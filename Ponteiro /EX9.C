#include <stdio.h>

int main() {
    int x = 10;
    int *p;
    int **pp;
    
    p = &x;
    pp = &p;
    
    printf("Valor de x: %d\n", x);
    printf("Valor apontado por p (*p): %d\n", *p);
    printf("Valor apontado por pp (**pp): %d\n", **pp);
    
    return 0;
}
