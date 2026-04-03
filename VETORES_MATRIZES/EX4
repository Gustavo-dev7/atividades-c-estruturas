#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 200

int main() {
    int numPessoas, i;
    char **nomes;
    int *idades;
    
    printf("Digite o número de pessoas: ");
    scanf("%d", &numPessoas);
    getchar();
    
    if (numPessoas > 100) {
        printf("Limite máximo de 100 pessoas.\n");
        return 1;
    }
    
    nomes = (char **) malloc(numPessoas * sizeof(char *));
    if (nomes == NULL) {
        printf("Erro de alocação!\n");
        return 1;
    }
    
    idades = (int *) malloc(numPessoas * sizeof(int));
    if (idades == NULL) {
        printf("Erro de alocação!\n");
        free(nomes);
        return 1;
    }
    
    for (i = 0; i < numPessoas; i++) {
        nomes[i] = (char *) malloc((MAX_NOME + 1) * sizeof(char));
        if (nomes[i] == NULL) {
            printf("Erro de alocação!\n");
            return 1;
        }
        
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome completo: ");
        fgets(nomes[i], MAX_NOME, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
        
        printf("Idade: ");
        scanf("%d", &idades[i]);
        getchar();
    }
    
    printf("\n--- Nomes armazenados ---\n");
    for (i = 0; i < numPessoas; i++) {
        printf("%d. %s (%d anos)\n", i + 1, nomes[i], idades[i]);
    }
    
    for (i = 0; i < numPessoas; i++) {
        free(nomes[i]);
    }
    free(nomes);
    free(idades);
    
    return 0;
}
