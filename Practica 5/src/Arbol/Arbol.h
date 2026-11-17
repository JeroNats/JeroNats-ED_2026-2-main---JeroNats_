// Hernandez Espinosa Jose Jeronimo
// 2212321

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"

typedef struct{
    NodoAR *raiz;
    int cantidad;
}Arbol;

Arbol *crearArbol();
void insertarEnArbol(Arbol *arbol, NodoAR *nodoar);
void eliminarNodoAR(Arbol *arbol, int dato);
void ordenarArbol(Arbol *arbol);
int alturaIterativa(Arbol *arbol);
void imprimirARIN_Orden(Arbol *arbol);
void imprimirARPre_Orden(Arbol *arbol);
void imprimirARPost_Orden(Arbol *arbol);
void liberarArbol(Arbol *arbol);
void imprimirArbol_Pre_Orden(NodoAR *nodoaraux, int nivel, char tipo);

#endif