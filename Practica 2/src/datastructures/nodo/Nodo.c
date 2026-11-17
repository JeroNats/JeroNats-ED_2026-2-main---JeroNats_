#include "Nodo.h"

Nodo* crearNodo(void *dato){
	Nodo *nuevo = calloc(1,sizeof(Nodo));
	nuevo->dato = dato;
	return nuevo;
}

Nodod* crearNodod(void *dato){
	Nodod *nuevo = calloc(1,sizeof(Nodod));
	nuevo->dato = dato;
	return nuevo;
}

void swapNodod(Nodod*,Nodod*){
	return;
}
