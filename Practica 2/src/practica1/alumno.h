// Hernandez Espinosa Jose Jeronimo
// 2212321

#ifndef ALUMNO_H
#define ALUMNO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Lista.h>

typedef struct {
	unsigned int matricula;
	char nombre[64];
	int semestres;
	float promedio;
} Alumno;

int compararMatricula(void *dato1, void *dato2);
int compararNombre(void *dato1, void *dato2);
int compararSemestres(void *dato1, void *dato2);
int compararPromedio(void *dato1, void *dato2);

void crearAlumnos(void *ptr);
void imprimirAlumno(void *dato);
void imprimirAlumnos(void *ptr);
void buscarAlumnos(void *ptr);
void borrarAlumnos(void *ptr);
void reordenarAlumnos(void *ptr);

#endif