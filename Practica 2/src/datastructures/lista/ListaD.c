// Hernandez Espinosa Jose Jeronimo
// 2212321
#include <stdio.h>
#include <stdlib.h>
#include "ListaD.h"

NodoD* crearNodoD(void *dato) {
    NodoD *nuevo = (NodoD*)malloc(sizeof(NodoD));
    if (nuevo) {
        nuevo->dato = dato;
        nuevo->ant = NULL;
        nuevo->sig = NULL;
    }
    return nuevo;
}

void imprimirListaFID(ListaD *lista, void (*imprimir)(void*)) {
    if (!lista || !lista->inicio) {
        return; 
    }
    NodoD *aux = lista->fin;
    while (aux != NULL) {
        printf("\n");
        imprimir(aux->dato);
        aux = aux->ant;
    }
}

void insertarInicioD(ListaD *lista, void *dato) {
    NodoD *nuevo = crearNodoD(dato);
    if (!lista->inicio) {
        lista->inicio = lista->fin = nuevo;
    } else {
        nuevo->sig = lista->inicio;
        lista->inicio->ant = nuevo;
        lista->inicio = nuevo;
    }
    lista->cant++;
}

void insertarFinalD(ListaD *lista, void *dato) {
    NodoD *nuevo = crearNodoD(dato);
    if (!lista->inicio) {
        lista->inicio = lista->fin = nuevo;
    } else {
        nuevo->ant = lista->fin;
        lista->fin->sig = nuevo;
        lista->fin = nuevo;
    }
    lista->cant++;
}

void insertarEnPosicionD(ListaD *lista, void *dato, int pos) {
    if (pos <= 0) {
        insertarInicioD(lista, dato);
        return;
    }
    if (pos >= lista->cant) {
        insertarFinalD(lista, dato);
        return;
    }
    
    NodoD *nuevo = crearNodoD(dato);
    NodoD *aux = lista->inicio;
    
    for (int i = 0; i < pos - 1; i++) {
        aux = aux->sig;
    }
    
    nuevo->sig = aux->sig;
    nuevo->ant = aux;
    aux->sig->ant = nuevo;
    aux->sig = nuevo;
    
    lista->cant++;
}

void eliminarPosicionD(ListaD *lista, int pos) {
    if (!lista->inicio || pos < 0 || pos >= lista->cant) return;

    NodoD *temp = lista->inicio;
    for (int i = 0; i < pos; i++) {
        temp = temp->sig;
    }

    if (temp == lista->actual) {
        if (temp->sig) lista->actual = temp->sig;
        else if (lista->bucle) lista->actual = lista->inicio;
        else lista->actual = temp->ant;
        
        if (lista->actual == temp) lista->actual = NULL;
    }

    if (temp->ant) temp->ant->sig = temp->sig;
    else lista->inicio = temp->sig;

    if (temp->sig) temp->sig->ant = temp->ant;
    else lista->fin = temp->ant;

    free(temp);
    lista->cant--;
}