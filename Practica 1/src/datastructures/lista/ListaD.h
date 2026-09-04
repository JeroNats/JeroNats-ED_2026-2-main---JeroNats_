#ifndef LISTAD_H
#define LISTAD_H

// Hernandez Espinosa Jose Jeronimo
// 2212321
#include <stdio.h>
#include <stdlib.h>
#include <Nodo.h>

typedef struct{
	Nodo *inicio;
	Nodo *fin;
	size_t cant;
	Orden orden;
	fn_comparar comparar;
}ListaD;

void imprimirLista(void*, void*);
void eliminarLista(void*);
void insertarFinal(void*, void*);
void eliminarDato(void*, void*, void*);
int buscarDato(void*, void*, void*);
void insertarEnOrden(void*, void*);
void ordenarLista(void*);

#endif