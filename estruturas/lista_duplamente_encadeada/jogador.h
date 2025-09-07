#ifndef L_D_E_JOGADOR_H
#define L_D_E_JOGADOR_H
    #include "baralho.h"
    #include <iostream>
    using namespace std;

    struct Mao{
        NoCarta *comeco = nullptr, *fim = nullptr;
        int tamanho = 0;

        // Inicializar lista
        bool inicializar(){
            NoCarta* atual = comeco;
            while (atual != nullptr) {
                NoCarta* proximo = atual->eloProx;
                delete atual;
                atual = proximo;
            }
            comeco = nullptr;
            fim = nullptr;
            tamanho = 0;
            return true;
        };

        //Inserir na lista
        bool inserir(Carta carta,bool ordenar = false){
            NoCarta *nova = new NoCarta;
            
            nova->dados = carta;
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
                if(carta.numero > comeco->dados.numero){
                    nova->eloProx = comeco;
                    comeco->eloAnt = nova;
                    comeco = nova;
                    tamanho += 1;
                    return true;
                }

                // Inserção no final (novo valor é o menor)
                if(carta.numero < fim->dados.numero){
                    fim->eloProx = nova;
                    nova->eloAnt = fim;
                    fim = nova;
                    tamanho += 1;
                    return true;
                }

                // Inserção no meio da lista
                NoCarta *atual = comeco;
                while(atual->eloProx != nullptr && atual->eloProx->dados.numero > carta.numero){
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

        //Remover da lista
        bool remover(Carta carta){
            NoCarta* aux = localizar(carta);

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

            NoCarta *ant = aux->eloAnt;
            // Retirando o ultimo
            if( aux == fim ){
                ant->eloProx = nullptr;
                fim = ant;
                delete aux;
                tamanho -= 1;
                return true;
            }
            // Retirando do meio
            NoCarta *prox = aux->eloProx;
            ant->eloProx = prox;
            prox->eloAnt = ant;
            delete aux;
            tamanho -= 1;
            return true;
        };        

        //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir)
        Carta& pegar(int index){
            NoCarta *referencia = comeco;

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
        NoCarta* localizar(Carta carta){
            NoCarta *aux = comeco;

            while( aux != nullptr ){
                if( aux->dados.nipe == carta.nipe && aux->dados.numero == carta.numero){
                    return aux;
                }
                aux = aux->eloProx;
            }
            return nullptr;
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
                atual = atual->eloProx;
                index++;
            }

            // Não encontrou
            return -1; 
        };

        //Imprimir lista
        void imprimir(){
            cout << "Imprimindo cartas na mao do jogador:\n";
            NoCarta* atual = comeco;
            while(atual != nullptr){
                cout << atual->dados.label << " | ";
                atual = atual->eloProx;
            }
            cout << "\n";
        };

        //contar
        int contar(){
            return tamanho;
        };

    };

    struct Jogador{
        string nome;
        Mao mao;
    };
#endif
