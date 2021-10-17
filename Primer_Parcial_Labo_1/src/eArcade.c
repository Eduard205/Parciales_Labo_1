/*
 * eArcade.c
 *Desarrollo de funciones de la biblioteca eArcade.h
 */

#include "eArcade.h"

static int obtenerId(void);

static int obtenerId(void) {

	static int contador = 1;

	return (contador++);
}

int inicializarArcade(eArcade cadena[], int tam) {
	int devolucion = -1;
	if (cadena != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			cadena[i].isEmpty = 1;
			cadena[i].idArcade = 0;
			cadena[i].idSalon = 0;
			strcpy(cadena[i].nacionalidad, " ");
			strcpy(cadena[i].nombreDelJuego, " ");
			cadena[i].cantidadDeJugadores = 0;
			cadena[i].cantidadMaxDeFichas = 0;
			cadena[i].tipoDeSonido = 0;

		}
		devolucion = 0;
	}
	return devolucion;
}

int buscarLibreArcade(eArcade cadena[], int *posicion, int tam) {

	int rtn = -1;
	if (cadena != NULL && posicion != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (cadena[i].isEmpty == 1) {
				*posicion = i;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

int altaArcade(eArcade cadena[], int posicion) {

	int rtn = 0;
	char auxChar1[50];
	char auxChar2[63];
	int auxInt1;
	int auxInt2;
	int auxInt3;
	int auxInt4;

	if (pedirEntero(&auxInt1, 1, 100, 3, "Ingrese Id del Salon: ",
						"Error, reingrese Id del Salon: ") == 1) {

	if (pedirCadena(auxChar1, 20, 3, "Ingrese Nacionalidad: ",
			"Error reingrese Nacionalidad: ") == 1) {

		if (pedirCadena(auxChar2, 63, 3, "Ingrese Nombre del Juego: ",
				"Error, reingrese Nombre del Juego: ") == 1) {

			if (pedirEntero(&auxInt2, 1, 2, 3, "Ingrese cantidadd de jugadores: ",
					"Error, reingrese cantidad de jugadores: ") == 1) {

				if (pedirEntero(&auxInt3, 1, 500, 3, "Ingrese cantidad maxima de fichas: ",
						"Error, reingrese cantidad maxima de fichas: ")==1) {

					if (pedirEntero(&auxInt4, 1, 2, 3, "Ingrese tipo de Sonido (1-Mono, 2-Estereo): ",
							"Error, reingrese tipo de Sonido (1-Mono, 2-Estereo): ")==1){

					cadena[posicion].idArcade = obtenerId();
					cadena[posicion].idSalon = auxInt1;
					strcpy(cadena[posicion].nacionalidad, auxChar1);
					strcpy(cadena[posicion].nombreDelJuego, auxChar2);
					cadena[posicion].cantidadDeJugadores = auxInt2;
					cadena[posicion].cantidadMaxDeFichas = auxInt3;
					cadena[posicion].tipoDeSonido = auxInt4;
					cadena[posicion].isEmpty = 0;
					rtn = 1;

					printf("Id Salon: %d\n", cadena[posicion].idSalon);
					printf("Id Arcade: %d\n", cadena[posicion].idArcade);
					printf("Nacionalidad: %s\n", cadena[posicion].nacionalidad);
					printf("Nombre del Juego: %s\n", cadena[posicion].nombreDelJuego);
					printf("Cantidad de Jugadores: %d\n", cadena[posicion].cantidadDeJugadores);
					printf("Cantidad Maxima de Fichas: %d\n", cadena[posicion].cantidadMaxDeFichas);
					printf("Tipo de Sonido: %d\n", cadena[posicion].tipoDeSonido);

				}

			}
		}

	}
	}
	}
	//printf("isEmpty: %d\n", array[posicion].isEmpty);

	return rtn;
}

int buscarArcade(eArcade cadena[], int tam, int id) {
	int rtn = -1;
	int i;

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (cadena[i].idArcade == id && cadena[i].isEmpty == 0) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int modificarUnArcade(eArcade *cadena) {

	int rtn = 0;
	char auxChar[63];
	int auxInt;

	if (pedirCadena(auxChar, 63, 3, "Ingrese Nombre del Juego: ",
					"Error, reingrese Nombre del Juego: ") == 1) {

		strcpy(cadena->nombreDelJuego, auxChar);
		rtn = 1;

	}

	if (pedirEntero(&auxInt, 1, 2, 3, "Ingrese cantidad de jugadores: ",
						"Error, reingrese cantidad de jugadores: ") == 1) {

			cadena->cantidadDeJugadores = auxInt;
			rtn = 1;
	}


	return rtn;
}

int modificarArcade(eArcade cadena[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 1000, 3,
			"Ingrese el id del Arcade a modificar: ",
			"Error. Ingrese un Id de Arcade entre (1-1000): ") == 1) {
		if (buscarArcade(cadena, tam, idAux) == -1) {
			printf("No existe el id ingresado\n ");
		} else {
			posicion = buscarArcade(cadena, tam, idAux);
			if (modificarUnArcade(&cadena[posicion]) == 1) {
				rtn = 1;
			} else {
				printf("Error, no se modificaron los campos");
			}
		}
	}

	if (rtn == 1) {
		printf("Se modifico el arcade con el id %d\n", cadena[posicion].idArcade);
		printf("Nuevo Nombre del Juego: %s\n", cadena[posicion].nombreDelJuego);
		printf("Nueva Cantidad de Jugadores: %d\n", cadena[posicion].cantidadDeJugadores);

	}

	return rtn;
}

int bajaArcade(eArcade cadena[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 1000, 3,
			"Ingrese el id del Arcade a dar de baja: ",
			"Error. Ingrese un Id de Arcade entre (1-1000): ") == 1) {
		if (buscarArcade(cadena, tam, idAux) == -1) {
			printf("No existe el id ingresado\n ");
		} else {
			posicion = buscarArcade(cadena, tam, idAux);
			cadena[posicion].isEmpty = 1;
			rtn = 1;
		}
	}

	if (rtn == 1) {
		printf("Se dio de baja al Arcade con el id %d\n",
				cadena[posicion].idArcade);

		printf("Id Salon: %d\n", cadena[posicion].idSalon);
		printf("Id Arcade: %d\n", cadena[posicion].idArcade);
		printf("Nacionalidad: %s\n", cadena[posicion].nacionalidad);
		printf("Nombre del Juego: %s\n", cadena[posicion].nombreDelJuego);
		printf("Cantidad de Jugadores: %d\n", cadena[posicion].cantidadDeJugadores);
		printf("Cantidad Maxima de Fichas: %d\n", cadena[posicion].cantidadMaxDeFichas);
		printf("Tipo de Sonido: %d\n", cadena[posicion].tipoDeSonido);

	}

	return rtn;
}

void mostrarUnArcade(eArcade cadena) {

	printf("%5d%5d%10s%10s%7d%7d%7d\n", cadena.idSalon, cadena.idArcade,cadena.nacionalidad, cadena.nombreDelJuego,
			cadena.cantidadDeJugadores, cadena.cantidadMaxDeFichas, cadena.tipoDeSonido);

}

int mostrarArcades(eArcade cadena[], int tam) {
	int i;
	int rtn = 0;

	printf("\n\t> LISTADO ARCADES\n");
	printf("%5s%5s%10s%15s%5s%5s%10s\n", "ID SALON","ID ARCADE","NACIONALIDAD","NOMBRE DEL JUEGO","CANT DE JUGADORES","CANT MAX FICHAS","TIPO DE SONIDO");

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (cadena[i].isEmpty == 0) {
				mostrarUnArcade(cadena[i]);
				rtn++;
			}
		}

	}
	return rtn;
}

int ordenarArcades(eArcade cadena[], int tam, int criterio) {

	int rtn = 0;
	int i;
	int j;
	eArcade aux;

	if (cadena != NULL && tam > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (cadena[i].isEmpty == 0 && cadena[j].isEmpty == 0) {
						if (cadena[i].tipoDeSonido > cadena[j].tipoDeSonido) {
							aux = cadena[i];
							cadena[i] = cadena[j];
							cadena[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < tam - 1; i++) {
				for (j = i + 1; j < tam; j++) {
					if (cadena[i].isEmpty == 0 && cadena[j].isEmpty == 0) {
						if (cadena[i].tipoDeSonido < cadena[j].tipoDeSonido) {
							aux = cadena[i];
							cadena[i] = cadena[j];
							cadena[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			rtn = 0;
			break;
		}
	}
	return rtn;
}
