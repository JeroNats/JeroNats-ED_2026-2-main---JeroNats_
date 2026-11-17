// Hernandez Espinosa Jose Jeronimo
// 2212321

#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"

Nodo *crearNodo(void *dato){
    if(!dato){
        printf("\nERROR: AL INSERTAR EL DATO\n");
        return NULL;
    }
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    if(!nuevoNodo){
        printf("\nERROR: AL CREAR NODO\n");
    }
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}
