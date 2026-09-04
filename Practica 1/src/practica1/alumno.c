// Hernandez Espinosa Jose Jeronimo
// 2212321

#include "alumno.h" 
#include <Nodo.h>

int compararMatricula(void *dato1, void *dato2){
	Alumno *a1 = (Alumno *)dato1;
	Alumno *a2 = (Alumno *)dato2;
	if(a1->matricula < a2->matricula) return -1;
	if(a1->matricula > a2->matricula) return 1;
	return 0;
}

int compararNombre(void *dato1, void *dato2){
	Alumno *a1 = (Alumno *)dato1;
	Alumno *a2 = (Alumno *)dato2;
	return strcmp(a1->nombre, a2->nombre);
}

int compararSemestres(void *dato1, void *dato2){
	Alumno *a1 = (Alumno *)dato1;
	Alumno *a2 = (Alumno *)dato2;
	if(a1->semestres < a2->semestres) return -1;
	if(a1->semestres > a2->semestres) return 1;
	return 0;
}

int compararPromedio(void *dato1, void *dato2){
	Alumno *a1 = (Alumno *)dato1;
	Alumno *a2 = (Alumno *)dato2;
	if(a1->promedio < a2->promedio) return -1;
	if(a1->promedio > a2->promedio) return 1;
	return 0;
}

void crearAlumnos(void *ptr){
	Lista *lista = (Lista *)ptr;
	Alumno busqueda;
	
	printf("Matricula: ");
	scanf("%u", &busqueda.matricula);
	
	if(buscarDato(lista, &busqueda, compararMatricula)){
		printf("Error: La matricula ya existe\n");
		return;
	}
	
	Alumno *nuevo = (Alumno *)malloc(sizeof(Alumno));
	nuevo->matricula = busqueda.matricula;
	
	printf("Nombre: ");
	scanf(" %[^\n]", nuevo->nombre);
	printf("Semestres: ");
	scanf("%d", &nuevo->semestres);
	printf("Promedio: ");
	scanf("%f", &nuevo->promedio);
	
	insertarEnOrden(lista, nuevo);
}

void imprimirAlumno(void *dato){
	Alumno *a = (Alumno *)dato;
	printf("%u | %s | %d | %.2f\n", a->matricula, a->nombre, a->semestres, a->promedio);
}

void imprimirAlumnos(void *ptr){
	Lista *lista = (Lista *)ptr;
	Nodo *actual = lista->inicio;
	
	printf("\n--- Lista de Alumnos ---\n");
	while(actual != NULL){
		imprimirAlumno(actual->dato);
		actual = actual->sig;
	}
	printf("------------------------\n");
}

void buscarAlumnos(void *ptr){
	Lista *lista = (Lista *)ptr;
	Alumno busqueda;
	int opcion;
	
	printf("Buscar por:\n 1 Matricula\n 2 Nombre\n 3 Semestres\n 4 Promedio\nOpcion: ");
	scanf("%d", &opcion);
	
	if(opcion == 1){
		printf("Matricula: ");
		scanf("%u", &busqueda.matricula);
	} else if(opcion == 2){
		printf("Nombre: ");
		scanf(" %[^\n]", busqueda.nombre);
	} else if(opcion == 3){
		printf("Semestres: ");
		scanf("%d", &busqueda.semestres);
	} else if(opcion == 4){
		printf("Promedio: ");
		scanf("%f", &busqueda.promedio);
	}
	
	Nodo *actual = lista->inicio;
	Alumno *encontrado = NULL;
	
	while(actual != NULL){
		if(opcion == 1 && compararMatricula(actual->dato, &busqueda) == 0){
			encontrado = (Alumno *)actual->dato;
			break;
		} else if(opcion == 2 && compararNombre(actual->dato, &busqueda) == 0){
			encontrado = (Alumno *)actual->dato;
			break;
		} else if(opcion == 3 && compararSemestres(actual->dato, &busqueda) == 0){
			encontrado = (Alumno *)actual->dato;
			break;
		} else if(opcion == 4 && compararPromedio(actual->dato, &busqueda) == 0){
			encontrado = (Alumno *)actual->dato;
			break;
		}
		actual = actual->sig;
	}
	
	if(encontrado != NULL){
		printf("Alumno encontrado:\n");
		imprimirAlumno(encontrado);
	} else {
		printf("Alumno no encontrado\n");
	}
}

void borrarAlumnos(void *ptr){
	Lista *lista = (Lista *)ptr;
	Alumno busqueda;
	printf("Ingresa la matricula a borrar: ");
	scanf("%u", &busqueda.matricula);
	
	eliminarDato(lista, &busqueda, compararMatricula);
}

void reordenarAlumnos(void *ptr){
	Lista *lista = (Lista *)ptr;
	int opcion;
	printf("Reordenar por:\n[1] Matricula\n[2] Nombre\n[3] Semestres\n[4] Promedio\nOpcion: ");
	scanf("%d", &opcion);
	
	if(opcion == 1) lista->comparar = compararMatricula;
	else if(opcion == 2) lista->comparar = compararNombre;
	else if(opcion == 3) lista->comparar = compararSemestres;
	else if(opcion == 4) lista->comparar = compararPromedio;
	
	ordenarLista(lista);
}