#ifndef NODO_H
#define NODO_H

// Hernandez Espinosa Jose Jeronimo
// 2212321
#include <stdlib.h>

typedef int (*fn_comparar)(void*,void*);
typedef void (*fn_imprimir)(void*);

typedef enum{
	DESCENDENTE = -1,
	NINGUNO = 0,
	ASCENDENTE = 1	
}Orden;

typedef struct nodo{
	void *dato;
	struct nodo *sig;
}Nodo;

typedef struct nodod{
	void *dato;
	struct nodod *sig;
	struct nodod *ant;
}Nodod;

Nodo* crearNodo(void *dato);
Nodod* crearNodod(void *dato);

void swapNodod(Nodod*,Nodod*);

#endif

