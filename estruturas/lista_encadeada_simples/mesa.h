#ifndef L_E_S_MESA_H
#define L_E_S_MESA_H
    #define TAM_JOGADORES 4
    #include "jogador.h"
    #include <iostream>
    using namespace std;

    struct Mesa{
        Jogador jogadores[TAM_JOGADORES];
        int ultimo = -1;

        //Inicializar lista
        bool inicializar(){
            ultimo = -1;

            return true;
        };

        //Inserir na lista (início, posição, fim);
        bool inserir(Jogador jogador,bool ordenar = false){
            int index = ultimo + 1;

            //verifica se o tamanho do vetor e maior que o maximo
            if(index >= TAM_JOGADORES){
                return false;
            }
            // Lista vazia
            if(ultimo == -1){
                jogadores[0] = jogador;
            }
            // Inserir ordenado
            else if(ordenar){
                int ultimoIndex = ultimo;
                while(ultimoIndex != -1){
                    if(jogadores[ultimoIndex].nome > jogador.nome){
                        jogadores[ultimoIndex + 1] = jogadores[ultimoIndex];
                        ultimoIndex--;
                    }else{
                        jogadores[ultimoIndex + 1] = jogador;
                        ultimoIndex = -1;
                    }
                }
            }
            // Inserir sem ordenar
            else{
                jogadores[index] = jogador;
            }

            ultimo = index;
            return true;
        };

        // Remover da lista (início, posição, fim);
        bool remover(Jogador jogador){
            //busca o index do item
            int index = buscar(jogador);

            //caso achado item remove ele da lista
            if( index != -1 ){
                for( int i = index; i < ultimo; i++ ){
                    jogadores[i] = jogadores[i+1];
                }
                ultimo--;

                return true;
            }

            return false;
        };

        //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir);
        Jogador& pegar(int index){
            if(index <= ultimo && index >= 0){
                return jogadores[index];
            }
            return jogadores[0];
        };

        //Contém item – recebe o dado e verifica se ele está na lista. Se estiver, retorna verdadeiro, falso caso contrário;
        bool localizar(Jogador jogador){
            for( int i=0; i <= ultimo; i++ ){
                if( jogadores[i].nome == jogador.nome){
                    return true;
                }
            }
            return false;
        };

        //Descobrir índice – recebe o dado e busca-o na lista. Se estiver na lista, retorna à posição do dado na lista, caso contrário, retorna -1.
        int buscar(Jogador jogador){
            //passa por todos os valores para ver se esta la
            for( int i=0; i <= ultimo; i++ ){
                if( jogadores[i].nome == jogador.nome){
                    return i;
                }
            }

            //item nao encontrado
            return -1;
        };

        //Imprimir lista
        void imprimir(){
            cout << "Imprimindo jogadores na mesa:\n";
            for( int i=0; i <= ultimo; i++ ){
                cout << jogadores[i].nome << " " << ((i == ultimo) ? "\n" : "");
            }
        };
    };
#endif