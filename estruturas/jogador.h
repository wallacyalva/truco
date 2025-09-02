#define TAM_MAO 3
#include "carta.h"
#include <iostream>
using namespace std;

struct No{
    Carta info;
    No *elo = nullptr;

    void inicializar(){
        elo = nullptr;
    }
     
    bool inserir(Carta &carta){
        if(contar() >= TAM_MAO) return false;

        No *no = new No();
        no->inicializar();
        carta.gerarLabel();
        no->info = carta;

        return true;
    }

    bool remover(Carta *carta){
        No *no = buscar(carta);
        
        if(no == nullptr) return false;


    }

    No *buscar(Carta *carta){
        No *aux = elo;

        while(aux->info.label != carta->label || aux != nullptr){
            aux = aux->elo;
        }

        return aux;
    }

    int contar(){
        No *aux = elo;
        int i = 0;

        while(aux != nullptr){
            aux = aux->elo;
            i++;
        }

        return i;
    }
};

struct Mao{
    No *fim;

    //Inicializar lista
    bool inicializar(){
        fim = nullptr;
    };

    //Inserir na lista (início, posição, fim);
    bool inserir(){

    };

    // Remover da lista (início, posição, fim); 
    bool remover(){

    };

    //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir);
    Carta pegar(){
    
    };

    //Contém item – recebe o dado e verifica se ele está na lista. Se estiver, retorna verdadeiro, falso caso contrário; 
    bool localizar(){

    };

    //Descobrir índice – recebe o dado e busca-o na lista. Se estiver na lista, retorna à posição do dado na lista, caso contrário, retorna -1.
    int buscar(){

    };

    //Imprimir lista
    void imprimir(){

    };

    //contar
    int contar(){

    };

};

struct Jogador{
    string nome;
    Mao mao;
};