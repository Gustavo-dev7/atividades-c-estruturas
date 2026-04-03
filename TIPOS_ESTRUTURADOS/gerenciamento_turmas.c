#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAGAS 3
#define MAX_TURMAS 10

struct aluno {
    int mat;
    char nome[81];
    float notas[3];
    float media;
};
typedef struct aluno Aluno;

struct turma {
    char id;
    int vagas;
    Aluno* alunos[MAX_VAGAS];
};
typedef struct turma Turma;

Turma* turmas[MAX_TURMAS];

Turma* cria_turma(char id) {
    Turma* nova_turma = (Turma*) malloc(sizeof(Turma));
    if (nova_turma == NULL) {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    
    nova_turma->id = id;
    nova_turma->vagas = MAX_VAGAS;
    
    for (int i = 0; i < MAX_VAGAS; i++) {
        nova_turma->alunos[i] = NULL;
    }
    
    return nova_turma;
}

void matricula_aluno(Turma* turma, int mat, char* nome) {
    if (turma->vagas == 0) {
        printf("Sem vagas disponíveis nesta turma!\n");
        return;
    }
    
    int posicao = -1;
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] == NULL) {
            posicao = i;
            break;
        }
    }
    
    if (posicao == -1) {
        printf("Erro interno: vagas inconsistentes!\n");
        return;
    }
    
    Aluno* novo_aluno = (Aluno*) malloc(sizeof(Aluno));
    if (novo_aluno == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    
    novo_aluno->mat = mat;
    strcpy(novo_aluno->nome, nome);
    
    for (int i = 0; i < 3; i++) {
        novo_aluno->notas[i] = 0.0;
    }
    novo_aluno->media = 0.0;
    
    turma->alunos[posicao] = novo_aluno;
    turma->vagas--;
    
    printf("Aluno matriculado com sucesso!\n");
}

void lanca_notas(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Matricula: %d\n", turma->alunos[i]->mat);
            printf("Aluno: %s\n", turma->alunos[i]->nome);
            
            for (int j = 0; j < 3; j++) {
                printf("Digite a nota %d: ", j + 1);
                scanf("%f", &turma->alunos[i]->notas[j]);
            }
            
            turma->alunos[i]->media = 
                (turma->alunos[i]->notas[0] + 
                 turma->alunos[i]->notas[1] + 
                 turma->alunos[i]->notas[2]) / 3.0;
        }
    }
}

void imprime_alunos(Turma* turma) {
    for (int i = 0; i < MAX_VAGAS; i++) {
        if (turma->alunos[i] != NULL) {
            printf("Matricula: %d\n", turma->alunos[i]->mat);
            printf("Nome: %s\n", turma->alunos[i]->nome);
            printf("Media: %.1f\n", turma->alunos[i]->media);
        }
    }
}

void imprime_turmas(Turma** turmas, int n) {
    for (int i = 0; i < n; i++) {
        printf("Turma %c - %d vagas disponíveis\n", turmas[i]->id, turmas[i]->vagas);
    }
}

Turma* procura_turma(Turma** turmas, int n, char id) {
    for (int i = 0; i < n; i++) {
        if (turmas[i]->id == id) {
            return turmas[i];
        }
    }
    return NULL;
}

void liberar_memoria(Turma** turmas, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MAX_VAGAS; j++) {
            if (turmas[i]->alunos[j] != NULL) {
                free(turmas[i]->alunos[j]);
            }
        }
        free(turmas[i]);
    }
}

int main() {
    int opcao, num_turmas = 0;
    char id;
    int matricula;
    char nome[81];
    Turma* turma_atual;
    
    printf("Bem-vindo ao Programa de Gerenciamento de Turmas!\n");
    printf("Este programa gerencia as turmas ofertadas, fornecendo as funcionalidades de matricula, lancamento de notas e listagem de alunos.\n");
    printf("Autor: Ada Lovelace\n");
    printf("Versao: 1.0\n\n");
    
    do {
        printf("\nMENU:\n");
        printf("1 - Criar turma\n");
        printf("2 - Listar turmas\n");
        printf("3 - Matricular aluno\n");
        printf("4 - Lancar notas\n");
        printf("5 - Listar alunos\n");
        printf("6 - Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                if (num_turmas >= MAX_TURMAS) {
                    printf("Limite máximo de turmas atingido!\n");
                    break;
                }
                printf("Criando nova turma...\n");
                printf("Digite um id: ");
                scanf("%c", &id);
                getchar();
                
                turmas[num_turmas] = cria_turma(id);
                if (turmas[num_turmas] != NULL) {
                    printf("Turma %c criada com sucesso!\n", id);
                    num_turmas++;
                }
                break;
                
            case 2:
                printf("Listando turmas...\n");
                imprime_turmas(turmas, num_turmas);
                break;
                
            case 3:
                printf("Matriculando aluno...\n");
                printf("Digite o id da turma: ");
                scanf("%c", &id);
                getchar();
                
                turma_atual = procura_turma(turmas, num_turmas, id);
                if (turma_atual == NULL) {
                    printf("Turma inexistente!\n");
                    break;
                }
                
                printf("Digite a matricula: ");
                scanf("%d", &matricula);
                getchar();
                
                printf("Digite o nome: ");
                fgets(nome, 81, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                
                matricula_aluno(turma_atual, matricula, nome);
                break;
                
            case 4:
                printf("Lancando notas...\n");
                printf("Digite o id da turma: ");
                scanf("%c", &id);
                getchar();
                
                turma_atual = procura_turma(turmas, num_turmas, id);
                if (turma_atual == NULL) {
                    printf("Turma inexistente!\n");
                    break;
                }
                
                lanca_notas(turma_atual);
                break;
                
            case 5:
                printf("Listando alunos...\n");
                printf("Digite o id da turma: ");
                scanf("%c", &id);
                getchar();
                
                turma_atual = procura_turma(turmas, num_turmas, id);
                if (turma_atual == NULL) {
                    printf("Turma inexistente!\n");
                    break;
                }
                
                imprime_alunos(turma_atual);
                break;
                
            case 6:
                printf("Obrigado por usar este programa!\n");
                liberar_memoria(turmas, num_turmas);
                break;
                
            default:
                printf("Opção inválida!\n");
        }
        
    } while (opcao != 6);
    
    return 0;
}
