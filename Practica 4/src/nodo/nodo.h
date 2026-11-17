// Hernandez Espinosa Jose Jeronimo
// 2212321

#ifndef NODO_H
#define NODO_H

typedef struct Nodo{
    void *dato;
    struct Nodo *sig;
}Nodo;

Nodo *newNodo(void *valor);

#endif 