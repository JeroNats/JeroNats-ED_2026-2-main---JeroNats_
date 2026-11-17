// Hernandez Espinosa Jose Jeronimo
// 2212321

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "nodo.h"
#include "pila.h"
#include "laberinto.h"
#define MORADO "\033[35m" 
#define DEFAULTT "\033[0m"

Pila *resolverLab(Laberinto lab, Coordenada *origen, Coordenada *destino);

int main(void){
    Laberinto lab = crearLaberinto();
    Coordenada *origen = crearCoordenada(1,1);
    Coordenada *destino = crearCoordenada(25,24);    
    int nuevasCoord = 0;

    printf(MORADO "\nDeseas cambiar las coordenadas de A y B?");
    scanf("%i", &nuevasCoord);
    if(nuevasCoord == 1){
        printf("\nCoordenadas de A:\nPosicion X?");
        scanf("%i", &origen->x);
        printf("\nPosicion Y?");
        scanf("%i", &origen->y);
        printf("\nCoordenadas de B:\nPosicion X?");
        scanf("%i", &destino->x);
        printf("\nPosicion Y?");
        scanf("%i", &destino->y);
    }
    moverA(lab, origen);
    moverB(lab, destino);

    Pila *pilaLab = resolverLab(lab, origen, destino);

    if(peekPila(pilaLab) == NULL){
        printf("\nNo llego a un camino posible");
    }else{
        printf("\nLaberinto resuelto");
    }

	freeLaberinto(lab);
    liberarPila(pilaLab);    
    free(pilaLab);

    return 0;
}

Pila *resolverLab(Laberinto lab, Coordenada *origen, Coordenada *destino){
    Pila *pilaLab = crearPila();
    Coordenada *inicio = crearCoordenada(origen->x,origen->y);
    Nodo *nodoInicio = newNodo(inicio);
    pushPila(pilaLab, nodoInicio);

    while(peekPila(pilaLab) != NULL){
        printf("\nPresiona enter para continuar. . . .");
        getchar();
        imprimirLaberinto(lab);
        Coordenada *actual = peekPila(pilaLab);
        if(lab[actual->x][actual->y] == 'B'){
            break;
        } 
        Movimientos movPos = revisarMovimientos(lab,*actual);
        if( sinCaminos(movPos) == 1 ){
            lab[actual->x][actual->y] = 'x';
            Nodo *borrar = popPila(pilaLab); 
            free(borrar);
        }else{
            if(movPos.arriba == 1){
                lab[actual->x][actual->y] = '.';
                actual = crearCoordenada(actual->x-1,actual->y);
                Nodo *nodoAInsertar = newNodo(actual);                
                pushPila(pilaLab,nodoAInsertar);
            }else if(movPos.abajo == 1){
                lab[actual->x][actual->y] = '.';
                actual = crearCoordenada(actual->x+1,actual->y);
                Nodo *nodoAInsertar = newNodo(actual);                
                pushPila(pilaLab,nodoAInsertar);
            }else if(movPos.derecha == 1){
                lab[actual->x][actual->y] = '.';
                actual = crearCoordenada(actual->x,actual->y+1);
                Nodo *nodoAInsertar = newNodo(actual);                
                pushPila(pilaLab,nodoAInsertar);
            }else if(movPos.izquierda == 1){
                lab[actual->x][actual->y] = '.';
                actual = crearCoordenada(actual->x,actual->y-1);
                Nodo *nodoAInsertar = newNodo(actual);                
                pushPila(pilaLab,nodoAInsertar);
            }
        }
        
    }

    return pilaLab;
}

