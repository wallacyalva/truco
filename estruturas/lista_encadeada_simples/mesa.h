#ifndef L_E_S_MESA_H
#define L_E_S_MESA_H
    #include "jogador.h"
    #include <iostream>
    using namespace std;
    
    struct NoJogador {
        Jogador dados;
        NoJogador* elo = nullptr;
    };

    struct Mesa{
        NoJogador *comeco = nullptr, *fim = nullptr;
        int tamanho = 0;
        
        //Inicializar lista
        bool inicializar(){
            while(comeco != nullptr) {
                NoJogador* temp = comeco;
                comeco = comeco->elo;
                delete temp;
            }
            comeco = nullptr;
            fim = nullptr;
            tamanho = 0;
            return true;
        };
        
        //Inserir na lista (início, posição, fim);
        bool inserir(Jogador jogador,bool ordenado = false){
            NoJogador *nova = new NoJogador;
            if(nova == nullptr){
                return false;
            };
            
            nova->dados = jogador;
            nova->elo = nullptr;

            if(ordenado){
                if(comeco == nullptr){ // Lista vazia
                    comeco = nova;
                    fim = nova;
                    tamanho += 1;
                    return true;
                }
    
                if(jogador.nome < comeco->dados.nome){ // Inser��o no come�o
                    nova->elo = comeco;
                    comeco = nova;
                    tamanho += 1;
                    return true;
                }
    
                if(jogador.nome > fim->dados.nome){ // Inser��o no final
                    fim->elo = nova;
                    fim = nova;
                    tamanho += 1;
                    return true;
                }
    
                // Inser��o no meio da lista
                NoJogador *ant = comeco;
                NoJogador *prox = ant->elo;
                
                while(prox != nullptr){
                    if(ant->dados.nome < jogador.nome){
                        ant->elo = nova;
                        nova->elo = prox;
                        tamanho += 1;
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
                tamanho += 1;
                return true;
            }
            return false;
        };

        //Remover da lista
        bool remover(Jogador jogador){
            NoJogador *anterior = nullptr, *referencia = comeco;
            
            // Busca elemento
            while(referencia != nullptr){
                if(jogador.nome != referencia->dados.nome){
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
                tamanho -= 1;
                return true;
            }

            // Retirando o primeiro elemento
            if( referencia == comeco ){
                comeco = referencia->elo;
                delete referencia;
                tamanho -= 1;
                return true;
            }
            if( referencia == fim ){ //Retirando o ultimo
                anterior->elo = nullptr;
                fim = anterior;
                delete referencia;
                tamanho -= 1;
                return true;
            }
            // Retirando do meio
            anterior->elo = referencia->elo;
            delete referencia;
            tamanho -= 1;
            return true;
        };

        //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir);
        Jogador& pegar(int index){
            // Verificação de segurança
            if (index < 0 || index >= tamanho || comeco == nullptr) {
                cout << "cachorro moorto" << to_string(tamanho);
                return comeco->dados; // Retorno de segurança
            }

            NoJogador *referencia = comeco;

            // CORREÇÃO: O loop agora avança corretamente até o índice desejado.
            for(int i = 0; i < index; i++){
                referencia = referencia->elo;
            }

            return referencia->dados;
        };

        //Contém item – recebe o dado e verifica se ele está na lista. Se estiver, retorna verdadeiro, falso caso contrário;
        bool localizar(Jogador jogador){
            NoJogador* atual = comeco;
            while (atual != nullptr) {
                if (atual->dados.nome == jogador.nome) {
                    // Encontrou
                    return true;
                }
                atual = atual->elo;
            }
            // Não encontrou
            return false;
        };

        //Descobrir índice – recebe o dado e busca-o na lista. Se estiver na lista, retorna à posição do dado na lista, caso contrário, retorna -1.
        int buscar(Jogador jogador){
            NoJogador* atual = comeco;
            int index = 0;

            while (atual != nullptr) {
                if (atual->dados.nome == jogador.nome) {
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
            cout << "Imprimindo os jogadores da mesa:\n";
            NoJogador* atual = comeco;
            while(atual != nullptr){
                cout << atual->dados.nome << " | ";
                atual = atual->elo;
            }
            cout << endl;
        };
    };
#endif