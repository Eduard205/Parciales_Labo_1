/*
 * eSalon.h
 *Agrupa funciones que permiten trabajar con los datos almacenados en la estructura Salon,
 *la cual representa los datos de una empresa.
 *
 */

#ifndef ESALON_H_
#define ESALON_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#define SHOPPING 1
#define LOCAL 2

typedef struct {
	int idSalon;
	char nombre[10];
	char direccion[15];
	int tipoDeSalon;   //1-Shopping / 2-Local//
	int isEmpty; //0: Ocupado / 1: libre //
} eSalon;

int inicializarSalon(eSalon cadena[], int tam);
int buscarLibreSalon(eSalon cadena[], int *posicion, int tam);
int altaSalon(eSalon cadena[], int posicion);
int buscarSalon(eSalon cadena[], int tam, int id);
int modificarSalon(eSalon cadena[], int tam);
int modificarUnSalon(eSalon *cadena);
int bajaSalon(eSalon cadena[], int tam);
void mostrarUnSalon(eSalon cadena);
int mostrarSalones(eSalon cadena[], int tam);
int ordenarSalones(eSalon cadena[], int tam, int criterio);



#endif /* ESALON_H_ */
