#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    float salario;
    int identificador;
    char cargo[50];
} Funcionario;

typedef struct {
    char nome[100];
    char documento[20];
    int idade;
} Pessoa;

void preencherFuncionario(Funcionario *f) {
    printf("Nome: ");
    fgets(f->nome, 100, stdin);
    f->nome[strcspn(f->nome, "\n")] = '\0';
    
    printf("Salario: ");
    scanf("%f", &f->salario);
    getchar();
    
    printf("Identificador: ");
    scanf("%d", &f->identificador);
    getchar();
    
    printf("Cargo: ");
    fgets(f->cargo, 50, stdin);
    f->cargo[strcspn(f->cargo, "\n")] = '\0';
}

void imprimirFuncionario(const Funcionario *f) {
    printf("\n--- Dados do Funcionario ---\n");
    printf("Nome: %s\n", f->nome);
    printf("Salario: R$ %.2f\n", f->salario);
    printf("Identificador: %d\n", f->identificador);
    printf("Cargo: %s\n", f->cargo);
}

void alterarSalario(Funcionario *f, float novoSalario) {
    f->salario = novoSalario;
    printf("Salario alterado para R$ %.2f\n", f->salario);
}

void maiorEMenorSalario(Funcionario vetor[], int tamanho) {
    if (tamanho <= 0) return;
    
    int indiceMaior = 0, indiceMenor = 0;
    
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i].salario > vetor[indiceMaior].salario)
            indiceMaior = i;
        if (vetor[i].salario < vetor[indiceMenor].salario)
            indiceMenor = i;
    }
    
    printf("\n=== Funcionario com MAIOR salario ===\n");
    printf("Cargo: %s\n", vetor[indiceMaior].cargo);
    printf("Salario: R$ %.2f\n", vetor[indiceMaior].salario);
    
    printf("\n=== Funcionario com MENOR salario ===\n");
    printf("Cargo: %s\n", vetor[indiceMenor].cargo);
    printf("Salario: R$ %.2f\n", vetor[indiceMenor].salario);
}

void preencherPessoa(Pessoa *p) {
    printf("Nome: ");
    fgets(p->nome, 100, stdin);
    p->nome[strcspn(p->nome, "\n")] = '\0';
    
    printf("Numero do documento: ");
    fgets(p->documento, 20, stdin);
    p->documento[strcspn(p->documento, "\n")] = '\0';
    
    printf("Idade: ");
    scanf("%d", &p->idade);
    getchar();
}

void imprimirPessoa(const Pessoa *p) {
    printf("\n--- Dados da Pessoa ---\n");
    printf("Nome: %s\n", p->nome);
    printf("Documento: %s\n", p->documento);
    printf("Idade: %d anos\n", p->idade);
}

void atualizarIdade(Pessoa *p, int novaIdade) {
    p->idade = novaIdade;
    printf("Idade atualizada para %d anos\n", p->idade);
}

void maisVelhaEMaisNova(Pessoa vetor[], int tamanho) {
    if (tamanho <= 0) return;
    
    int indiceVelha = 0, indiceNova = 0;
    
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i].idade > vetor[indiceVelha].idade)
            indiceVelha = i;
        if (vetor[i].idade < vetor[indiceNova].idade)
            indiceNova = i;
    }
    
    printf("\n=== Pessoa mais VELHA ===\n");
    printf("Nome: %s\n", vetor[indiceVelha].nome);
    printf("Idade: %d anos\n", vetor[indiceVelha].idade);
    
    printf("\n=== Pessoa mais NOVA ===\n");
    printf("Nome: %s\n", vetor[indiceNova].nome);
    printf("Idade: %d anos\n", vetor[indiceNova].idade);
}

int main() {
    int n_func, n_pessoas;
    
    printf("=== TESTE FUNCIONARIO ===\n");
    printf("Quantos funcionarios deseja cadastrar? ");
    scanf("%d", &n_func);
    getchar();
    
    Funcionario funcionarios[n_func];
    
    for (int i = 0; i < n_func; i++) {
        printf("\n--- Cadastro do Funcionario %d ---\n", i + 1);
        preencherFuncionario(&funcionarios[i]);
    }
    
    printf("\n--- Listagem de Funcionarios ---");
    for (int i = 0; i < n_func; i++) {
        imprimirFuncionario(&funcionarios[i]);
    }
    
    if (n_func > 0) {
        printf("\n--- Teste de alteracao de salario ---\n");
        printf("Digite o novo salario para %s: ", funcionarios[0].nome);
        float novoSal;
        scanf("%f", &novoSal);
        alterarSalario(&funcionarios[0], novoSal);
    }
    
    maiorEMenorSalario(funcionarios, n_func);
    
    printf("\n\n=== TESTE PESSOA ===\n");
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n_pessoas);
    getchar();
    
    Pessoa pessoas[n_pessoas];
    
    for (int i = 0; i < n_pessoas; i++) {
        printf("\n--- Cadastro da Pessoa %d ---\n", i + 1);
        preencherPessoa(&pessoas[i]);
    }
    
    printf("\n--- Listagem de Pessoas ---");
    for (int i = 0; i < n_pessoas; i++) {
        imprimirPessoa(&pessoas[i]);
    }
    
    if (n_pessoas > 0) {
        printf("\n--- Teste de atualizacao de idade ---\n");
        printf("Digite a nova idade para %s: ", pessoas[0].nome);
        int novaIdade;
        scanf("%d", &novaIdade);
        atualizarIdade(&pessoas[0], novaIdade);
    }
    
    maisVelhaEMaisNova(pessoas, n_pessoas);
    
    return 0;
}
