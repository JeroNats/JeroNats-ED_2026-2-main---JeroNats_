// Hernandez Espinosa Jose Jeronimo
// 2212321

#include "nodo.h"
#include <stddef.h>

#ifndef PILA_H
#define PILA_H

typedef struct{
    Nodo *cima;
    size_t cant;
}Pila;

Pila *crearPila();
void pushPila(Pila *pila, Nodo *nodoAInsertar);
Nodo *popPila(Pila *pila);
void *peekPila(Pila *pila);
void liberarPila(Pila *pila);

#endif