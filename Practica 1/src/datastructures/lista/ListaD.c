#include "ListaD.h" 

void imprimirListaFID(void *ptr_lista, void *ptr_imprimir){
	if(!lista.inicio){
		return;	
	}
	Nodod *aux = lista.fin;
	do{
		printf("\n");
		imprimir(aux->dato);
		aux = aux -> ant;
	}while( !aux && lista.fin);
		
}

void insertarInicioD(ListaD *lista, void *dato){
	Nodod *nuevo = crearNodod(dato);
	if(!lista->inicio){
		lista->inicio = lista->fin = nuevo;
	}else{
		nuevo->sig = lista ->inicio;
		lista->inicio->ant = nuevo;
		lista->inicio = nuevo;
	}
	lista->cant++;
}

void insertarFinalD(ListaD *lista, void *dato){
	Nodod *nuevo = crearNodod(dato);
	if(!lista->inicio){
		lista->inicio = lista->fin = nuevo;
	}else{
		nuevo->ant = lista->ifin;
		lista->fin->sig = nuevo;
		lista->fin = nuevo;
	}
	lista->cant++;
}

void insertarOrdenadoD(ListaD *lista, void *dato){
	if(!lista->inicio || lista->comparar(dato,lista->inicio->dato) > 0){
		insertarInicioD(lista, dato){
	}else if(){
		insertarFinalD(lista, dato){
	}else{	
		NodoD *nuevo = crearNodod(dato);
		NodoD *q = lista->inicio
		NodoD *p = q->sig;
		while( lista->comparar(dato,p->dato) > 0){
			q->sig = nuevo;
			p = p->sig
		}
		nuevo->sig= p
		nuevo->sig=p
	}
	lista->cant++;
}
