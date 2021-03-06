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

int altaArcade(eArcade cadena[], int posicion, int *idSalonValidado) {

	int rtn = 0;
	eArcade bufferAux;

	if (pedirCadena(bufferAux.nacionalidad, 20, 3, "Ingrese Nacionalidad: ",
			"Error reingrese Nacionalidad: ") == 1
			&& pedirCadena(bufferAux.nombreDelJuego, 63, 3,
					"Ingrese Nombre del Juego: ",
					"Error, reingrese Nombre del Juego: ") == 1

			&& pedirEntero(&bufferAux.cantidadDeJugadores, 1, 2, 3,
					"Ingrese cantidadd de jugadores: ",
					"Error, reingrese cantidad de jugadores: ") == 1

			&& pedirEntero(&bufferAux.cantidadMaxDeFichas, 1, 500, 3,
					"Ingrese cantidad maxima de fichas: ",
					"Error, reingrese cantidad maxima de fichas: ") == 1

			&& pedirEntero(&bufferAux.tipoDeSonido, 1, 2, 3,
					"Ingrese tipo de Sonido (1-Mono, 2-Estereo): ",
					"Error, reingrese tipo de Sonido (1-Mono, 2-Estereo): ")
					== 1) {

		bufferAux.idSalon = *idSalonValidado;
		bufferAux.idArcade = obtenerId();
		cadena[posicion] = bufferAux;
		cadena[posicion].isEmpty = 0;
		rtn = 1;

		mostrarUnArcade(cadena[posicion]);

	}

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

int modificarUnArcade(eArcade *cadena, int tam) {

	int rtn = 0;
	eArcade bufferAux;
	int opcion;

	pedirEntero(&opcion, 1, 2, 3,
			"Seleccionar campo a modificar (1-Nombre del juego, 2-Cantidad de Jugadores): ",
			"Error, reingrese campo a modificar: ");

	switch (opcion) {
	case 1:
		arcades_ListarJuegos(cadena, tam);

		if (pedirCadena(bufferAux.nombreDelJuego, 63, 3,
				"Ingrese Nombre del Juego: ",
				"Error, reingrese Nombre del Juego: ") == 1) {

			strncpy(cadena->nombreDelJuego, bufferAux.nombreDelJuego,
			NOMBRE_DE_JUEGO_LEN);
			rtn = 1;
		}

		break;

	case 2:
		if (pedirEntero(&bufferAux.cantidadDeJugadores, 1, 2, 3,
				"Ingrese cantidad de jugadores: ",
				"Error, reingrese cantidad de jugadores: ") == 1) {

			cadena->cantidadDeJugadores = bufferAux.cantidadDeJugadores;
			rtn = 1;
		}
		break;

	}

	return rtn;
}

int modificarArcade(eArcade cadena[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 1000, 3,
			"Ingrese el id del Arcade a modificar: ",
			"Error. Ingrese un Id de Arcade entre (1-1000): ") == 1
			&& buscarArcade(cadena, tam, idAux) != -1) {

		posicion = buscarArcade(cadena, tam, idAux);
		if (modificarUnArcade(&cadena[posicion], tam) == 1) {
			rtn = 1;
		} else {
			printf("Error, no se modificaron los campos");
			rtn = 0;
		}

	} else {
		printf("No existe el id ingresado\n ");
		rtn = 0;

	}

	if (rtn == 1) {
		printf("Se modifico el arcade con el id %d\n",
				cadena[posicion].idArcade);
		printf("Nuevo Nombre del Juego: %s\n", cadena[posicion].nombreDelJuego);
		printf("Nueva Cantidad de Jugadores: %d\n",
				cadena[posicion].cantidadDeJugadores);
	}

	return rtn;
}

