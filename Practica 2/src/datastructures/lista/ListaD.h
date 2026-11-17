// Hernandez Espinosa Jose Jeronimo
// 2212321
#ifndef LISTAD_H
#define LISTAD_H

#include <stdlib.h>
#include <stdio.h>

typedef struct NodoD {
    void *dato;
    struct NodoD *ant;
    struct NodoD *sig;
} NodoD;

typedef struct {
    NodoD *inicio;
    NodoD *fin;
    NodoD *actual;  
    int bucle;      
    int cant;
    int (*comparar)(void*, void*);
} ListaD;

NodoD* crearNodoD(void *dato);
void imprimirListaFID(ListaD *lista, void (*imprimir)(void*));
void insertarInicioD(ListaD *lista, void *dato);
void insertarFinalD(ListaD *lista, void *dato);
void insertarEnPosicionD(ListaD *lista, void *dato, int pos);
void eliminarPosicionD(ListaD *lista, int pos);

#endif