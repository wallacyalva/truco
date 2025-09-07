#ifndef L_D_E_CARTA_H
#define L_D_E_CARTA_H
    #include <string>
    using namespace std;

    struct Carta {
        int nipe;
        int numero;
        string label;

        //Gera o nome da carta de acordo com as informacoes
        string gerarLabel(){
            switch (numero){
                case 1:
                    label = "Ás (1)";
                break;
                case 8:
                    label = "Dama (Q)";
                break;
                case 9:
                    label = "Valete (J)";
                break;
                case 10:
                    label = "Rei (K)";
                break;
                default:
                    label = to_string(numero);
                break;
            }

            switch (nipe){
                case 0:
                    label += " de ouro ♦️";
                break;
                case 1:
                    label += " de espadas ♠️";
                break;
                case 2:
                    label += " de copas ♥️";
                break;
                case 3:
                    label += " de paus ♣️";
                break;
            }

            return label;
        }
    };
#endif
