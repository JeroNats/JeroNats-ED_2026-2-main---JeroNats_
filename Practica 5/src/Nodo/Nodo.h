// Hernandez Espinosa Jose Jeronimo
// 2212321

#ifndef NODO_H
#define NODO_H

typedef struct NodoAR{
    int dato;
    struct NodoAR *padre;
    struct NodoAR *derecha;
    struct NodoAR *izquierda;    
}NodoAR;

NodoAR *crearNodoAR();

#endif