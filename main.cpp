#include "jogo.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    int opcoes = 0,jogadores = 2;
    do{
        switch (opcoes){
            cout << "\033c";
            cout << "Selecione uma das opções a seguir: \n 1 • Jogar ▷\n 2 • Sobre ⁉️\n 3 • Jogadores \n 4 • Fim 𝕏\n";
            cin >> opcoes;
            system("cls");
            case 1:
                /* Play Game*/
                if(jogo(opcoes,jogadores)){
                    cout << "Fim de jogo, o jogo será encerrado, até a proxima :)\n";
                }
                break;
            case 2:
                /* Sobre */
                mostrarRegras();
            break;
            case 3:
                /*Jogadors*/
                selecionarJogador(jogadores);
            break;
            default:
                cout << "O jogo será encerrado, até a proxima :)\n";
                opcoes = 4;
            break;
        }
    } while (opcoes == 4);
 
    return 0;
}