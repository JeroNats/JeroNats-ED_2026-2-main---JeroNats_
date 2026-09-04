#include "Lista.h"

void imprimirLista(void *ptr_lista, void *ptr_imprimir){
	Lista *lista = (Lista *)ptr_lista;
	void (*imprimir)(void*) = (void (*)(void*))ptr_imprimir;
	Nodo *aux;
	if(!lista->inicio){
		printf("\n Lista vacia");
		return;
	}	
	printf("\n [CANT %lu]Lista: \n\n", lista->cant);
	aux = lista->inicio;
	while(aux){
		imprimir(aux->dato);
		printf(" -> ");
		aux = aux->sig;
	}
}

void eliminarLista(void *ptr_lista){
	Lista *lista = (Lista *)ptr_lista;
	if(!lista->inicio) return;
	Nodo *aux;
	while(lista->inicio){
		aux = lista->inicio;
		lista->inicio = lista->inicio->sig;
		free(aux);
	}
	lista->fin = lista->inicio;
	lista->cant = 0;
}

void insertarFinal(void *ptr_lista, void *dato){
	Lista *lista = (Lista *)ptr_lista;
	if(!lista->inicio){
		lista->inicio = lista->fin = crearNodo(dato);
		lista->cant++;
		return;
	}
	lista->fin->sig = crearNodo(dato);
	lista->fin = lista->fin->sig;
	lista->cant++;
}

void eliminarDato(void *ptr_lista, void *dato, void *ptr_comparar){	
	Lista *lista = (Lista *)ptr_lista;
	int (*comparar)(void*, void*) = (int (*)(void*, void*))ptr_comparar;
	if(!lista->inicio) return;
	for(Nodo *ant=NULL, *elim=lista->inicio ; elim ; ant = elim , elim = elim->sig){
		if(comparar(dato, elim->dato) == 0){
			if(lista->inicio == elim) lista->inicio = elim->sig;
			else ant->sig = elim->sig;
			if(lista->fin == elim) lista->fin = ant;
			free(elim);
			lista->cant--;
			return;
		}
	}	
}

int buscarDato(void *ptr_lista, void *dato, void *ptr_comparar){
	Lista *lista = (Lista *)ptr_lista;
	int (*comparar)(void*, void*) = (int (*)(void*, void*))ptr_comparar;
	Nodo *aux;
	if(!lista->inicio) return 0;
	aux = lista->inicio;
	while(aux){
		if(comparar(dato, aux->dato) == 0) return 1;
		aux = aux->sig;
	}
	return 0;
}

void ordenarLista(void *ptr_lista){
	Lista *lista = (Lista *)ptr_lista;
	if(lista->inicio == NULL) return;
	int intercambiado;
	Nodo *actual;
	Nodo *ultimo = NULL;
	do {
		intercambiado = 0;
		actual = lista->inicio;
		while(actual->sig != ultimo){
			if(lista->comparar(actual->dato, actual->sig->dato) > 0){
				void *temp = actual->dato;
				actual->dato = actual->sig->dato;
				actual->sig->dato = temp;
				intercambiado = 1;
			}
			actual = actual->sig;
		}
		ultimo = actual;
	} while(intercambiado);
}

void insertarEnOrden(void *ptr_lista, void *dato){
	Lista *lista = (Lista *)ptr_lista;
	Nodo *nuevo = crearNodo(dato);
	if(!lista->inicio){
		lista->inicio = lista->fin = nuevo;
		lista->cant++;
		return;
	}
	if(lista->comparar(dato, lista->inicio->dato) < 0){
		nuevo->sig = lista->inicio;
		lista->inicio = nuevo;
		lista->cant++;
		return;
	}
	Nodo *actual = lista->inicio;
	while(actual->sig != NULL && lista->comparar(dato, actual->sig->dato) >= 0){
		actual = actual->sig;
	}
	nuevo->sig = actual->sig;
	actual->sig = nuevo;
	if(nuevo->sig == NULL){
		lista->fin = nuevo;
	}
	lista->cant++;
}

