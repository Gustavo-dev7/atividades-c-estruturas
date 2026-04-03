# atividades-c-estruturas

---

## Bloco 1 – Ponteiros e Aritmética de Ponteiros

### Exercício 1
**O básico:** ponteiro apontando para uma variável.  
**Como pensei:** Precisava mostrar que um ponteiro guarda endereços. Então criei `x` e `p`. Fiz `p = &x` – isso significa: "p, agora você aponta para o endereço da x". Depois imprimi tudo: o valor de x, o endereço dela, o que p contém (que é o endereço) e o valor que está nesse endereço (o conteúdo de x). Simples, mas essencial.

### Exercício 2
**Mudando o valor de uma variável sem tocar nela diretamente.**  
Com `p` apontando para `n`, usei `*p = 20`. Aqui a mágica: `*p` é como se fosse a própria `n`. Assim, alterei `n` de forma indireta. É como ter um controle remoto que mexe na variável à distância.

### Exercício 3
**Somando dois números com ponteiros.**  
A função `soma` recebe três ponteiros. Dentro dela, desreferencio os dois primeiros (`*a`, `*b`) para pegar os valores, somo e guardo no endereço apontado por `resultado`. Na `main`, passo os endereços das variáveis com `&`.

### Exercício 4
**Troca de valores (swap).**  
Usei uma variável temporária `temp` para guardar o valor de `*a`, depois coloquei `*b` em `*a` e o valor temporário em `*b`. Assim os valores são trocados permanentemente.

### Exercício 5
**Maior de dois números.**  
Comparei `*a` e `*b` usando o operador ternário e retornei o maior valor.

### Exercício 6
**Percorrendo vetor com ponteiro.**  
Fiz `p = v` (em C, o nome do array decai para um ponteiro para o primeiro elemento). Usei `*(p + i)` para acessar cada elemento, demonstrando aritmética de ponteiros.

### Exercício 7
**Soma de vetor com ponteiros.**  
Percorri o vetor usando `*(v + i)` e acumulei os valores na variável `soma`.

### Exercício 8
**Maior elemento do vetor.**  
Inicializei `maior` com o primeiro elemento (`*v`) e, durante a varredura, atualizei sempre que encontrava um valor maior.

### Exercício 9
**Ponteiro para ponteiro.**  
Criei `p` apontando para `x`, e `pp` apontando para `p`. Acessei o valor final de três formas diferentes: `x`, `*p` e `**pp`. Isso mostra que múltiplos níveis de indireção são possíveis.

### Exercício 10
**Inverter vetor.**  
Usei dois ponteiros: `inicio` (apontando para o primeiro elemento) e `fim` (apontando para o último). Troquei os valores enquanto `inicio < fim` e movi os ponteiros um para frente e outro para trás.

### Exercício 11 (Desafio)
**Alocação dinâmica com malloc.**  
Perguntei ao usuário o tamanho do vetor, aloquei com `malloc`, verifiquei se a alocação foi bem-sucedida, li os valores, calculei a média e liberei a memória com `free`.

---

## Bloco 2 – Alocação Dinâmica (Apenas 1 questão – slide 31)

### Matriz 5x5 com índices
**Como pensei:** Uma matriz dinâmica em C é um ponteiro para ponteiro (`int**`). Primeiro aloco um vetor de ponteiros (as linhas), depois aloco cada linha individualmente. Preenchi cada posição com `i * 5 + j` para que o número reflita sua posição (ex: linha 0, coluna 0 → 0; linha 2, coluna 3 → 13). No final, liberei cada linha e depois a matriz principal.

---

## Bloco 3 – Vetores e Matrizes (4 questões do INFO-2_1_1.pdf)

### Exercício 1 – Vetor invertido
Perguntei o tamanho `n`, aloquei o vetor com `malloc`, li os valores do usuário e imprimi do último índice (`n-1`) até o primeiro (`0`).

### Exercício 2 – Matriz e transposta
Aloquei duas matrizes dinâmicas (original e transposta). Para a transposta, fiz `transposta[j][i] = matriz[i][j]`. Depois imprimi ambas e liberei a memória.

### Exercício 3 – Matriz quadrada aleatória
Aloquei uma matriz `n x n`, usei `srand(time(NULL))` para gerar números aleatórios diferentes a cada execução, e preenchi com `rand() % 100 + 1` (números entre 1 e 100).

### Exercício 4 – Nomes e idades
Aloquei um vetor de ponteiros para `char` (`char** nomes`) e um vetor de `int` (`int* idades`). Para cada pessoa, aloquei espaço para o nome com `malloc`. Usei `fgets` para ler nomes com espaços e `scanf` para as idades. No final, liberei cada nome e depois os vetores principais.

---

## Bloco 4 – Tipos Estruturados

### Parte 1 – Funcionário e Pessoa (INFO-1_2.pdf)

**Funcionario:**
- `preencherFuncionario`: recebe ponteiro e preenche nome, salário, identificador e cargo.
- `imprimirFuncionario`: exibe todos os dados.
- `alterarSalario`: modifica o salário via ponteiro.
- `maiorEMenorSalario`: percorre o vetor e encontra o maior e menor salário.

**Pessoa:**
- `preencherPessoa`: preenche nome, documento e idade.
- `imprimirPessoa`: exibe os dados.
- `atualizarIdade`: modifica a idade.
- `maisVelhaEMaisNova`: percorre o vetor e encontra a pessoa mais velha e a mais nova.

### Parte 2 – Gerenciamento de Turmas (Prática_Tipos_Estruturados.pdf)

**Estruturas criadas:**
- `Aluno`: matrícula, nome, 3 notas, média.
- `Turma`: identificador, vagas disponíveis, vetor de ponteiros para alunos.

**Funções implementadas:**
- `cria_turma`: aloca memória para a turma, define o identificador, inicializa vagas e coloca todos os ponteiros de alunos como `NULL`.
- `matricula_aluno`: verifica se há vaga, procura a primeira posição vazia, aloca memória para o aluno, inicializa notas com zero e armazena o ponteiro.
- `lanca_notas`: percorre os alunos matriculados, solicita as 3 notas e calcula a média aritmética.
- `imprime_alunos`: exibe matrícula, nome e média de cada aluno.
- `imprime_turmas`: lista todas as turmas criadas com suas vagas disponíveis.
- `procura_turma`: busca uma turma pelo identificador.
- `liberar_memoria`: libera toda a memória alocada (alunos e turmas).

**Menu interativo:**
O programa apresenta um menu com as opções:
1. Criar turma
2. Listar turmas
3. Matricular aluno
4. Lançar notas
5. Listar alunos
6. Sair

O menu valida se a turma existe antes de cada operação e trata erros como turma inexistente ou vagas esgotadas.

---

## Como compilar e executar

```bash
# Para compilar qualquer arquivo individual
g++ nome_do_arquivo.c -o nome_do_arquivo

# Para executar (Windows)
./nome_do_arquivo.exe

# Para executar (Linux/Mac)
./nome_do_arquivo
