/*
 * eArcade.h
 *Agrupa funciones que permiten trabajar con los datos almacenados en la estructura Arcade,
 *la cual representa los datos de una empresa.
 *
 */

#ifndef EARCADE_H_
#define EARCADE_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#define LIBRE 1
#define OCUPADO 0
#define NACIONALIDAD_LEN 20
#define NOMBRE_DE_JUEGO_LEN 63
#define MONO 1
#define ESTEREO 2

typedef struct {
	int idSalon;
	int idArcade;
	char nacionalidad[NACIONALIDAD_LEN];
	char nombreDelJuego[NOMBRE_DE_JUEGO_LEN];
	int cantidadDeJugadores;
	int cantidadMaxDeFichas;
	int tipoDeSonido;   //1-Mono / 2-Estereo//
	int isEmpty; //0: Ocupado / 1: libre //
} eArcade;

int inicializarArcade(eArcade cadena[], int tam);
int buscarLibreArcade(eArcade cadena[], int *posicion, int tam);
int altaArcade(eArcade cadena[], int posicion, int* idSalonValidado);
int buscarArcade(eArcade cadena[], int tam, int id);
int modificarArcade(eArcade cadena[], int tam);
int modificarUnArcade(eArcade *cadena, int tam);
int bajaArcade(eArcade cadena[], int tam);
int bajaArcadesPorIdSalon(eArcade cadena[], int tam, int idSalonEliminado);
void mostrarUnArcade(eArcade cadena);
void mostrarNombreDeUnJuego(eArcade cadena);
int mostrarArcades(eArcade cadena[], int tam);
int arcades_ListarJuegos(eArcade cadena[], int tam);
int ordenarArcades(eArcade cadena[], int tam, int criterio);

int arcade_altaForzada(eArcade cadena[], int posicion, int idSalon /*int idArcade */, char* nacionalidad, char* nombreDelJuego, int cantidadDeJugadores, int cantidadMaxDeFichas,
int tipoDeSonido);


#endif /* EARCADE_H_ */
