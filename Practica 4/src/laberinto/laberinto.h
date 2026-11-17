// Hernandez Espinosa Jose Jeronimo
// 2212321

#ifndef LABERINTO_H
#define LABERINTO_H

#define REN 27
#define COL 26

typedef unsigned char **Laberinto;

typedef struct{
    int x, y;      
}Coordenada;

typedef struct{
    int arriba, abajo, izquierda, derecha;     
}Movimientos;

Coordenada *crearCoordenada(int x, int y);
int compararCoordenadas(void *xya,void *xyb );
void moverPunto(Laberinto laberinto, Coordenada *coordenadas, char AoB);
void moverA(Laberinto laberinto, Coordenada *coordenadas);
void moverB(Laberinto laberinto, Coordenada *coordenadas);
Laberinto crearLaberinto();
void imprimirLaberinto(Laberinto laberinto);
void freeLaberinto(Laberinto laberinto);
Movimientos revisarMovimientos(Laberinto laberinto, Coordenada coordenadas);
int sinCaminos(Movimientos movPos);
void imprimirMovimientosPosibles(Movimientos movPos);


#endif
