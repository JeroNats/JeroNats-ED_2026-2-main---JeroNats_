// Hernandez Espinosa Jose Jeronimo
// 2212321

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostring.h>
#include <Lista.h>
#include "alumno.h"

int menu(void);

int main(void){
	
	Lista listaAlumnos;
	listaAlumnos.inicio = NULL;
	listaAlumnos.fin = NULL;
	listaAlumnos.cant = 0;
	listaAlumnos.comparar = compararMatricula;
	int opcion = 0;
	
	do{
		opcion = menu();	
		switch(opcion){
			case 1:
				crearAlumnos(&listaAlumnos);
				break;
			case 2:
				imprimirAlumnos(&listaAlumnos);
				break;
			case 3:
				reordenarAlumnos(&listaAlumnos);
				break;
			case 4:
				buscarAlumnos(&listaAlumnos);			
				break;
			case 5:
				borrarAlumnos(&listaAlumnos);
				break;	
			case 6:
				printf("\nFinalizar el programa\n");
				break;
			default:
				printf("\nOpcion invalida\n");
				break;
		}
	} while(opcion != 6);
	
	eliminarLista(&listaAlumnos);
	printf("\n\n FIN DE PROGRAMA :)\n");
	return 0;
}

int menu(void){
	int opcion;
	printf("\n======== MENU ========\n"
		   "[1] Registrar alumno\n"
		   "[2] Imprimir alumnos\n"
		   "[3] Reordenar\n"
		   "[4] Buscar alumno\n"
		   "[5] Borrar alumno\n"
		   "[6] Finalizar el programa\n"
		   "======================\n"
		   "Escribe el numero de la opcion que desees: ");
	scanf("%d", &opcion);
	return opcion;
}