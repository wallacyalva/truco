#ifndef L_D_E_BARALHO_H
#define L_D_E_BARALHO_H
    #include "carta.h"
    #include <iostream>
    #include <string>
    using namespace std;
    
    struct NoCarta {
        Carta dados;
        NoCarta* eloAnt = nullptr;
        NoCarta* eloProx = nullptr;
    };

    struct Baralho{
        NoCarta *comeco = nullptr;
        NoCarta *fim = nullptr;
        int tamanho = 0;

        // Inicializar lista
        bool iniciar(){
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

            if(ordenar){
                
                if(comeco == nullptr){ // Lista vazia
                    comeco = nova;
                    fim = nova;
                    return true;
                }
                
                if(carta.numero > comeco->dados.numero){ // Inser��o no come�o
                    nova->eloProx = comeco;
                    comeco->eloAnt = nova;
                    comeco = nova;
                    return true;
                }

                if(carta.numero < fim->dados.numero){ // Inser��o no final
                    fim->eloProx = nova;
                    nova->eloAnt = fim;
                    fim = nova;
                    return true;
                }

                // Inser��o no meio da lista
                NoCarta *ant = comeco;
                NoCarta *prox = ant->eloProx;
                while(prox != nullptr){
                    if(ant->dados.numero > carta.numero && carta.numero > prox->dados.numero){
                        ant->eloProx = nova;
                        nova->eloAnt = ant;
                        prox->eloAnt = nova;
                        nova->eloProx = prox;
                        return true;
                    }
                    ant = prox;
                    prox = ant->eloProx;
                }
            }else{
                if(comeco == nullptr){ // Lista est� vazia
                    comeco = nova;
                    fim = nova;
                }else{
                    fim->eloAnt = nova;
                    nova->eloProx = fim;
                    fim = nova;
                }

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
                return true;
            }
            // Retirando o primeiro
            if( aux == comeco ){
                comeco = aux->eloProx;
                comeco->eloAnt = nullptr;
                delete aux;
                return true;
            }

            NoCarta *ant = aux->eloAnt;
            // Retirando o ultimo
            if( aux == fim ){
                ant->eloProx = nullptr;
                fim = ant;
                delete aux;
                return true;
            }
            // Retirando do meio
            NoCarta *prox = aux->eloProx;
            ant->eloProx = prox;
            prox->eloAnt = ant;
            delete aux;
            return true;
        };
        
        //Obter item da lista – recebe a posição como parâmetro e retorna o dado daquela posição (se existir)
        Carta& pegar(int index){
            NoCarta *referencia = comeco;
            if(index == 0){
                return referencia->dados;
            }
            
            int indexReferencia = 0;

            while(indexReferencia != index){
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
            cout << "Imprimindo cartas do baralho:\n";
            NoCarta* atual = comeco;
            while(atual != nullptr){
                cout << atual->dados.label << " | ";
                atual = atual->eloProx;
            }
            cout << "\n";
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
                        atual = atual->eloProx;
                    }
    
                    //nó da lista original
                    if (anterior == nullptr) { 
                        //primeiro elemento
                        comeco = atual->eloProx;
                    } else {
                        anterior->eloProx = atual->eloProx;
                    }
    
                    //nó removido ao final da nova lista embaralhada
                    atual->eloProx = nullptr; // Isola o nó
                    if (referenciaComeco == nullptr) { 
                        // Nova lista está vazia
                        referenciaComeco = atual;
                        referenciaFim = atual;
                    } else {
                        referenciaFim->eloProx = atual;
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