// Hernandez Espinosa Jose Jeronimo
// 2212321

#include "Arbol.h"
#include "Nodo.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int menu();
void mostrarArbol(Arbol *arbol);

int main(void){
    int opc = 0;
    Arbol *arbol = crearArbol();
    int dato;

    do{
        opc = menu();
        getchar();
        switch(opc){
            case 1:
                printf("\nIngresa el numero que deseas insertar: ");
                scanf("%i", &dato);
                NodoAR *nodoinsertar = crearNodoAR();
                nodoinsertar->dato = dato;
                insertarEnArbol(arbol, nodoinsertar); 
                break;
            case 2:
                printf("\nIngresa el numero que deseas insertar: ");
                scanf("%i", &dato);
                eliminarNodoAR(arbol,dato);
                break;
            case 3:
                ordenarArbol(arbol);
                break; 
            case 4:
                mostrarArbol(arbol);
                break;            
            case 5:
                liberarArbol(arbol);
                printf("\nFinalizando. . .");
                break;
            default:
                printf("\nOpcion invalida vuelve a intentarlo. . .");
                break;
            }
    }while(opc != 5);
    return 0;
}
int menu(){
    int opc = 0;
    printf("\n============ MENU ============\n"
             "[1] Insertar en Arbol\n"
             "[2] Eliminar dato en Arbol\n"
             "[3] Equilibrar el Arbol\n"
             "[4] Mostrar Arbol\n"
             "[5] Terminar programa\n"
             "==============================\n"
             "Escribe la opcion que desees: ");
    scanf("%i", &opc);
    return opc;
}
void mostrarArbol(Arbol *arbol){
    if(!arbol){ printf("\nError: el Arbol ingresado es invalido <mostrarArbol>"); return;}
    if(arbol->raiz == NULL){ printf("\nEl arbol ingresado esta vacio desde en su raiz <mostrarArbol>"); return;}

    int ar = 0;
    do{
    printf("\n============ MOSTRAR ARBOL ============\n"
             "[1] Imprimir In Orden: R->I->D\n"
             "[2] Imprimir Pre Orden: I->R->D\n"
             "[3] Imprimir Post Orden: I->D->R\n"
             "[4] Imprimir Pre Orden (Visual)\n"
             "=======================================\n"
             "Escribe la opcion que desees: ");
    scanf("%i", &ar);
    }while( ar != 1 && ar != 2 && ar != 3 && ar != 4 );

    switch(ar){
        case 1:
            imprimirARIN_Orden(arbol);
            break;
        case 2:
            imprimirARPre_Orden(arbol);
            break;
        case 3:
            imprimirARPost_Orden(arbol);
            break;
        case 4:
            NodoAR *nodoar = arbol->raiz;
            imprimirArbol_Pre_Orden(nodoar,0, 'r');
            break;
    }
}
