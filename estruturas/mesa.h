#ifndef MESA_H
#define MESA_H
    #if TIPO_LISTA == 1
        #include "lista_estatica/mesa.h"
    #elif TIPO_LISTA == 2
        #include "lista_encadeada_simples/mesa.h"
    #elif TIPO_LISTA == 3
        #include "lista_duplamente_encadeada/mesa.h"
    #endif
#endif