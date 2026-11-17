// Hernandez Espinosa Jose Jeronimo
// 2212321
#include <stdlib.h>
#include <stdio.h>
#include "pila.h"
#include "nodo.h"

int verificarPila(Pila *pila){
    if(!pila){
    printf("\nERROR: LA PILA ES INVALIDA");
        return 0;
    }
    return 1;
}

Pila *crearPila(){
    Pila *pilaNueva = (Pila *)malloc(sizeof(Pila));
    if(!pilaNueva){
        printf("\nERROR:AL CREAR LA PILA\n");        
        return NULL;
    }
    pilaNueva->cima = NULL;
    pilaNueva->cant = 0;
    return pilaNueva;
}

void pushPila(Pila *pila, void *dato){
    if(verificarPila(pila) == 0){
        return;
    }

    Nodo *nodoNew = crearNodo(dato);
    
    nodoNew->sig = pila->cima;
    pila->cima = nodoNew;
    pila->cant++;
}

Nodo *popPila(Pila *pila){
    if( verificarPila(pila) == 0 ){
        return NULL;
    }
    if( pila->cima == NULL ){
        printf("\nLa pila ya esta vacia");
        return NULL;
    }

    Nodo *nodoExtraer = NULL;

    nodoExtraer = pila->cima;
    pila->cima = pila->cima->sig;
    pila->cant--;
    nodoExtraer->sig = NULL;
    return nodoExtraer;
}
void *peekPila(Pila *pila){
    if( verificarPila(pila) == 0 ){
        return NULL;
    }
    if( pila->cima == NULL ){
        printf("\nLa pila  esta vacia");
        return NULL;
    }

    void *datoExtraido = pila->cima->dato;
    return datoExtraido;
}
void vaciarPila(Pila *pila){
    if(verificarPila(pila) == 0){
        return;
    }
    while(pila->cima != NULL){
        Nodo *nodoBorrar = popPila(pila);
        free(nodoBorrar);
    }
}