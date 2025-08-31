Estrutura de Dados - Simulação de Truco Mineiro em C++
Este projeto foi desenvolvido para a disciplina de Estrutura de Dados e tem como objetivo aplicar os conceitos de Listas (Estática, Encadeada Simples e Duplamente Encadeada) na simulação de um jogo de cartas, especificamente o Truco Mineiro.

🎯 Objetivo
O foco principal do trabalho é implementar, a partir do zero, diferentes tipos de listas para gerenciar as mecânicas centrais de um jogo de baralho: a criação e o embaralhamento de um deck de cartas, a distribuição dessas cartas aos jogadores e o controle das rodadas, onde cada jogador descarta uma carta por vez.

🃏 O Jogo: Truco Mineiro
Para contextualizar a aplicação das estruturas de dados, o jogo escolhido foi o Truco Mineiro. As seguintes regras e características foram consideradas para a simulação:

Baralho (1): Utiliza-se um baralho limpo, contendo 40 cartas (excluindo-se 8, 9, 10 e coringas).

Jogadores (Variável): O programa é projetado para suportar um número variável de jogadores, a ser definido no início da execução.

Cartas por Jogador (Fixo): Cada jogador recebe 3 cartas no início de cada mão.

Rodadas (Variável): Uma "mão" completa consiste em até 3 rodadas. A simulação executará um número pré-definido de mãos para demonstrar o funcionamento.

O projeto se concentra na logística do jogo (distribuição e descarte), não sendo necessário implementar a contagem de pontos ou a lógica de vitória, embora um sistema simples possa ser adicionado como um bônus.

🛠️ Estruturas de Dados Implementadas
O núcleo do projeto consiste na criação dos seguintes Tipos Abstratos de Dados (TADs) em C++:

1. TAD Lista Estática
Implementação de uma lista baseada em um array de tamanho fixo.

Operações:

InicializarLista(): Prepara a lista para uso.

Inserir(item, posicao): Adiciona um item no início, fim ou em uma posição específica.

Remover(posicao): Retira um item do início, fim ou de uma posição específica.

ObterItem(posicao): Retorna o dado de uma posição, se ela for válida.

ContemItem(item): Verifica se um dado específico existe na lista.

DescobrirIndice(item): Retorna a posição de um dado, se ele existir na lista.

ImprimirLista(): Exibe todos os elementos da lista.

2. TAD Lista Encadeada Simples
Implementação de uma lista dinâmica onde cada elemento aponta para seu sucessor.

Operações: Possui as mesmas operações da Lista Estática.

3. TAD Lista Duplamente Encadeada
Implementação de uma lista dinâmica onde cada elemento aponta para seu sucessor e seu predecessor.

Operações: Possui as mesmas operações das listas anteriores.

4. TADs de Domínio da Aplicação
Para modelar o jogo, foram criados os seguintes TADs:

Carta: Representa uma carta individual, com atributos para valor (A, 2, 3, 4, 5, 6, 7, Q, J, K) e naipe (Ouros, Espadas, Copas, Paus).

Baralho: Gerencia o conjunto de 40 cartas, utilizando uma das listas implementadas para permitir as operações de embaralhar e distribuir.

Jogador: Modela um jogador, contendo um nome ou ID e uma mao (uma lista para armazenar suas 3 cartas).

⚙️ Funcionamento da Simulação
O programa será executado de forma automática, sem interação do usuário após a configuração inicial, avançando ao pressionar de uma tecla para facilitar a visualização. Os passos são:

Configuração Inicial: Define-se o número de jogadores que participarão da partida.

Criação do Baralho: O baralho é instanciado e preenchido com as 40 cartas.

Embaralhamento: O baralho é desordenado para garantir a aleatoriedade.

Distribuição de Cartas: O programa remove as cartas do topo do baralho e as insere na mão de cada jogador, sequencialmente, até que todos tenham 3 cartas.

Simulação das Rodadas:

Para cada uma das 3 rodadas da mão:

Cada jogador "joga" (remove) uma carta de sua mão.

A ação é registrada em um log.

Log de Rodadas: Ao final de cada mão, um relatório é impresso no console, detalhando as jogadas. Exemplo:

================== MÃO 1 ==================
[LOG] Rodada 1:
  - Jogador 1 descartou: 4 de Paus
  - Jogador 2 descartou: 7 de Copas
[LOG] Rodada 2:
  - Jogador 1 descartou: Ás de Espadas
  - Jogador 2 descartou: 2 de Ouros
...
===========================================

🚀 Como Compilar e Executar
Esta seção será atualizada com os comandos finais.

Pré-requisitos:

Um compilador C++, como o G++.

Comando de Compilação (Exemplo):

g++ -o truco *.cpp

Comando de Execução (Exemplo):

./truco

👨‍💻 Autores
[Seu Nome Completo] - [Sua Matrícula]

[Nome do Colega 1] - [Matrícula]

[Nome do Colega 2] - [Matrícula]
