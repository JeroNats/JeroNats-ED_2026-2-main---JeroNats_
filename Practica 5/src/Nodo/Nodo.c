// Hernandez Espinosa Jose Jeronimo
// 2212321

#include "Nodo.h"
#include <stdlib.h>
#include <stdio.h>

NodoAR *crearNodoAR(){
    NodoAR *nodoar = (NodoAR *)malloc(sizeof(NodoAR));
    if(!nodoar){ printf("\nError: no se pudo crear Nodo tipo Arbol<crearNodoAR>"); return NULL;}

    nodoar->dato = 0;
    nodoar->padre = NULL;
    nodoar->derecha = NULL;
    nodoar->izquierda = NULL;

    return nodoar;
}
