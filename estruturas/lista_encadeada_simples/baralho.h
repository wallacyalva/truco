#ifndef L_E_S_BARALHO_H
#define L_E_S_BARALHO_H
    #include "carta.h"
    #include <iostream>
    #include <string>
    using namespace std;
    
    struct NoCarta {
        Carta dados;
        NoCarta* elo = nullptr;
    };

    struct Baralho{
        NoCarta *comeco = nullptr, *fim = nullptr;
        int tamanho = 0;
        
        //Inicializar lista
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
            while(referencia != nullptr && (carta.numero != referencia->dados.numero || carta.nipe != referencia->dados.nipe)){
                anterior = referencia;
                referencia = referencia->elo;
            }

            // Elemento não encontrado
            if(referencia == nullptr) {
                return false;
            };

            // Removendo o primeiro
            if(referencia == comeco){
                comeco = referencia->elo;
            } 
            // Removendo do meio ou fim
            else{
                anterior->elo = referencia->elo;
            }
            
            // Se removeu o último, atualiza o ponteiro
            if(referencia == fim){ 
                fim = anterior;
            }

            delete referencia;
            tamanho--;
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
            // Não é possível embaralhar 0 ou 1 carta
            if (tamanho < 2) {
                return;
            }

            NoCarta* baralhoEmbaralhado = nullptr; // O início da nova lista
            int contagemAtual = tamanho;

            // Loop que executa 'tamanho' vezes: a cada iteração, um nó aleatório
            // da lista original é movido para a nova lista embaralhada.
            for (int i = 0; i < tamanho; i++) {
                // 1. Escolhe uma posição aleatória na lista original restante
                int posAleatoria = rand() % contagemAtual;

                // 2. Encontra e remove o nó dessa posição
                NoCarta* anterior = nullptr;
                NoCarta* atual = comeco;
                for (int j = 0; j < posAleatoria; j++) {
                    anterior = atual;
                    atual = atual->elo;
                }

                // Desconecta o nó da lista original
                if (anterior == nullptr) { // Se for o primeiro elemento
                    comeco = atual->elo;
                } else {
                    anterior->elo = atual->elo;
                }

                // 3. Insere o nó removido no início da nova lista
                atual->elo = baralhoEmbaralhado;
                baralhoEmbaralhado = atual;

                contagemAtual--; // Diminui o contador para a próxima iteração
            }

            // 4. A nova lista embaralhada torna-se a lista oficial do baralho
            this->comeco = baralhoEmbaralhado;

            // 5. Reconstrói o ponteiro 'fim', pois não sabemos qual é o último nó
            if (this->comeco != nullptr) {
                NoCarta* noAtual = this->comeco;
                while (noAtual->elo != nullptr) {
                    noAtual = noAtual->elo;
                }
                this->fim = noAtual;
            } else {
                this->fim = nullptr; // A lista está vazia
            }
        };

    };
#endif