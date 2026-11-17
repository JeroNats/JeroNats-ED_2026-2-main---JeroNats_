// Hernandez Espinosa Jose Jeronimo
// 2212321
#include "Cancion.h"

Canciones cargarCanciones(void)
{
	static Cancion biblioteca[] = 
	{
		{"Burn My Dread", "Shoji Meguro", 2006},
		{"Mass Destruction", "Shoji Meguro", 2006},
		{"Deep Breath", "Shoji Meguro", 2006},
		{"Changing Seasons", "Shoji Meguro", 2006},
		{"Memories of You", "Shoji Meguro", 2006},
		{"Master of Tartarus", "Shoji Meguro", 2006},
		{"Want To Be Close", "Shoji Meguro", 2006},
		{"Wake Up Get Out", "Shoji Meguro", 2016},
		{"Last Surprise", "Shoji Meguro", 2016},
		{"Beneath the Mask", "Shoji Meguro", 2016},
		{"Life Will Change", "Shoji Meguro", 2016},
		{"Rivers in Desert", "Shoji Meguro", 2016},
		{"Tokyo Daylight", "Shoji Meguro", 2016},
		{"Keeper of Lust", "Shoji Meguro", 2016},
		{"Layer Cake", "Shoji Meguro", 2016}
	};	
	static Canciones canciones;
	canciones.cancion = biblioteca;
	canciones.cant = sizeof(biblioteca)/sizeof(Cancion);
	return canciones;
}

void imprimirCanciones(Canciones canciones)
{
	printf("\n Canciones TOTAL:%d", (int)canciones.cant);
	for(int i = 0 ; i< canciones.cant; i++)
	{
		printf("\n[%d]",i);
		imprimirCancion(&canciones.cancion[i]);
	}
}

void imprimirCancion(void *dato)
{
	Cancion *cancion = dato;
	printf(" %-20s ",cancion->nombre);
	printf("| %-20s ",cancion->autor);
	printf("| %hu ",cancion->release_date);
}

void imprimirNombre(void *dato)
{
	Cancion *cancion = dato;
	printf(" %-20s ",cancion->nombre);	
}