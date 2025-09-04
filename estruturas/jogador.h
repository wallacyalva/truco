#define TAM_MAO 3
#include "carta.h"
#include <iostream>
using namespace std;

struct Mao{
    Carta cartas[TAM_MAO];
    int ultimo = -1;

    //Inicializar lista
    bool inicializar(){
        ultimo = -1;

        return true;
    };

    //Inserir na lista (início, posição, fim);
    bool inserir(Carta carta,bool ordenar = false){
        int index = ultimo + 1;

        //verifica se o tamanho do vetor e maior que o maximo
        if(index >= TAM_MAO){
            return false;
        }
        // Lista vazia
        if(ultimo == -1){
            cartas[0] = carta;
        }
        // Inserir ordenado
        else if(ordenar){
            int ultimoIndex = ultimo;
            while(ultimoIndex != -1){
                if(cartas[ultimoIndex].numero > carta.numero){
                    cartas[ultimoIndex + 1] = cartas[ultimoIndex];
                    ultimoIndex--;
                }else{
                    cartas[ultimoIndex + 1] = carta;
                    ultimoIndex = -1;
                }
            }
        }
        // Inserir sem ordenar
        else{
            cartas[index] = carta;
        }

        ultimo = index;
        return true;
    };

    // Remover da lista (início, posição, fim); 
    bool remover(Carta carta){
        //busca o index do item
        int index = buscar(carta);

        //caso achado item remove ele da lista
        if( index != -1 ){
            for( int i = index; i < ultimo; i++ ){
                cartas[i] = cartas[i+1];
            }
            ultimo--;
            
            return true;
        } 

        return false;
    };

    //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir);
    Carta pegar(int index){
        if(index <= ultimo && index >= 0){
            return cartas[index];
        }
        return Carta {0, 0, "Carta Invalida"};
    };

    //Contém item – recebe o dado e verifica se ele está na lista. Se estiver, retorna verdadeiro, falso caso contrário; 
    bool localizar(Carta carta){
        for( int i=0; i <= ultimo; i++ ){
            if( cartas[i].nipe == carta.nipe && cartas[i].numero == carta.numero){
                return true;
            }
        }
        return false;
    };

    //Descobrir índice – recebe o dado e busca-o na lista. Se estiver na lista, retorna à posição do dado na lista, caso contrário, retorna -1.
    int buscar(Carta carta){
        //passa por todos os valores para ver se esta la
        for( int i=0; i <= ultimo; i++ ){
            if( cartas[i].nipe == carta.nipe && cartas[i].numero == carta.numero){
                return i;
            }
        }

        //item nao encontrado
        return -1;
    };

    //Imprimir lista
    void imprimir(){
        for( int i=0; i <= ultimo; i++ ){
            cout << cartas[i].label << " "<< ((i == ultimo) ? "\n" : "");
        }
    };

    //contar
    int contar(){
        return ultimo + 1;
    };

};

struct Jogador{
    string nome;
    Mao mao;
};