#ifndef L_D_E_MESA_H
#define L_D_E_MESA_H
    #include "jogador.h"
    #include <iostream>
    using namespace std;

    struct NoJogador {
        Jogador dados;
        NoJogador* eloAnt = nullptr;
        NoJogador* eloProx = nullptr;
    };

    struct Mesa{
        NoJogador *comeco = nullptr;
        NoJogador *fim = nullptr;
        int tamanho = 0;

        //Inicializar lista
        bool inicializar(){
            while(comeco != nullptr) {
                NoJogador* temp = comeco;
                comeco = comeco->eloProx;
                delete temp;
            }
            comeco = nullptr;
            fim = nullptr;
            tamanho = 0;
            return true;
        };

        //Inserir na lista (início, posição, fim);
        bool inserir(Jogador jogador,bool ordenar = false){
            NoJogador *nova = new NoJogador;
            
            nova->dados = jogador;
            nova->eloAnt = nullptr;
            nova->eloProx = nullptr;
            
            // Lista vazia
            if(comeco == nullptr){
                comeco = nova;
                fim = nova;
                tamanho += 1;
                return true;
            }

            if(ordenar){

                // Inserção no começo (novo valor é o maior)
                if(jogador.nome > comeco->dados.nome){
                    nova->eloProx = comeco;
                    comeco->eloAnt = nova;
                    comeco = nova;
                    tamanho += 1;
                    return true;
                }

                // Inserção no final (novo valor é o menor)
                if(jogador.nome < fim->dados.nome){
                    fim->eloProx = nova;
                    nova->eloAnt = fim;
                    fim = nova;
                    tamanho += 1;
                    return true;
                }

                // Inserção no meio da lista
                NoJogador *atual = comeco;
                while(atual->eloProx != nullptr && atual->eloProx->dados.nome > jogador.nome){
                    atual = atual->eloProx;
                }
                
                // Insere nova depois de atual
                nova->eloProx = atual->eloProx;
                if (atual->eloProx != nullptr) {
                    atual->eloProx->eloAnt = nova;
                }
                atual->eloProx = nova;
                nova->eloAnt = atual;
                
                tamanho += 1;
                return true;
            }else{
                // Inserção não ordenada (sempre no fim)
                fim->eloProx = nova;
                nova->eloAnt = fim;
                fim = nova;
                tamanho += 1;
                return true;
            }
            return false;
        };

        // Remover da lista (início, posição, fim);
        bool remover(Jogador jogador){
            NoJogador* aux = localizar(jogador);

            if(aux == nullptr){
                return false;
            }

            // Unico elemento
            if(aux == comeco && aux == fim){
                comeco = nullptr;
                fim = nullptr;
                delete aux;
                tamanho -= 1;
                return true;
            }

            // Retirando o primeiro
            if( aux == comeco ){
                comeco = aux->eloProx;
                comeco->eloAnt = nullptr;
                delete aux;
                tamanho -= 1;
                return true;
            }

            NoJogador *ant = aux->eloAnt;
            // Retirando o ultimo
            if( aux == fim ){
                ant->eloProx = nullptr;
                fim = ant;
                delete aux;
                tamanho -= 1;
                return true;
            }
            // Retirando do meio
            NoJogador *prox = aux->eloProx;
            ant->eloProx = prox;
            prox->eloAnt = ant;
            delete aux;
            tamanho -= 1;
            return true;
        };

        //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir);
        Jogador& pegar(int index){
            NoJogador *referencia = comeco;

            //Eveita bugs
            if (index < 0 || index >= tamanho || comeco == nullptr) {
                return comeco->dados;
            }

            if(index == 0){
                return referencia->dados;
            }
            
            for(int i = 0; i < index; i++){
                referencia = referencia->eloProx;
            }

            return referencia->dados;
        };

        //Contém item – recebe o dado e verifica se ele está na lista. Se estiver, retorna verdadeiro e falso caso contrário
        //(foi alterado para retornar o no para ser usado no remover)
        NoJogador* localizar(Jogador jogador){
            NoJogador *aux = comeco;

            while( aux != nullptr ){
                if( aux->dados.nome == jogador.nome){
                    return aux;
                }
                aux = aux->eloProx;
            }
            return nullptr;
        };

        //Descobrir índice – recebe o dado e busca-o na lista. Se estiver na lista, retorna à posição do dado na lista, caso contrário, retorna -1.
        int buscar(Jogador jogador){
            NoJogador* atual = comeco;
            int index = 0;

            //passa por todos os valores para ver se esta la
            while (atual != nullptr) {
                if (atual->dados.nome == jogador.nome) {
                    // Encontrou, retorna o índice
                    return index; 
                }
                atual = atual->eloProx;
                index++;
            }

            // Não encontrou
            return -1; 
        };

        //Imprimir lista
        void imprimir(){
            cout << "Imprimindo cartas do baralho:\n";
            NoJogador* atual = comeco;
            while(atual != nullptr){
                cout << atual->dados.nome << " | ";
                atual = atual->eloProx;
            }
            cout << "\n";
        };
    };
#endif