// Hernandez Espinosa Jose Jeronimo
// 2212321

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "pila.h"
#include "nodo.h"

Pila *crearPila(){
    Pila *newPila = (Pila *)malloc(sizeof(Pila));
    if(!newPila){ printf("\nError al crear la nueva pila\n"); return NULL; }

    newPila->cima = NULL;
    newPila->cant = 0;

    return newPila;
}
void pushPila(Pila *pila, Nodo *nodoAInsertar){
    if(!pila){ printf("\nError: la Pila es invalida\n"); return; }
    if(!nodoAInsertar){ printf("\nError: el Nodo a insertar no es valido\n"); return; }

    nodoAInsertar->sig = pila->cima;
    pila->cima = nodoAInsertar;
    pila->cant++;
    
    printf("\nNodo insertado correctamente en la Cima, ahora hay %i de nodos en la Pila\n", (int)pila->cant);
}

Nodo *popPila(Pila *pila){
    if(!pila){ printf("\nError: la pila es invalida"); return NULL; }
    if(pila->cima == NULL){ printf("\nLa Pila ya esta vacia"); return NULL; }
 
    Nodo *nodoAExtraer;
    nodoAExtraer = pila->cima;
    pila->cima = pila->cima->sig;
    pila->cant--;

    return nodoAExtraer;
}

void *peekPila(Pila *pila){
    if(!pila){ printf("\nError: la pila es invalida"); return NULL; }
    if(pila->cima == NULL){ printf("\nLa Pila esta vacia"); return NULL; }

    void *datoExtraido = pila->cima->dato;
    return datoExtraido;
}
void liberarPila(Pila *pila){
    if(!pila){ printf("\nError: la pila es invalida"); return; }
    if(pila->cima == NULL){ printf("\nLa Pila esta vacia"); return; }
    while(peekPila(pila) != NULL){
        Nodo *aux = popPila(pila);
        free(aux);
    }
}