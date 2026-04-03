atividades-c-estruturas
Bloco 1 – Ponteiros e Aritmética de Ponteiros
Exercício 1

Nesse primeiro exercício a ideia era só entender o funcionamento básico de ponteiros.
Criei uma variável x e um ponteiro p. Quando fiz p = &x, o ponteiro passou a armazenar o endereço de memória da variável x. Depois imprimi o valor de x, o endereço de x, o valor armazenado em p (que é justamente esse endereço) e o valor apontado por p usando *p. Esse exercício foi importante para entender a diferença entre valor e endereço.

Exercício 2

Aqui o objetivo era alterar o valor de uma variável usando ponteiro.
Fiz um ponteiro apontar para a variável n e depois usei *p = 20. Dessa forma, o valor de n foi alterado indiretamente, sem modificar a variável diretamente pelo nome dela, apenas através do ponteiro.

Exercício 3

Nesse exercício fiz uma função para somar dois números usando ponteiros.
A função recebe três ponteiros: dois para os valores que serão somados e um para armazenar o resultado. Dentro da função, usei *a e *b para acessar os valores e depois guardei o resultado em *resultado. Na função principal, passei os endereços das variáveis usando o operador &.

Exercício 4

Aqui foi feita a troca de valores entre duas variáveis (swap).
Usei uma variável auxiliar para armazenar temporariamente um dos valores, depois fiz a troca usando os ponteiros. Assim, os valores das variáveis foram trocados de forma permanente.

Exercício 5

Nesse exercício precisei criar uma função que retornasse o maior entre dois números usando ponteiros.
Comparei os valores apontados pelos ponteiros e retornei o maior deles utilizando o operador ternário.

Exercício 6

Aqui comecei a trabalhar com vetores usando ponteiros.
Como o nome do vetor já representa o endereço do primeiro elemento, atribuí o vetor a um ponteiro e percorri os elementos usando aritmética de ponteiros, acessando cada posição com *(p + i).

Exercício 7

Esse exercício foi parecido com o anterior, mas o objetivo era somar todos os elementos do vetor.
Percorri o vetor usando ponteiros e fui acumulando a soma em uma variável.

Exercício 8

Nesse exercício precisei encontrar o maior elemento de um vetor.
Comecei considerando o primeiro elemento como o maior e depois percorri o vetor comparando com os demais valores. Sempre que encontrava um valor maior, atualizava a variável que armazenava o maior.

Exercício 9

Aqui trabalhei com ponteiro para ponteiro.
Criei uma variável, um ponteiro apontando para ela e um segundo ponteiro apontando para o primeiro. Depois mostrei que era possível acessar o valor da variável diretamente, pelo ponteiro e pelo ponteiro de ponteiro (**pp).

Exercício 10

Nesse exercício inverti um vetor usando ponteiros.
Utilizei dois ponteiros: um apontando para o início do vetor e outro para o final. Fui trocando os valores enquanto o ponteiro do início era menor que o do final, movendo um para frente e o outro para trás.

Exercício 11 (Desafio)

Aqui trabalhei com alocação dinâmica de memória.
Primeiro pedi ao usuário o tamanho do vetor, depois aloquei memória usando malloc. Verifiquei se a alocação deu certo, li os valores, calculei a média e no final liberei a memória usando free.

Bloco 2 – Alocação Dinâmica
Matriz 5x5 com índices

Nesse exercício fiz a alocação dinâmica de uma matriz.
Como uma matriz dinâmica em C é representada por um ponteiro para ponteiro (int**), primeiro aloquei memória para as linhas e depois para as colunas de cada linha. Preenchi a matriz com valores baseados na posição dos índices e, ao final, liberei toda a memória alocada.

Bloco 3 – Vetores e Matrizes
Exercício 1 – Vetor invertido

Aqui aloquei dinamicamente um vetor, li os valores informados pelo usuário e depois imprimi o vetor em ordem inversa, começando do último elemento até o primeiro.

Exercício 2 – Matriz e transposta

Nesse exercício criei uma matriz e também sua transposta.
A transposta foi feita trocando as posições dos índices, ou seja, o elemento [i][j] da matriz original virou [j][i] na matriz transposta.

Exercício 3 – Matriz quadrada aleatória

Aqui aloquei uma matriz quadrada e preenchi com números aleatórios.
Usei srand(time(NULL)) para que os números mudassem a cada execução e utilizei rand() para gerar valores dentro de um intervalo definido.

Exercício 4 – Nomes e idades

Nesse exercício trabalhei com alocação dinâmica para armazenar nomes e idades.
Usei um vetor de ponteiros para armazenar os nomes e um vetor de inteiros para as idades. Para cada nome, aloquei memória separadamente. No final, liberei toda a memória que foi alocada.

Bloco 4 – Tipos Estruturados
Parte 1 – Funcionário e Pessoa

Aqui trabalhei com estruturas (struct) para organizar dados mais complexos.

Para Funcionário, criei funções para:

preencher os dados
imprimir os dados
alterar o salário
encontrar o maior e o menor salário

Para Pessoa, fiz funções para:

preencher os dados
imprimir
atualizar idade
encontrar a pessoa mais velha e a mais nova
Parte 2 – Gerenciamento de Turmas

Essa parte foi a mais completa, funcionando como um pequeno sistema.

Criei duas estruturas:

Aluno (matrícula, nome, notas e média)
Turma (identificador, vagas e vetor de alunos)

Depois implementei funções para:

criar turma
matricular aluno
lançar notas
listar alunos
listar turmas
procurar turma
liberar memória

O programa funciona com um menu interativo onde o usuário pode escolher as operações. Também fiz verificações para evitar erros, como tentar matricular aluno em turma cheia ou acessar turma que não existe.

Resumo geral

Essas atividades foram importantes para entender melhor:

ponteiros
aritmética de ponteiros
alocação dinâmica
vetores e matrizes dinâmicas
estruturas em C
organização de programas maiores

Basicamente, foi uma prática completa sobre manipulação de memória e estruturas de dados na linguagem C.
