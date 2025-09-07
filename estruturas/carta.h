#ifndef CARTA_H
#define CARTA_H
    #if TIPO_LISTA == 1
        #include "lista_estatica/carta.h"
    #elif TIPO_LISTA == 2
        #include "lista_encadeada_simples/carta.h"
    #elif TIPO_LISTA == 3
        #include "lista_duplamente_encadeada/carta.h"
    #endif

#endif