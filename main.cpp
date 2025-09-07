// feito por:
// Daniel Uesler de Brito (daniel.8071330@edu.univali.br) - 8071330
// Wallacy Alvarenga (wallacyalvarenga@univali.br) - 6916694
// Mude o valor abaixo para escolher a implementação da lista
// 1 = Lista Estática
// 2 = Lista Encadeada Simples
// 3 = Lista Duplamente Encadeada
#define TIPO_LISTA 2
#include <iostream>
#include <string>
// #include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;
#include "jogo.h"

int main() {
    // SetConsoleOutputCP(65001);
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    int opcoes = 0,jogadores = 2;
    do{
        cout << "\033c";
        cout << "Selecione uma das opções a seguir: \n 1 • Jogar ▷\n 2 • Sobre ⁉️\n 3 • Jogadores \n 4 • Fim 𝕏\n";
        cin >> opcoes;
        system("cls");

        switch (opcoes){
            case 1:
                /* Play Game*/
                if(jogo(jogadores)){
                    cout << "Fim de jogo, Pressione qualquer tecla para encerrar o jogo, até a proxima :)\n";
                    cin.ignore();
                    cout<< cin.get();
                    cout<<"\033c";
                    opcoes = 4;
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
    } while (opcoes != 4);

    return 0;
}
