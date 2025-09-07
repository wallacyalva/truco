#ifndef L_E_S_JOGADOR_H
#define L_E_S_JOGADOR_H
    #include "baralho.h"
    #include <iostream>
    using namespace std;

    struct Mao{
        NoCarta *comeco = nullptr, *fim = nullptr;
        int tamanho = 0;

        //Inicializar lista
        bool inicializar(){
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
        
        //Inserir na lista (início, posição, fim);
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
                    tamanho += 1;
                    return true;
                }
    
                if(carta.numero < comeco->dados.numero){ // Inser��o no come�o
                    nova->elo = comeco;
                    comeco = nova;
                    tamanho += 1;
                    return true;
                }
    
                if(carta.numero > fim->dados.numero){ // Inser��o no final
                    fim->elo = nova;
                    fim = nova;
                    tamanho += 1;
                    return true;
                }
    
                // Inser��o no meio da lista
                NoCarta *ant = comeco;
                NoCarta *prox = ant->elo;
                
                while(prox != nullptr){
                    if(ant->dados.numero < carta.numero && carta.numero < prox->dados.numero){
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
        bool remover(Carta carta){
            NoCarta *anterior = nullptr, *referencia = comeco;
            
            // Busca elemento
            while(referencia != nullptr && (referencia->dados.numero != carta.numero || referencia->dados.nipe != carta.nipe)){
                anterior = referencia;
                referencia = referencia->elo;
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
        
        //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir)
        Carta& pegar(int index){
            // evitar bug de informar index invalido
            if (index < 0 || index >= tamanho || comeco == nullptr) {
                return comeco->dados;
            }

            NoCarta *referencia = comeco;

            for(int i = 0; i < index; i++){
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
            cout << "Imprimindo cartas da mao:\n";
            NoCarta* atual = comeco;
            while(atual != nullptr){
                cout << atual->dados.label << " | ";
                atual = atual->elo;
            }
            cout << endl;
        };

        //Contar itens da lista
        int contar(){
            return tamanho;
        };

    };

    struct Jogador{
        string nome;
        Mao mao;
    };
#endif
