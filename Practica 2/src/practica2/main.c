// Hernandez Espinosa Jose Jeronimo
// 2212321
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaD.h"
#include "Cancion.h"

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void)
{
    int option, corre_programa;
    Canciones canciones = cargarCanciones();
    
    ListaD lista = {NULL, NULL, NULL, 0, 0, NULL};
    
    corre_programa = 1;
    while(corre_programa)
    {
        printf("\n\r\n\r");
        
        if (lista.actual == NULL) {
            printf("Ninguna <-- Ninguna --> Ninguna\n");
        } else {
            Cancion *c_actual = (Cancion*)lista.actual->dato;
            Cancion *c_ant = NULL;
            Cancion *c_sig = NULL;

            if (lista.actual->ant) c_ant = (Cancion*)lista.actual->ant->dato;
            else if (lista.bucle && lista.fin) c_ant = (Cancion*)lista.fin->dato;

            if (lista.actual->sig) c_sig = (Cancion*)lista.actual->sig->dato;
            else if (lista.bucle && lista.inicio) c_sig = (Cancion*)lista.inicio->dato;

            printf("%s <-- %s --> %s\n", 
                c_ant ? c_ant->nombre : "Ninguna", 
                c_actual->nombre, 
                c_sig ? c_sig->nombre : "Ninguna");
        }

        printf("\n\r [0] BUCLE: %s", lista.bucle ? "ACTIVADO" : "DESACTIVADO");
        printf("\n\r [1] ANTERIOR");
        printf("\n\r [2] SIGUIENTE");
        printf("\n\r [3] AGREGAR CANCION");
        printf("\n\r [4] MOSTRAR LISTA DE REPRODUCCION");
        printf("\n\r [5] QUITAR CANCION");
        printf("\n\r [6] REINICIAR REPRODUCCION");
        printf("\n\r [7] TERMINAR PROGRAMA");

        printf("\n\r Escoge opcion: ");
        if (scanf("%d", &option) != 1) option = -1;
        clear_buffer();

        switch(option)
        {
        case 0:
            lista.bucle = !lista.bucle;
            break;
            
        case 1:
            if (lista.actual) {
                if (lista.actual->ant) lista.actual = lista.actual->ant;
                else if (lista.bucle && lista.fin) lista.actual = lista.fin;
            }
            break;
            
        case 2:
            if (lista.actual) {
                if (lista.actual->sig) lista.actual = lista.actual->sig;
                else if (lista.bucle && lista.inicio) lista.actual = lista.inicio;
            }
            break;
            
        case 3: {
            imprimirCanciones(canciones);
            int id_cancion;
            printf("\nSelecciona el numero de cancion a agregar: ");
            scanf("%d", &id_cancion);
            clear_buffer();
            
            if (id_cancion >= 0 && id_cancion < canciones.cant) {
                NodoD *aux = lista.inicio;
                int i = 0;
                while(aux) {
                    printf("\n[%d] ", i++);
                    imprimirCancion(aux->dato);
                    aux = aux->sig;
                }
                
                int pos;
                printf("\nPosicion a insertar (0 a %d): ", lista.cant);
                scanf("%d", &pos);
                clear_buffer();
                
                if (pos >= 0 && pos <= lista.cant) {
                    insertarEnPosicionD(&lista, &canciones.cancion[id_cancion], pos);
                    if (lista.cant == 1) lista.actual = lista.inicio;
                }
            }
            break;
        }
        
        case 4: {
            NodoD *aux = lista.inicio;
            int i = 0;
            if(!aux) printf("\nLista de reproduccion vacia.");
            while(aux) {
                if (aux == lista.actual) printf("\n>> [%d] ", i++);
                else printf("\n   [%d] ", i++);
                imprimirCancion(aux->dato);
                aux = aux->sig;
            }
            break;
        }
        
        case 5: {
            NodoD *aux = lista.inicio;
            int i = 0;
            while(aux) {
                printf("\n[%d] ", i++);
                imprimirCancion(aux->dato);
                aux = aux->sig;
            }
            if (lista.cant > 0) {
                int pos;
                printf("\nPosicion a eliminar: ");
                scanf("%d", &pos);
                clear_buffer();
                
                eliminarPosicionD(&lista, pos);
            } else {
                printf("\nNo hay canciones para eliminar.");
            }
            break;
        }
        
        case 6:
            lista.actual = lista.inicio;
            break;
            
        case 7:
            corre_programa = 0;
            break;
            
        default:
            printf("\nOpcion no valida.");
            break;
        }
        
        printf("\n\nENTER PARA CONTINUAR...");
        getchar();
    }
    
    while (lista.cant > 0) {
        eliminarPosicionD(&lista, 0);
    }
    
    printf("\n FIN DE PROGRAMA \n\r");
    return 0;
}