// Hernandez Espinosa Jose Jeronimo
// 2212321

#include "Pila.h"
#include <stdlib.h>
#include <stdio.h>

PilaAR *crearPilaAR(){
    PilaAR *pilaar = (PilaAR *)malloc(sizeof(PilaAR));
    if(!pilaar){ printf("\nError: no se pudo crear la Pila tipo Arbol <crearPilaAR>"); return NULL;}

    pilaar->cima = NULL;
    pilaar->cantidad = 0;

    return pilaar;
}
void pushPilaAR(PilaAR *pilaar, NodoAR *nodoar){
    if(!pilaar){ printf("\nError: La Pila tipo Arbol es invalida <pushPilaAR>"); return;}
    else if(!nodoar){ printf("\nError: El Nodo tipo Arbol que se quiso pushear es invalida <pushPilaAR>"); return;}

    NodoPilaAR *nodopilaar = (NodoPilaAR *)malloc(sizeof(NodoPilaAR));

    nodopilaar->nodoar = nodoar;
    nodopilaar->siguiente = pilaar->cima;

    pilaar->cima = nodopilaar;
    pilaar->cantidad++;
}
NodoAR *popPilaAR(PilaAR *pilaar){
    if(!pilaar){ printf("\nError: La Pila tipo Arbol es invalida <popPilaAR>"); return NULL;}

    NodoPilaAR *auxPAR = pilaar->cima;
    NodoAR *auxNAR = auxPAR->nodoar;

    pilaar->cima = pilaar->cima->siguiente;
    free(auxPAR);
    pilaar->cantidad--;

    return auxNAR;
}
NodoAR *peekPilaAR(PilaAR *pilaar){
    if(!pilaar){ printf("\nError: La Pila tipo Arbol es invalida <popPilaAR>"); return NULL;}

    NodoPilaAR *auxPAR = pilaar->cima;
    NodoAR *auxNAR = auxPAR->nodoar;

    return auxNAR;
}