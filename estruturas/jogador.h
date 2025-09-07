#ifndef JOGADOR_H
#define JOGADOR_H
    #if TIPO_LISTA == 1
        #include "lista_estatica/jogador.h"
    #elif TIPO_LISTA == 2
        #include "lista_encadeada_simples/jogador.h"
    #elif TIPO_LISTA == 3
        #include "lista_duplamente_encadeada/jogador.h"
    #endif
#endif