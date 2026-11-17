// Hernandez Espinosa Jose Jeronimo
// 2212321

#ifndef PILA_H
#define PILA_H

#include <stddef.h>
#include "nodo.h"

typedef struct{
    Nodo *cima;
    size_t cant;
}Pila;

Pila *crearPila(); 
void pushPila(Pila *pila, void *dato);
Nodo *popPila(Pila *pila);
void *peekPila(Pila *pila);
void vaciarPila(Pila *pila);

#endif 