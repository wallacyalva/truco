# 🃏 Truco Mineiro em C++

Este projeto é uma implementação para a disciplina de Estrutura de Dados, desenvolvido em C++, que simula a distribuição e as rodadas de um jogo de Truco Mineiro utilizando diferentes tipos de listas.

## 🎮 Como Jogar

- Ao iniciar o jogo, informe as **dimensões do campo** (máximo de 30x30) e a **quantidade de bombas**.
- Clique com o botão esquerdo para revelar um campo.
- Clique com o botão direito para **marcar** uma bomba com uma bandeira 🚩.
- O jogo termina quando:
  - Você revela todas as células **sem bombas** (vitória).
  - Você clica em uma bomba (derrota).

## 🎯 Objetivo do Projeto

- O objetivo deste trabalho é implementar e aplicar na prática as sistemáticas de distribuição de cartas e o controlo de rodadas de uma partida de baralho. Para isso, serão desenvolvidas do zero as seguintes estruturas de dados:

  - Lista Estática
  - Lista Encadeada Simples
  - Lista Duplamente Encadeada

## ⚙️ Regras da Simulação
- A simulação é baseada numa versão simplificada do Truco Mineiro com as seguintes regras:

  - Baralho: Utiliza-se um baralho de 40 cartas (são removidas as cartas 8, 9 e 10).
  - Jogadores: O programa permite um número variável de jogadores, definido no início da execução.
  - Distribuição: Cada jogador recebe 3 cartas no início de cada mão.
  - Rodadas: Uma mão é composta por 3 rodadas, onde cada jogador descarta uma carta por vez.
  - Foco: A simulação concentra-se na manipulação das estruturas (criar baralho, embaralhar, distribuir, descartar), sem implementar a lógica de pontuação ou vitória.

## 🛠️ Estruturas Implementadas
- O projeto é dividido nos seguintes Tipos Abstratos de Dados (TADs):

  - Listas: Ficheiros ListaEstatica.h, ListaEncadeada.h, e ListaDuplamente.h com as operações de inserir, remover, obter, verificar, procurar e imprimir.

- TADs do Jogo:

  - Carta.h: Modela uma carta com valor e naipe.
  - Baralho.h: Gerencia o conjunto de 40 cartas.
  - Jogador.h: Representa um jogador e a sua "mão" de cartas.

## 📁 Estrutura do Projeto
```plaintext
truco-mineiro-cpp/
├── main.cpp
├── ListaEstatica.h
├── ListaEstatica.cpp
├── ListaEncadeada.h
├── ListaEncadeada.cpp
├── ListaDuplamente.h
├── ListaDuplamente.cpp
├── Carta.h
├── Carta.cpp
├── Baralho.h
├── Baralho.cpp
├── Jogador.h
└── Jogador.cpp
```

## ▶️ Executando o Projeto

### Pré-requisitos
- É necessário ter um compilador C++, como o G++, instalado no sistema.

### Compilando o projeto
- Utilize o seguinte comando no terminal para compilar todos os ficheiros .cpp e gerar um executável chamado truco:
```bash
g++ -o truco *.cpp
```

### Executando a simulação
Após a compilação, execute o programa com o comando:
```bash
./truco
```

## 👨‍💻 Autores
Wallacy Alvarenga - 6916694
