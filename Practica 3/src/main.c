// Hernandez Espinosa Jose Jeronimo
// 2212321

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>
#include <math.h>
#include "pila.h"
#include "nodo.h"

#define MAXTEXT 99
int menu();
void limpiarTexto(char original[], char limpio[]);
void veriPali();
void veriParente();

int main(void){
    int opc = 0;
    
    do{
        opc = menu();
        getchar();
        switch(opc){
            case 1:
            veriPali(); 
            break;
            case 2:
            veriParente();
            break;
            case 3:
            printf("\nFinalizando. . .");
            break;
    }
    }while(opc != 3);
    return 0;
}

int menu(){
    int opc = 0;
    printf("\n============ MENU ============\n"
             "[1] Verificar si es palindromo\n"
             "[2] Verificación de paréntesis\n"
             "[3] Terminar programa\n"
             "==============================\n"
             "Escribe la opcion que desees: ");
    scanf("%i", &opc);
    return opc;
}

void limpiarTexto(char original[], char limpio[]){
    int i = 0, j = 0;
    while( original[i] != '\0' ){
        if( original[i] >= 65 && original[i] <= 90){
            limpio[j] = original[i] + 32;
            i++;
            j++;
        }else if( original[i] >= 97 && original[i] <= 122){
            limpio[j] = original[i];
            i++;
            j++;           
        }else{
            i++;
        }
    }
    limpio[j] = '\0';
}
void veriPali(){
    char cadenaText[MAXTEXT];
    char cadenaLimpia[MAXTEXT];
    char caux;
    int i=0, j=0;
    int totalcarac;
    Nodo *nodoAux;
    printf("\n\nSeleccionaste verificar palindromo\n\n\nEscribe la palabra o frase que deseas verificar: ");
    fgets(cadenaText,MAXTEXT,stdin);

    limpiarTexto(cadenaText, cadenaLimpia);
    Pila *textoExtraer = crearPila();
    Nodo *nodoExtraer = NULL;

    while(cadenaLimpia[i] != '\0'){
        void *dato = &cadenaLimpia[i];
        pushPila(textoExtraer, dato);
        i++;
    }

    i = 0;

    while(textoExtraer->cant != 0){
        caux = *(char *)peekPila(textoExtraer);
        if(caux != cadenaLimpia[i]){
            printf("\nLetra diferente encontrada, no es un palindromo");
            return;
        }
        if(caux == cadenaLimpia[i]){
            nodoAux = popPila(textoExtraer);
            free(nodoAux);
            i++;
        }
    }
    printf("\nLa palabra SI es palindromo");
    return;
}
void veriParente(){
    char cadenaText[MAXTEXT];
    char caux;
    int i=0;
  

    printf("\n\nSeleccionaste Verificacion de parentesis\n\n\nEscribe la cadena de caracteres deseas verificar: ");
    fgets(cadenaText,MAXTEXT,stdin);    

    if(cadenaText[0] == ')' || cadenaText[0] == '}' || cadenaText[0] == ']'){
        printf("\nLa cadena no puede iniciar con un simbolo de cierre\n");
        return;
    }
    Pila *pilaPare = crearPila();
    Nodo *nodoAux;
    while(cadenaText[i] != '\0'){
        if(cadenaText[i] == '(' || cadenaText[i] == '{' || cadenaText[i] == '['){
            caux = cadenaText[i];
            pushPila(pilaPare, &cadenaText[i]);
        }else if(cadenaText[i] == ')' || cadenaText[i] == '}' || cadenaText[i] == ']'){
            if(pilaPare->cima == NULL){
                return;
            }
            caux = *(char *)peekPila(pilaPare);
            if( ')' == cadenaText[i]){
                nodoAux = popPila(pilaPare);
                caux = *(char *)nodoAux->dato;
                if(caux == '('){
                    free(nodoAux);
                }else{
                    printf("\nCadena de texto invalida, no todos los simbolos se cierran bien\n");            
                    return;
                }
            }else if( '}' == cadenaText[i]){
                nodoAux = popPila(pilaPare);
                caux = *(char *)nodoAux->dato;
                if(caux == '{'){
                    free(nodoAux);
                }else{
                    printf("\nCadena de texto invalida, no todos los simbolos se cierran bien\n");            
                    return;
                }
            }else if( ']' == cadenaText[i]){
                nodoAux = popPila(pilaPare);
                caux = *(char *)nodoAux->dato;
                if(caux == '['){
                    free(nodoAux);
                }else{
                    printf("\nCadena de texto invalida, no todos los simbolos se cierran bien\n");            
                    return;
                }
            }           
        }
        i++;
    }
    if(pilaPare->cant == 0 || pilaPare->cima == NULL){
        printf("\nCadena de texto validada, todos los simbolos se cierran\n");
    }else{
        printf("\nCadena de texto invalida, no todos los simbolos se cierran\n");        
    }
}
