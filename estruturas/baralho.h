#ifndef BARALHO_H
#define BARALHO_H
    #if TIPO_LISTA == 1
        #include "lista_estatica/baralho.h"
    #elif TIPO_LISTA == 2
        #include "lista_encadeada_simples/baralho.h"
    #elif TIPO_LISTA == 3
        #include "lista_duplamente_encadeada/baralho.h"
    #endif
#endif
