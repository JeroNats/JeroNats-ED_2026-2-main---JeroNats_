// Hernandez Espinosa Jose Jeronimo
// 2212321

#include <stdlib.h>
#include <stdio.h>
#include "laberinto.h"

Coordenada *crearCoordenada(int x, int y){
    if(x < 0 || y < 0){ printf("\nCoordenadas invalida"); return NULL; }

    Coordenada *cxy = (Coordenada *)malloc(sizeof(Coordenada));

    if(!cxy){ printf("\nLa coordenada no se pudo crear correctamente"); return NULL; }

    cxy->x = x;
    cxy->y = y;

    return cxy;
}
int compararCoordenadas(void *xya,void *xyb ){
    Coordenada *coordenadaA = xya;
    Coordenada *coordenadaB = xyb;
    if( coordenadaA->x == coordenadaB->x && coordenadaA->y == coordenadaB->y ){
        return 1;
    }
    return 0;
}
void imprimirCoordenadas(void *xy){
    Coordenada *coords = xy;
    printf("\n[X = %i][Y= %i]", coords->x, coords->y);
}
void moverPunto(Laberinto laberinto, Coordenada *coordenadas, char AoB){
    for(int i = 0 ; i < REN ; i++){
        for(int j = 0 ; j < COL ; j++){
            if( laberinto[i][j] == AoB ){
                laberinto[i][j] = '*';
            }
            if( coordenadas->x == i && coordenadas->y == j){
                laberinto[i][j] = AoB;
            }
        }
    }
}
void moverA(Laberinto laberinto, Coordenada *coordenadas){
    moverPunto(laberinto, coordenadas, 'A');
}
void moverB(Laberinto laberinto, Coordenada *coordenadas){
    moverPunto(laberinto, coordenadas, 'B');
}
Laberinto crearLaberinto(){
    Laberinto laberinto = (unsigned char **)malloc(REN * sizeof(unsigned char*));
    
    if(!laberinto){ printf("\nEl laberinto no se pudo crear correctamente"); return NULL; }

    char *temp = 
"xxxxxxxxxxxxxxxxxxxxxxxxxx\
xAx*****x****************x\
x*xxx*x*x*xxxxxxxxx*xxxx*x\
x*****x*x******x**x****x*x\
xxxxxxx*xxxxxx*xx*xxxx*xxx\
x*****x*x****x*x****xx***x\
x*xxx*x*xxxx*x*x*xxxxx*x*x\
x***x*x****x*****xxxxxxx*x\
xxx*x*xxxx*xxxxxxx****x**x\
x*x*x***xx****xx***xx*x*xx\
x*x*x*x*xxxxx**x*xxxx*x**x\
x*x*x*x***x*xx*x****x*xx*x\
x*x*x*xxx****x*x*xx*x****x\
x*x*x*xxxxxxxx*x**x*xxxx*x\
x***x********x*xx*x*x****x\
x*xxxxxxxxxx*x**xxx*x*xxxx\
x***x******x**x*****x**x*x\
xxx*x*xxxxxxx*xxxxxxxx*x*x\
x*x*x*******x****xx****x*x\
x*x*x*xxxxx*xxxx*xx*xxxx*x\
x*x*x****xx***x**xx*x****x\
x*x*xxxxxxx*x**x*xx*x*x*xx\
x*x*********xx*x*xx*xxx*xx\
x*xxxxxxxxxxx**x*********x\
x***x***x***x*xxxxxxxxxx*x\
x*x***x***x*************Bx\
xxxxxxxxxxxxxxxxxxxxxxxxxx\0";

    for(int i = 0 ; i < REN ; i++){
        laberinto[i] = (unsigned char *)malloc(COL * sizeof(unsigned char));
    }

    for(int i = 0 ; i < REN ; i++){
        for(int j = 0 ; j < COL ; j++){
            laberinto[i][j] = temp[(i*COL)+j];
        }
    }
    return laberinto;
}
void imprimirLaberinto(Laberinto laberinto){
    for(int i = 0 ; i < REN ; i++){
        printf("\n");
        for(int j = 0 ; j < COL ; j++){
            if(laberinto[i][j] == '*' ){
                printf(" ");
            }else{
                printf("%c", laberinto[i][j]);
            }
        }
    }
}
void freeLaberinto(Laberinto laberinto){
    for( int i = 0 ; i < REN ; i++ ){
        free(laberinto[i]);
    }
    free(laberinto);
}

Movimientos revisarMovimientos(Laberinto laberinto, Coordenada coordenadas){    
    if(!laberinto){ printf("\nLaberinto error en REVISAR MOVIMIENTOS "); Movimientos movPos = {0,0,0,0}; return movPos; }
    if(coordenadas.x < 0 || coordenadas.y < 0){ printf("\nCoordenadas error en REVISAR MOVIMIENTOS "); Movimientos movPos = {0,0,0,0}; return movPos; }

    Movimientos movPos = {0,0,0,0}; 
    
    // ARRIBA 
    if(laberinto[coordenadas.x - 1][coordenadas.y] == '*' || laberinto[coordenadas.x - 1][coordenadas.y] == 'B'){
        movPos.arriba = 1;
    }
    // ABAJO    
    if(laberinto[coordenadas.x + 1][coordenadas.y] == '*' || laberinto[coordenadas.x + 1][coordenadas.y] == 'B'){
        movPos.abajo = 1;
    }
    // DERECHA
    if(laberinto[coordenadas.x][coordenadas.y + 1] == '*' || laberinto[coordenadas.x][coordenadas.y + 1] == 'B'){
        movPos.derecha = 1;
    }
    // IZQUIERDA
    if(laberinto[coordenadas.x][coordenadas.y - 1] == '*' || laberinto[coordenadas.x][coordenadas.y - 1] == 'B'){
        movPos.izquierda = 1;
    }

    return movPos;
}
int sinCaminos(Movimientos movPos){
    if( movPos.arriba == 0 && movPos.abajo == 0 && movPos.izquierda == 0 && movPos.derecha == 0 ){
        return 1;
    }else{ return 0; }
}
void imprimirMovimientosPosibles(Movimientos movPos){
    printf("\nMovimientos posibles: ");
    // ARRIBA 
    if(movPos.arriba == 1){
        printf("\nArriba");
    }
    // ABAJO    
    if(movPos.abajo == 1){
        printf("\nAbajo");
    }
    // DERECHA
    if(movPos.derecha == 1){
        printf("\nDerecha");
    }
    // IZQUIERDA
    if(movPos.izquierda == 1){
        printf("\nIzquierda");
    }
 }