int bajaArcade(eArcade cadena[], int tam) {

	int rtn = 0;
	int posicion;
	int idAux;
	char respuesta;

	if (pedirEntero(&idAux, 1, 1000, 3,
			"Ingrese el id del Arcade a dar de baja: ",
			"Error. Ingrese un Id de Arcade entre (1-1000): ") == 1
			&& buscarArcade(cadena, tam, idAux) != -1) {

		posicion = buscarArcade(cadena, tam, idAux);

		mostrarUnArcade(cadena[posicion]);

		if (pedirCadena(&respuesta, 2, 3,
				"Esta seguro de dar de baja al Arcade (s/n): ",
				"Error, reingrese respuesta (s/n): ") == 1
				&& respuesta == 's') {

			cadena[posicion].isEmpty = 1;
			rtn = 1;
		} else {
			printf("Se cancelo la baja del Arcade\n");
		}

	} else {
		printf("No existe el id ingresado\n ");
		rtn = 0;
	}

	if (rtn == 1) {
		printf("Se dio de baja al Arcade con el id %d\n",
				cadena[posicion].idArcade);

		mostrarUnArcade(cadena[posicion]);
	}

	return rtn;
}

int bajaArcadesPorIdSalon(eArcade cadena[], int tam, int idSalonEliminado) {

	int rtn = -1;
	if (cadena != NULL && tam > 0) {

		for (int i = 0; i < tam; i++) {
			if (cadena[i].idSalon
					== idSalonEliminado&& cadena[i].isEmpty == OCUPADO) {
				cadena[i].isEmpty = LIBRE;
				printf("Se dio de baja al Arcade con el id %d\n",
						cadena[i].idArcade);
				rtn = 0;
			}
		}
	}
	return rtn;
}

void mostrarUnArcade(eArcade cadena) {

	printf(
			"ID SALON: %d - ID ARCADE: %d - NACIONALIDAD: %s - NOMBRE DEL JUEGO: %s - CANT DE JUGADORES: %d - CANT MAX FICHAS: %d - TIPO DE SONIDO: %d\n",
			cadena.idSalon, cadena.idArcade, cadena.nacionalidad,
			cadena.nombreDelJuego, cadena.cantidadDeJugadores,
			cadena.cantidadMaxDeFichas, cadena.tipoDeSonido);
}

void mostrarNombreDeUnJuego(eArcade cadena) {

	printf("NOMBRE DEL JUEGO: %s\n", cadena.nombreDelJuego);
}

int mostrarArcades(eArcade cadena[], int tam) {
	int i;
	int rtn = 0;

	printf("\n\t*************** LISTADO ARCADES ***************\n");

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (cadena[i].isEmpty == OCUPADO) {
				mostrarUnArcade(cadena[i]);
				rtn++;
			}
		}
	}
	return rtn;
}

int arcades_ListarJuegos(eArcade cadena[], int tam) {
	int i;
	int rtn = 0;
	eArcade listaAux[tam];


	printf("\n\t*************** LISTADO DE JUEGOS ***************\n");

	if (cadena != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {

			strncpy(listaAux[i].nombreDelJuego, &cadena->nombreDelJuego[i],
			NOMBRE_DE_JUEGO_LEN);


			if (cadena[i].isEmpty == 0
					&& strncmp(cadena[i].nombreDelJuego,
							listaAux[i].nombreDelJuego,
							NOMBRE_DE_JUEGO_LEN) != 0) {

				mostrarNombreDeUnJuego(cadena[i]);
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

int arcade_altaForzada(eArcade cadena[], int posicion,
		int idSalon /*int idArcade */, char *nacionalidad, char *nombreDelJuego,
		int cantidadDeJugadores, int cantidadMaxDeFichas, int tipoDeSonido) {

	int rtn = 0;
	eArcade bufferAux;

	if (cadena != NULL && posicion >= 0 && idSalon > 0 && nacionalidad != NULL
			&& nombreDelJuego != NULL && cantidadDeJugadores > 0
			&& cantidadMaxDeFichas > 0) {

		bufferAux.idSalon = idSalon;
		bufferAux.idArcade = obtenerId();
		strncpy(bufferAux.nacionalidad, nacionalidad,
		NACIONALIDAD_LEN);
		strncpy(bufferAux.nombreDelJuego, nombreDelJuego,
		NOMBRE_DE_JUEGO_LEN);
		bufferAux.cantidadDeJugadores = cantidadDeJugadores;
		bufferAux.cantidadMaxDeFichas = cantidadMaxDeFichas;
		bufferAux.tipoDeSonido = tipoDeSonido;
		bufferAux.isEmpty = 0;
		cadena[posicion] = bufferAux;
		rtn = 1;
	}
	return rtn;
}
