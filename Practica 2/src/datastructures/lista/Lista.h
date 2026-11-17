#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <Nodo.h>

typedef struct{
	Nodo *inicio;
	Nodo *fin;
	size_t cant;
	Orden orden;
	int (*comparar)(void*, void*);
}Lista;

void imprimirLista(void*, void*);
void eliminarLista(void*);
void insertarFinal(void*, void*);
void eliminarDato(void*, void*, void*);
int buscarDato(void*, void*, void*);
void insertarEnOrden(void*, void*);
void ordenarLista(void*);

#endif