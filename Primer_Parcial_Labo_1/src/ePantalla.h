/*
 * ePantalla.h
 *Agrupa funciones que permiten trabajar con los datos almacenados en la estructura Pantalla,
 *la cual representa los datos de unA de la empresa.
 *
 */

#ifndef EPANTALLA_H_
#define EPANTALLA_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

typedef struct {
	int id;
	char nombre[128];
	char direccion[128];
	float precio;
	int tipo;
	int isEmpty; // 0: Ocupado // 1: libre //
} ePantalla;

int inicializarPantalla(ePantalla array[], int tam);
int buscarLibrePantalla(ePantalla array[], int *posicion, int tam);
int altaPantalla(ePantalla array[], int posicion);
int buscarPantalla(ePantalla array[], int tam, int id);
int modificarPantalla(ePantalla array[], int tam);
int modificarUnaPantalla(ePantalla *array);
int bajaPantalla(ePantalla array[], int tam);
void mostrarUnaPantalla(ePantalla array);
int mostrarPantallas(ePantalla array[], int tam);
int ordenarPantallas(ePantalla array[], int tam, int criterio);



#endif /* EPANTALLA_H_ */
