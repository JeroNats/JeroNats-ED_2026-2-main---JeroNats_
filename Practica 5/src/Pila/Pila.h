// Hernandez Espinosa Jose Jeronimo
// 2212321

#ifndef PILA_H
#define PILA_H

#include "Nodo.h"

typedef struct NodoPilaAR{
    NodoAR *nodoar;
    struct NodoPilaAR *siguiente;
}NodoPilaAR;

typedef struct{
    NodoPilaAR *cima;
    int cantidad;
}PilaAR;

PilaAR *crearPilaAR();
void pushPilaAR(PilaAR *pilaar, NodoAR *nodoar);
NodoAR *popPilaAR(PilaAR *pilaar);
NodoAR *peekPilaAR(PilaAR *pilaar);

#endif
