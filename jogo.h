#include <iostream>
#include <string>
using namespace std;


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
    if(players != 2 || players != 4){
        players = 2;
    }
    cout << "Jogadores definidos como " << players << ".\n";
    cout << "Pressione qualquer tecla para voltar ao menu principal...\n";
    cin.ignore();
    cout<< cin.get();
    cout<<"\033c";
}

bool jogo(int &opcoes, int &jogadores){
    
    return true;
}
