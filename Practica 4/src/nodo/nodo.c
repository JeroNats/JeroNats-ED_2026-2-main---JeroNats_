// Hernandez Espinosa Jose Jeronimo
// 2212321

#include <stdlib.h>
#include <stdio.h>
#include "nodo.h"

Nodo *newNodo(void *dato){
    if(!dato){ printf("\nDato invalido"); return NULL; }

    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
 
    if(!nuevoNodo){ printf("\nEl nodo no se pudo crear correctamente"); return NULL; }

    nuevoNodo->dato = dato;  
    nuevoNodo->sig = NULL;

    return nuevoNodo;
}