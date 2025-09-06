#include <iostream>
#include <string>
using namespace std;
#include "estruturas/mesa.h"
#include "estruturas/baralho.h"

int calculaValor(Carta carta) {
    int valor = 0;
    switch (carta.numero){
        case 3:
            valor = 10;
        break;
        case 2:
            valor = 9;
        break;
        case 1:
            if(carta.nipe == 1){
                valor = 13;
            }else{
                valor = 8;
            }
        break;
        case 10:
            valor = 7;

        break;
        case 9:
            valor = 6;

        break;
        case 8:
            valor = 5;

        break;
        case 7:{
            if(carta.nipe == 0){
                valor = 11;
            }else if(carta.nipe == 2){
                valor = 12;
            }else{
                valor = 4;
            }
        }
        break;
        case 6:
            valor = 3;

        break;
        case 5:
            valor = 2;

        break;
        case 4:
            if(carta.nipe == 3){
                valor = 14;
            }else{
                valor = 1;
            }
        break;
    }

    return valor;
}

int compararCartas(Carta carta1, Carta carta2) {
    int valorCata1 = calculaValor(carta1);
    int valorCata2 = calculaValor(carta2);

    if(valorCata1 > valorCata2){
        return 1;
    }else if(valorCata2 > valorCata1){
        return 2;
    }else{
        return 0;
    }
}

void mostrarRegras() {
    cout << "\n--- 🃏 Regras do Truco Mineiro 🃏 ---\n\n";
    
    cout << "O objetivo do jogo é ser a primeira dupla ou jogador a atingir 12 pontos.\n\n";

    cout << "🎴 BARALHO E CARTAS:\n";
    cout << " - Cartas em Jogo: Utiliza-se um baralho normal, retirando as cartas 8, 9 e 10.\n\n";

    cout << " ✨ MANILHAS (As cartas mais fortes):\n";
    cout << " - A ordem de força das manilhas é fixa, sendo sempre a seguinte:\n";
    cout << "   1º (Maior): 4 de Paus (Zap) ♣️\n";
    cout << "   2º: 7 de Copas ♥️\n";
    cout << "   3º: Ás de Espadas (Espadilha) ♠️\n";
    cout << "   4º: 7 de Ouros (Pica-fumo) ♦️\n\n";

    cout << " 💪 ORDEM DE FORÇA (Cartas Comuns):\n";
    cout << " - Para as demais cartas, a ordem de força é:\n";
    cout << "   3 > 2 > A > K > J > Q > 7 > 6 > 5 > 4\n\n";

    cout << "🎮 JOGABILIDADE E PONTUAÇÃO:\n";
    cout << " - Jogadores: Pode ser jogado em 2 (1x1) ou 4 jogadores (em duplas 2x2).\n";
    cout << " - Cartas por Mão: Cada jogador recebe 3 cartas no início de cada mão.\n";
    cout << " - Rodadas: Uma \"mão\" é disputada em até 3 rodadas. Quem joga a carta mais forte vence a rodada.\n";
    cout << " - Vencedor da Mão: A dupla que vencer duas rodadas leva os pontos da mão.\n";
    cout << " - Pontuação: Uma mão inicia valendo 2 pontos. A primeira equipe a fazer 12 pontos vence o jogo.\n\n";
    
    cout << "🤝 EMPATES:\n";
    cout << " - Se uma rodada terminar empatada, a rodada seguinte decide o vencedor da mão.\n";
    cout << " - Se todas as três rodadas empatarem, ninguém ganha os pontos e uma nova mão é iniciada.\n\n";
    
    cout << "Pressione qualquer tecla para voltar ao menu principal...\n";
    cin.ignore();
    cout<< cin.get();
    cout<<"\033c";
}

void selecionarJogador(int &players){
    cout << "Quantidade disponivel sao: 2 ou 4\n";
    cout << "Quantidade atual é: " << players << "\n";
    cout << "Selecione a quantidade de jogadores:\n";
    cin >> players;
    if(players != 2 && players != 4){
        players = 2;
    }
    cout << "Jogadores definidos como " << players << ".\n";
    cout << "Pressione qualquer tecla para voltar ao menu principal...\n";
    cin.ignore();
    cout<< cin.get();
    cout<<"\033c";
}

