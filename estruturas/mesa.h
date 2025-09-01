#include "jogador.h"
#include <iostream>
using namespace std;

struct No{
    Jogador info;
    No *eloA, *eloP;
};

struct Mesa{
    No *comeco, *fim;
    
    //Inicializar lista
    bool inicializar(){

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
};