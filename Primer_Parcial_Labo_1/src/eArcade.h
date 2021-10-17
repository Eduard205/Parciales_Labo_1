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

typedef struct {
	int idSalon;
	int idArcade;
	char nacionalidad[20];
	char nombreDelJuego[63];
	int cantidadDeJugadores;
	int cantidadMaxDeFichas;
	int tipoDeSonido;   //1-Mono / 2-Estereo//
	int isEmpty; //0: Ocupado / 1: libre //
} eArcade;

int inicializarArcade(eArcade cadena[], int tam);
int buscarLibreArcade(eArcade cadena[], int *posicion, int tam);
int altaArcade(eArcade cadena[], int posicion);
int buscarArcade(eArcade cadena[], int tam, int id);
int modificarArcade(eArcade cadena[], int tam);
int modificarUnArcade(eArcade *cadena);
int bajaArcade(eArcade cadena[], int tam);
void mostrarUnArcade(eArcade cadena);
int mostrarArcades(eArcade cadena[], int tam);
int ordenarArcades(eArcade cadena[], int tam, int criterio);



#endif /* EARCADE_H_ */