bool jogo(int jogadores){
    
    Mesa mesa;
    Baralho baralho;

    mesa.inicializar();
    cout << "Mesa iniciada \n";
    //adiciona os jogadores a mesa
    for (int i = 0; i < jogadores; i++){
        Jogador jogador;
        jogador.nome = "Jogador " + to_string(i + 1);
        mesa.inserir(jogador);
        cout << "adiconado jogador de index:" << i << " \n";
    }
    
    baralho.gerarCartas();
    cout << "Cartas criadas e adicionadas ao baralho \n";
    baralho.imprimir();
    int pontos1 = 0;
    int pontos2 = 0;

    do{
        cout << "Placar: Time 1 (" << pontos1 << ") x (" << pontos2 << ") Time 2\n";

        // Antes de distribuir novas cartas, é preciso resetar a mão de cada jogador.
        for (int i = 0; i < jogadores; i++){
            mesa.pegar(i).mao.inicializar();
        }

        baralho.embaralhar();
        cout << "Baralho embaralhado \n";
        baralho.imprimir();
        
        //distribuicao de cartas
        //quantidade de cartas na mao
        for (int j = 0; j < 3; j++){
            //quantidade de jogadores na mesa
            for (int i = 0; i < jogadores; i++){
                Jogador& jogador = mesa.pegar(i);
                cout << "Pegado jogador de index:" << i << ". com o nome de:" << jogador.nome <<" \n";
                Carta carta = baralho.pegar(0);
                cout << "Pegado a carta de cima do baralho:" << carta.label << " \n";
                jogador.mao.inserir(carta);
                cout << "Adicionado a carta: " << carta.label << ". a mao do jogador: " << jogador.nome << " \n";
                jogador.mao.imprimir();
                baralho.remover(carta);
                cout << "retirado a carta: " << carta.label << "do baralho \n";
                cout << "cartas atuais do baralho: \n";
                baralho.imprimir();
            }
        }

        int maos1 = 0;
        int maos2 = 0;
        int round = 0;
        //usada para quando a mao ficou melada (empatada)
        bool decisiva = false;
        do{
            bool melada = false;
            Carta cartaGanhando;
            int jogadorGanhando = 0;
            //certifica de cada jogador faze sua jogada na mao
            for (int i = 0; i < jogadores; i++){
                Jogador& jogador = mesa.pegar(i);
                cout << "Vez do jogador:" << jogador.nome << " \n";
                int numCartasNaMao = jogador.mao.contar();
                cout << numCartasNaMao << "index carta \n";
                Carta carta = jogador.mao.pegar(rand() % numCartasNaMao);
                cout << "pegou a carta:" << carta.label << " \n";
                //se for o primeiro ele esta ganhando
                if(i == 0){
                    jogadorGanhando = i;
                    cartaGanhando = carta;
                }else{
                    //verifica à partir da regra se a carta matou ou nao
                    int resultado = compararCartas(cartaGanhando,carta);
                    if(resultado == 2 || resultado == 0){
                        jogadorGanhando = i;
                        cartaGanhando = carta;
                        if(resultado == 2){
                            melada = false;
                        }else{
                            melada = true;
                        }
                    }
                }
                cout << "O jogador jogou a carta:" << carta.label << " \n";
                baralho.inserir(carta);
                jogador.mao.remover(carta);
                jogador.mao.imprimir();
            }

            if(decisiva && !melada){
                cout << "O jogador:" << mesa.pegar(jogadorGanhando).nome << "ganhou o round\n";
                    if(jogadorGanhando == 0 || jogadorGanhando == 2){
                        maos1 = 2;
                    }else{
                        maos2 = 2;
                    }
            }else{
                if(melada){
                    cout << "A mão ficou melada\n";
                    decisiva = true;
                    melada = false;
                }else{
                    cout << "O jogador:" << mesa.pegar(jogadorGanhando).nome << "ganhou a mao\n";
                    if(jogadorGanhando == 0 || jogadorGanhando == 2){
                        maos1++;
                    }else{
                        maos2++;
                    }
                }
            }
            
            round++;
        } while (maos1 < 2 && maos2 < 2 && round < 3);

        if(maos1 == 2){
            if(jogadores == 2){
                cout << "O Jogador 1 ganhou o roud\n";
            }else{
                cout << "O time 1 ganhou o roud\n";
            }

            pontos1 += 2;
        }else if(maos2 == 2){
            if(jogadores == 2){
                cout << "O Jogador 2 ganhou o roud\n";
            }else{
                cout << "O time 2 ganhou o roud\n";
            }

            pontos2 += 2;
        }else if(round != 3){
            cout << "O roud ficou melado (ninguem pontua)\n";
        }
    } while (pontos1 < 12 && pontos2 < 12);
    
    if(pontos1 > pontos2){
        if(jogadores == 2){
            cout << "O Jogador 1 ganhou o jogo\n";
        }else{
            cout << "O time 1 ganhou o jogo\n";
        }
    }else{
        if(jogadores == 2){
            cout << "O Jogador 2 ganhou o jogo\n";
        }else{
            cout << "O time 2 ganhou o jogo\n";
        }
    }
    
    return true;
}
