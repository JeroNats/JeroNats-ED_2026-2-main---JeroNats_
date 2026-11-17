// Hernandez Espinosa Jose Jeronimo
// 2212321

#include "Arbol.h"
#include "Pila.h"
#include <stdlib.h>
#include <stdio.h>

Arbol *crearArbol(){
    Arbol *arbol = (Arbol *)malloc(sizeof(Arbol));
    if(!arbol){ printf("\nError: no se pudo crear Arbol<crearArbol>"); return NULL;}

    arbol->raiz = NULL;
    arbol->cantidad = 0;

    return arbol;
}
void insertarEnArbol(Arbol *arbol, NodoAR *nodoar){
    if(!arbol){ printf("\nError: el Arbol ingresado es invalido <insertarEnArbol>"); return;}
    else if(!nodoar){ printf("\nError: el NodoAR ingresado es invalido <insertarEnArbol>"); return;}

    if(arbol->raiz == NULL){
        arbol->raiz = nodoar;
        arbol->cantidad++;
        return;
    }else{
        NodoAR *auxiliar = arbol->raiz;
        NodoAR *anterior = NULL;

        while(auxiliar != NULL){
            anterior = auxiliar;
            if( nodoar->dato < auxiliar->dato ){
                auxiliar = auxiliar->izquierda;
            }else{
                auxiliar = auxiliar->derecha;
            }
        }

        nodoar->padre = anterior;

        if( nodoar->dato < anterior->dato ){ 
            anterior->izquierda = nodoar;
        }else{
            anterior->derecha = nodoar;        
        }

        arbol->cantidad++;
    }
}
void eliminarNodoAR(Arbol *arbol, int dato){
    NodoAR *actual = arbol->raiz;
    if(!actual){ printf("\nError: La Raiz de Arbol ingresado es invalido <eliminarNodoAR>"); return;}
    if(actual == NULL){ printf("\nLa Raiz del Arbol ingresado esta vacia <eliminarNodoAR>"); return;}

    while(actual != NULL){
        if(actual->dato == dato){
            break;
        }else if(dato < actual->dato){
            actual = actual->izquierda;
        }else{
            actual = actual->derecha;
        }
    }
    // Es una Hoja (No tiene hijos)
    if(actual->izquierda == NULL && actual->derecha == NULL){
        if(actual == arbol->raiz){
            arbol->raiz = NULL;
        }else{
            if(actual->padre->izquierda == actual){
            actual->padre->izquierda = NULL;        
            }else{
            actual->padre->derecha = NULL;
            }
        }
        free(actual);
    // Tiene los dos hijos vivos  
    }else if( actual->izquierda != NULL && actual->derecha != NULL ){
        NodoAR *reemplazo = actual->derecha;
        while(reemplazo->izquierda != NULL){
            reemplazo = reemplazo->izquierda;
        }
        actual->dato = reemplazo->dato;
        NodoAR *hijodeReemplazo = reemplazo->derecha;
        if(reemplazo->padre == actual){
            reemplazo->padre->derecha = hijodeReemplazo;
        }else{
            reemplazo->padre->izquierda = hijodeReemplazo;
        }
        if(hijodeReemplazo != NULL){
            hijodeReemplazo->padre = reemplazo->padre;
        }
        free(reemplazo);
    // Tiene un hijo izquierdo    
    }else if( actual->izquierda != NULL && actual->derecha == NULL ){
        // Si actual es la raiz del arbol
        if(actual == arbol->raiz){
            // La raiz se vuelve el hijo izquierdo 
            arbol->raiz = actual->izquierda;
            // Hacemos que la nueva raiz se vuelva huerfana
            arbol->raiz->padre = NULL;
        }else{
            /* En otro caso, hacemos primero que el padre del hijo izquierdo
            su padre ahora sea el abuelo*/
            actual->izquierda->padre = actual->padre;
            /* Despues comparamos para saber si actual era el hijo derecho
            o izquierdo del abuelo */
            if(actual == actual->padre->izquierda ){
                /* Si era el hijo izquierdo, hacemos que el hijo izquierdo
                del abuelo sea el hijo izquierdo del padre */
                actual->padre->izquierda = actual->izquierda;
            }else{
                /* Si era el hijo derecho, hacemos que el hijo derecho
                del abuelo sea el hijo izquierdo del padre */
               actual->padre->derecha = actual->izquierda;
            }
        }
        free(actual);
    // Tiene un hijo derecho
    }else if( actual->izquierda == NULL && actual->derecha != NULL ){
        // Si actual es la raiz del arbol
        if(actual == arbol->raiz){
            // La raiz se vuelve el hijo izquierdo 
            arbol->raiz = actual->derecha;
            // Hacemos que la nueva raiz se vuelva huerfana
            arbol->raiz->padre = NULL;
        }else{
            /* En otro caso, hacemos primero que el padre del hijo izquierdo
            su padre ahora sea el abuelo*/
            actual->derecha->padre = actual->padre;
            /* Despues comparamos para saber si actual era el hijo derecho
            o izquierdo del abuelo */
            if(actual == actual->padre->izquierda ){
                /* Si era el hijo izquierdo, hacemos que el hijo izquierdo
                del abuelo sea el hijo izquierdo del padre */
                actual->padre->izquierda = actual->derecha;
            }else{
                /* Si era el hijo derecho, hacemos que el hijo derecho
                del abuelo sea el hijo izquierdo del padre */
               actual->padre->derecha = actual->derecha;
            }
        }
        free(actual);
    }
    arbol->cantidad--;
}
void ordenarArbol(Arbol *arbol){
    if(!arbol){ printf("\nError: El Arbol es invalido <ordenarArbol>"); return;}
    if(arbol->raiz == NULL){ printf("\nLa Raiz del Arbol esta vacia"); return;}

    Arbol arbol_raiz_derecha = {0};
    Arbol arbol_raiz_izquierda = {0};
    arbol_raiz_derecha.raiz = arbol->raiz->derecha;
    arbol_raiz_izquierda.raiz = arbol->raiz->izquierda;
    int Hd = 0;
    int Hi = 0;
    int B = 0;

    Hd = alturaIterativa(&arbol_raiz_derecha);
    Hi = alturaIterativa(&arbol_raiz_izquierda);
    B = Hd - Hi;

    if( B >= -1 && B <= 1 ){ printf("\nEl Arbol ya esta equilibrado"); return;}
    int *arbolarray = (int *)malloc(sizeof(int) * arbol->cantidad);
    int i= 0;

    PilaAR *pila = crearPilaAR();
    NodoAR *actual = arbol->raiz;

    while(actual != NULL || pila->cantidad > 0){
        if(actual != NULL){
            pushPilaAR(pila, actual);
            actual = actual->izquierda;
        }else{
            NodoAR *nodoARAUX = popPilaAR(pila);
            arbolarray[i] = nodoARAUX->dato;
            i++;
            actual = nodoARAUX->derecha;
        }
    }

    actual = arbol->raiz;
    NodoAR *ultimoVisitado = NULL;

    while(actual != NULL || pila->cantidad > 0){
        if(actual != NULL){
            pushPilaAR(pila, actual);
            actual = actual->izquierda;
        }else{
            NodoAR *padre = peekPilaAR(pila);
            if( padre->derecha != NULL && ultimoVisitado != padre->derecha){
                actual = padre->derecha;
            }else{
                ultimoVisitado = popPilaAR(pila);
                free(ultimoVisitado);
            }
        }
    }

    arbol->raiz = NULL;
    int cantidadDeNodos = arbol->cantidad;
    arbol->cantidad =0;
    int pilaInicio[cantidadDeNodos];
    int pilaFin[cantidadDeNodos];
    int tope = 0;
    
    pilaInicio[0] = 0;
    pilaFin[0] = cantidadDeNodos-1;
    tope++;

    while( tope > 0 ){
        tope--;
        int limiteActualInicio = pilaInicio[tope];
        int limiteActualFin = pilaFin[tope];
        if(limiteActualInicio <= limiteActualFin){
            NodoAR *nodoInsertarAR = crearNodoAR();
            int mitad = (( limiteActualInicio + limiteActualFin )/2);
            nodoInsertarAR->dato = arbolarray[mitad];
            insertarEnArbol(arbol, nodoInsertarAR);

            if(mitad + 1 <= limiteActualFin){
                pilaInicio[tope] = mitad + 1;
                pilaFin[tope] = limiteActualFin;
                tope++;
            }
            if(limiteActualInicio <= mitad - 1){
                pilaInicio[tope] = limiteActualInicio;
                pilaFin[tope] = mitad - 1;
                tope++;
            }
        }
    }
    free(arbolarray);
    free(pila);
}
int alturaIterativa(Arbol *arbol){
    if(!arbol){ printf("\nError: El Arbol es invalido <alturaIterativa>"); return 0;}
    if(arbol->raiz == NULL){ return 0;}
    NodoAR *actual = arbol->raiz;
    NodoAR *ultimoVisitado = NULL;
    PilaAR *pila = crearPilaAR();
    int alturaMaxima = 0;

    while(actual != NULL || pila->cantidad > 0){
        if(actual != NULL){
            //Lo guarda en la pila el actual
            pushPilaAR(pila, actual);
            if(pila->cantidad > alturaMaxima){
                alturaMaxima = pila->cantidad; 
            }
            // Actual se vuelve su hijo izquierdo y volvemos al while
            actual = actual->izquierda;
        }else{
            // Hacemos que el padre sea el que esta en la cima en ese momento
            NodoAR *padre = peekPilaAR(pila);
            // Preguntamos, el hijo derecho de padre es diferente de nulo y diferente de ultimo visitado?
            if(padre->derecha != NULL && ultimoVisitado != padre->derecha){
                // si es asi, volvemos el actual al hijo derecho
                actual = padre->derecha;
            }else{
                /* si no, SACAMOS, NO VER, a la cima, volviendose la cima el siguiente de su pila
                y la cima que sacamos la volvemos la referencia de lo ultimo que visitamos */
                ultimoVisitado = popPilaAR(pila);
            }
        }
    }
    free(pila);
    return alturaMaxima;
}
void imprimirARIN_Orden(Arbol *arbol){
    PilaAR *pila = crearPilaAR();
    NodoAR *actual = arbol->raiz;

    while(actual != NULL || pila->cantidad > 0){
        if(actual != NULL){
            //Lo guarda en la pila el actual
            pushPilaAR(pila, actual);
            // Actual se vuelve su hijo izquierdo y volvemos al while
            actual = actual->izquierda;
        }else{
            // Sacamos el nodo que esta en la cima
            actual = popPilaAR(pila);
            //imprimimos su dato
            printf("%i, ", actual->dato);
            // Hacemos que actual se vuelva su hijo derecho
            actual = actual->derecha;
        }
    }
    free(pila);
}
void imprimirARPre_Orden(Arbol *arbol){
    PilaAR *pila = crearPilaAR();
    NodoAR *actual = arbol->raiz;
    NodoAR *ultimov = NULL;

    while(actual != NULL || pila->cantidad > 0){
        if(actual != NULL){
            // Imprimimos el valor de actual
            printf("%i, ", actual->dato);
            //Lo guarda en la pila el actual
            pushPilaAR(pila, actual);
            // Actual se vuelve su hijo izquierdo y volvemos al while
            actual = actual->izquierda;
        }else{
            // Hacemos que el padre sea el que esta en la cima en ese momento
            NodoAR *padre = peekPilaAR(pila);

            // Preguntamos, el hijo derecho de padre es diferente de nulo y diferente de ultimo visitado?
            if(padre->derecha != NULL && ultimov != padre->derecha){
                // si es asi, volvemos el actual al hijo derecho
                actual = padre->derecha;
            }else{
                /* si no, SACAMOS, NO VER, a la cima, volviendose la cima el siguiente de su pila
                y la cima que sacamos la volvemos la referencia de lo ultimo que visitamos*/
                ultimov = popPilaAR(pila);
            }
        }
    }
    free(pila);
}
void imprimirARPost_Orden(Arbol *arbol){
    PilaAR *pila = crearPilaAR();
    NodoAR *actual = arbol->raiz;
    NodoAR *ultimov = NULL;

    while(actual != NULL || pila->cantidad > 0){
        if(actual != NULL){
            //Lo guarda en la pila el actual
            pushPilaAR(pila, actual);
            // Actual se vuelve su hijo izquierdo y volvemos al while
            actual = actual->izquierda;
        }else{
            // Hacemos que el padre sea el que esta en la cima en ese momento
            NodoAR *padre = peekPilaAR(pila);
            // Preguntamos, el hijo derecho de padre es diferente de nulo y diferente de ultimo visitado?
            if(padre->derecha != NULL && ultimov != padre->derecha){
                // si es asi, volvemos el actual al hijo derecho
                actual = padre->derecha;
            }else{
                /* si no, SACAMOS, NO VER, a la cima, volviendose la cima el siguiente de su pila
                y la cima que sacamos la volvemos la referencia de lo ultimo que visitamos e 
                Imprimimos el valor de actual */
                printf("%i, ", actual->dato);                
                ultimov = popPilaAR(pila);
            }
        }
    }
    free(pila);
}
void liberarArbol(Arbol *arbol){
    PilaAR *pila = crearPilaAR();
    NodoAR *actual = arbol->raiz;
    NodoAR *ultimov = NULL;

    while(actual != NULL || pila->cantidad > 0){
        if(actual != NULL){
            pushPilaAR(pila, actual);
            actual = actual->izquierda;
        }else{
            NodoAR *padre = peekPilaAR(pila);
            if(padre->derecha != NULL && ultimov != padre->derecha){
                actual = padre->derecha;
            }else{    
                ultimov = popPilaAR(pila);
                free(ultimov);
            }
        }
    }
    arbol->raiz = NULL;
    arbol->cantidad = 0;
    free(pila);
}        
void imprimirArbol_Pre_Orden(NodoAR *nodoaraux, int nivel, char tipo){
    if(nodoaraux == NULL){ return; }
    if(tipo == 'r'){
        printf("%i Raiz\n", nodoaraux->dato);
    }else{
        for( int i = 1 ; i < nivel ; i++){
            printf("|   ");
        }
        printf("|___%c %i\n", tipo, nodoaraux->dato);
    }    
    imprimirArbol_Pre_Orden(nodoaraux->izquierda, nivel+1, 'I');
    imprimirArbol_Pre_Orden(nodoaraux->derecha, nivel+1, 'D');
}