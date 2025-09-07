#ifndef L_E_S_BARALHO_H
#define L_E_S_BARALHO_H
    #define TAM_BARALHO 40
    #include "carta.h"
    #include <iostream>
    #include <string>
    using namespace std;
    
    struct NoCarta {
        Carta dados;
        NoCarta* elo = nullptr;
    };

    struct Baralho{
        NoCarta *comeco, *fim;
        int tamanho = 0;

        bool iniciar(){
            while(comeco != nullptr) {
                NoCarta* temp = comeco;
                comeco = comeco->elo;
                delete temp;
            }
            comeco = nullptr;
            fim = nullptr;
            tamanho = 0;
            return true;
        };
        
        bool inserir(Carta carta,bool ordenado = false){
            NoCarta *nova = new NoCarta;
            if(nova == nullptr){
                return false;
            };
            
            nova->dados = carta;
            nova->elo = nullptr;

            if(ordenado){
                if(comeco == nullptr){ // Lista vazia
                    comeco = nova;
                    fim = nova;
                    return true;
                }
    
                if(carta.numero < comeco->dados.numero){ // Inser��o no come�o
                    nova->elo = comeco;
                    comeco = nova;
                    return true;
                }
    
                if(carta.numero > fim->dados.numero){ // Inser��o no final
                    fim->elo = nova;
                    fim = nova;
                    return true;
                }
    
                // Inser��o no meio da lista
                NoCarta *ant = comeco;
                NoCarta *prox = ant->elo;
                
                while(prox != nullptr){
                    if(ant->dados.numero < carta.numero && carta.numero < prox->dados.numero){
                        ant->elo = nova;
                        nova->elo = prox;
                        return true;
                    }
                    ant = prox;
                    prox = ant->elo;
                }
            }else{
                if(comeco == nullptr){ // Lista est� vazia
                    comeco = nova;
                    fim = nova;
                }else{
                    fim->elo = nova;
                    fim = nova;
                }
                return true;
            }
            return false;
        };
        
        //Remover da lista
        bool remover(Carta carta){
            NoCarta *anterior = nullptr, *referencia = comeco;
            
            // Busca elemento
            while(referencia != nullptr){
                if(carta.numero != referencia->dados.numero || carta.nipe != referencia->dados.nipe){
                    anterior = referencia;
                    referencia = referencia->elo;
                };
            }

            // Elemento não encontrado
            if(referencia == nullptr) {
                return false;
            };

            // Unico elemento
            if(referencia == comeco && referencia == fim){
                comeco = nullptr;
                fim = nullptr;
                delete referencia;
                return true;
            }

            // Retirando o primeiro elemento
            if( referencia == comeco ){
                comeco = referencia->elo;
                delete referencia;
                return true;
            }
            if( referencia == fim ){ //Retirando o ultimo
                anterior->elo = nullptr;
                fim = anterior;
                delete referencia;
                return true;
            }
            // Retirando do meio
            anterior->elo = referencia->elo;
            delete referencia;
            return true;
        };
        
        //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir)
        Carta& pegar(int index){
            NoCarta *referencia = comeco;
            if(index == 0){
                return referencia->dados;
            }
            
            int indexReferencia = 0;

            while( indexReferencia != index ){
                referencia = referencia->elo;
            }

            return referencia->dados;
        };
        
        //Contém item – recebe o dado e verifica se ele está na lista. Se estiver, retorna verdadeiro e falso caso contrário
        bool localizar(Carta carta){
            NoCarta* atual = comeco;
            while (atual != nullptr) {
                if (atual->dados.nipe == carta.nipe && atual->dados.numero == carta.numero) {
                    // Encontrou
                    return true;
                }
                atual = atual->elo;
            }
            // Não encontrou
            return false;
        };
        
        //Descobrir índice – recebe o dado e busca-o na lista. Se estiver na lista, retorna à posição do dado na lista, caso contrário, retorna -1
        int buscar(Carta carta){
            NoCarta* atual = comeco;
            int index = 0;
            
            while (atual != nullptr) {
                if (atual->dados.nipe == carta.nipe && atual->dados.numero == carta.numero) {
                    // Encontrou, retorna o índice
                    return index; 
                }
                atual = atual->elo;
                index++;
            }

            // Não encontrou
            return -1; 
        };

        //Imprimir lista
        void imprimir(){
            cout << "Imprimindo cartas do baralho:\n";
            NoCarta* atual = comeco;
            while(atual != nullptr){
                cout << atual->dados.label << " | ";
                atual = atual->elo;
            }
            cout << endl;
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
            if (tamanho >= 2) {
                NoCarta* referenciaComeco = nullptr;
                NoCarta* referenciaFim = nullptr;
                int index = tamanho;
    
                for (int i = 0; i < tamanho; i++) {
                    // índice aleatório do que resta da lista original
                    int k = rand() % index;
    
                    // remove o nó da lista original
                    NoCarta* anterior = nullptr;
                    NoCarta* atual = comeco;
                    for (int j = 0; j < k; j++) {
                        anterior = atual;
                        atual = atual->elo;
                    }
    
                    //nó da lista original
                    if (anterior == nullptr) { 
                        //primeiro elemento
                        comeco = atual->elo;
                    } else {
                        anterior->elo = atual->elo;
                    }
    
                    //nó removido ao final da nova lista embaralhada
                    atual->elo = nullptr; // Isola o nó
                    if (referenciaComeco == nullptr) { 
                        // Nova lista está vazia
                        referenciaComeco = atual;
                        referenciaFim = atual;
                    } else {
                        referenciaFim->elo = atual;
                        referenciaFim = atual;
                    }
    
                    index--;
                }
    
                // nova lista embaralhada se torna a lista do baralho
                comeco = referenciaComeco;
                fim = referenciaFim;
            }

        };

    };
#endif