#define TAM_BARALHO 40
#include "carta.h"
#include <iostream>
#include <string>
using namespace std;

struct Baralho{
    Carta Cartas[TAM_BARALHO];
    int ultimo = -1;

    bool iniciar(){
        ultimo = -1;

        return true;
    };
    
    bool inserir(Carta carta,bool ordenar = false){
        int index = ultimo + 1;

        //verifica se o tamanho do vetor e maior que o maximo
        if(index >= TAM_BARALHO){
            return false;
        }

        // Lista vazia
        if(ultimo == -1){
            Cartas[0] = carta;
        }
        // Inserir ordenado
        else if(ordenar){
            int ultimoIndex = ultimo;
            while(ultimoIndex != -1){
                if(Cartas[ultimoIndex].numero > carta.numero){
                    Cartas[ultimoIndex + 1] = Cartas[ultimoIndex];
                    ultimoIndex--;
                }else{
                    Cartas[ultimoIndex + 1] = carta;
                    ultimoIndex = -1;
                }
            }
        }
        // Inserir sem ordenar
        else{
            Cartas[ultimo + 1] = carta;
        }

        ultimo = index;
        return true;
    };
    
    //Remover da lista
    bool remover(Carta carta){
        //busca o index do item
        int index = buscar(carta);

        //caso achado item remove ele da lista
        if( index != -1 ){
            for( int i = index; i < ultimo; i++ ){
                Cartas[i] = Cartas[i+1];
            }
            ultimo--;
            
            return true;
        } 

        return false;
    };
    
    //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir)
    Carta pegar(int index){
        if(index <= ultimo && index >= 0){
            return Cartas[index];
        }
        return Carta {0, 0, "Carta Invalida"};
    };
    
    //Contém item – recebe o dado e verifica se ele está na lista. Se estiver, retorna verdadeiro e falso caso contrário
    bool localizar(Carta carta){
        for( int i=0; i <= ultimo; i++ ){
            if( Cartas[i].nipe == carta.nipe && Cartas[i].numero == carta.numero){
                return true;
            }
        }
        return false;
    };
    
    //Descobrir índice – recebe o dado e busca-o na lista. Se estiver na lista, retorna à posição do dado na lista, caso contrário, retorna -1
    int buscar(Carta carta){
        //passa por todos os valores para ver se esta la
        for( int i=0; i <= ultimo; i++ ){
            if( Cartas[i].nipe == carta.nipe && Cartas[i].numero == carta.numero){
                return i;
            }
        }

        //item nao encontrado
        return -1;
    };

    //Imprimir lista
    void imprimir(){
        for( int i=0; i <= ultimo; i++ ){
            cout << Cartas[i].label << " ";
        }
    };

    void gerarCartas(){
        iniciar();
        for (int numero = 1; numero <= 10; numero++){
            for (int nipe = 0; nipe <= 3; nipe++){
                Carta carta;
                carta.numero = numero;
                carta.nipe = nipe;
                carta.gerarLabel();
                inserir(carta);
            }
        }
        
    };

    // Função para embaralhar as cartas do baralho
    void embaralhar(){
        // Não é possível embaralhar 0 ou 1 carta
        if (ultimo < 1) {
            return;
        }


        // Percorre o baralho do final até o segundo elemento
        for (int i = ultimo; i > 0; i--) {
            // Escolhe um índice aleatório
            int j = rand() % (i + 1);

            // Troca a carta da posição
            Carta temp = Cartas[i];
            Cartas[i] = Cartas[j];
            Cartas[j] = temp;
        }
    };

};