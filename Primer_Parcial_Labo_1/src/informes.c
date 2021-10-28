/*
 * informes.c
 *
 *  Desarrollo de las funciones de la biblioteca informes.
 *      Author: Eduard Brito
 */
#include "informes.h"


int mostrarSalonesConMasArcades(eSalon cadenaSalon[], int tamSalon,
		eArcade cadenaArcade[], int tamArcade) {
	int i;
	int rtn = 0;
	int j;
	int contadorArcades;

	printf("\n\t**********LISTADO DE SALONES**********\n");

	if (cadenaSalon != NULL && tamSalon > 0 && cadenaArcade != NULL
			&& tamArcade > 0) {

		for (i = 0; i < tamSalon; i++) {
			contadorArcades=0;
			if (cadenaSalon[i].isEmpty == OCUPADO) {

				for (j = 0; j < tamArcade; j++) {

					if (cadenaArcade[j].isEmpty == OCUPADO
							&& cadenaArcade[j].idSalon
									== cadenaSalon[i].idSalon) {
						contadorArcades++;

						if (contadorArcades > 4) {
							mostrarUnSalon(cadenaSalon[i]);
							rtn++;
							break;

						}
					}

				}

			}
		}
	}
	return rtn;
}

void mostrarUnArcade_ConDatosParaInformes(eArcade cadena) {

	printf(
			"ID SALON: %d - ID ARCADE: %d - NOMBRE DEL JUEGO: %s - CANT DE JUGADORES: %d\n",
			cadena.idSalon, cadena.idArcade, cadena.nombreDelJuego, cadena.cantidadDeJugadores);
}

void mostrarUnSalonConSusArcades(eSalon cadenaSalon, int cantidadDeArcades){
	printf(
			"ID SALON: %d - NOMBRE: %s - DIRECCION: %s - TIPO: %d - CANTIDAD DE ARCADES: %d\n",
			cadenaSalon.idSalon, cadenaSalon.nombre, cadenaSalon.direccion,cadenaSalon.tipoDeSalon, cantidadDeArcades);

}


int mostrarArcadesPorCantidadDeJugadores(eArcade cadenaArcade[], int tamArcade) {

		int i;
		int rtn = 0;



		printf("\n\t**********LISTADO DE ARCADES POR CANTIDAD DE JUGADORES**********\n");

		if (cadenaArcade != NULL && tamArcade > 0) {

			for (i = 0; i < tamArcade; i++) {

				if (cadenaArcade[i].isEmpty == OCUPADO && cadenaArcade[i].cantidadDeJugadores>2) {

					mostrarUnArcade_ConDatosParaInformes(cadenaArcade[i]);
					//mostrarUnArcade(cadenaArcade[i]);

						rtn++;
					}
			}
		}
		return rtn;
}

int mostrarPorIdSalonesConArcades(eSalon cadenaSalon[], int tamSalon,
		eArcade cadenaArcade[], int tamArcade) {

	int i;
	int rtn = 0;
	int contadorArcades=0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 100, 3, "Ingrese el id del Salon a MOSTRAR: ",
			"Error. Ingrese un Id de Salon entre (1-100): ") == 1
			&& buscarSalon(cadenaSalon, tamSalon, idAux) != -1) {

		posicion = buscarSalon(cadenaSalon, tamSalon, idAux);

	} else {
		printf("No existe el id ingresado\n ");
		rtn = 0;
	}

	printf("\n\t**********LISTADO DE UN SALON CON LA CANTIDAD ARACADES QUE POSEE**********\n");

	if (cadenaArcade != NULL && tamArcade > 0) {


				for (i = 0; i < tamArcade; i++) {

					if (cadenaArcade[i].isEmpty == OCUPADO
							&& cadenaArcade[i].idSalon
									== cadenaSalon[posicion].idSalon) {
						contadorArcades++;
						rtn++;
						}
					}

					mostrarUnSalonConSusArcades(cadenaSalon[posicion], contadorArcades);
				}
	return rtn;
}

int mostrarArcadesDeUnSalon(eSalon cadenaSalon[], int tamSalon,
		eArcade cadenaArcade[], int tamArcade) {

	int i;
	int rtn = 0;
	int contadorArcades=0;
	int posicion;
	int idAux;

	if (pedirEntero(&idAux, 1, 100, 3, "Ingrese el id del Salon a MOSTRAR: ",
			"Error. Ingrese un Id de Salon entre (1-100): ") == 1
			&& buscarSalon(cadenaSalon, tamSalon, idAux) != -1) {

		posicion = buscarSalon(cadenaSalon, tamSalon, idAux);

	} else {
		printf("No existe el id ingresado\n ");
		rtn = 0;
	}

	printf("\n\t**********LISTADO DE ARACADES DE UN SALON**********\n");

	printf(
				"ID SALON: %d - NOMBRE: %s - TIPO: %d\n",
				cadenaSalon[posicion].idSalon, cadenaSalon[posicion].nombre, cadenaSalon[posicion].tipoDeSalon);

	if (cadenaArcade != NULL && tamArcade > 0) {


				for (i = 0; i < tamArcade; i++) {

					if (cadenaArcade[i].isEmpty == OCUPADO
							&& cadenaArcade[i].idSalon
									== cadenaSalon[posicion].idSalon) {
						mostrarUnArcade(cadenaArcade[i]);
						rtn++;
						}
					}

					mostrarUnSalonConSusArcades(cadenaSalon[posicion], contadorArcades);
				}
	return rtn;
}


int mostrarSalonesConMasArcadesAux(eSalon cadenaSalon[], int tamSalon,
		eArcade cadenaArcade[], int tamArcade) {
	int i;
	int rtn = 0;
	int j;
	int contadorArcades;

	printf("\n\t**********LISTADO DE SALONES**********\n");

	if (cadenaSalon != NULL && tamSalon > 0 && cadenaArcade != NULL
			&& tamArcade > 0) {

		for (i = 0; i < tamSalon; i++) {
			contadorArcades=0;
			if (cadenaSalon[i].isEmpty == OCUPADO) {

				for (j = 0; j < tamArcade; j++) {

					if (cadenaArcade[j].isEmpty == OCUPADO
							&& cadenaArcade[j].idSalon
									== cadenaSalon[i].idSalon && cadenaArcade[i].cantidadDeJugadores>2) {
						contadorArcades++;

						if (contadorArcades >= 8 ) {
							mostrarUnSalon(cadenaSalon[i]);
							break;
							rtn++;
						}
					}

				}

			}
		}
	}
	return rtn;
}

int imprimnirPromedioDeAracdesPorSalon(eSalon cadenaSalon[], int tamSalon,
		eArcade cadenaArcade[], int tamArcade) {
	int i;
	int rtn = 0;
	int j;
	int contadorArcades=0;
	int contadorSalones=0;
	float promedio;

	printf("\n\t**********PROMEDIO DE ARCADES POR SALON**********\n");

	if (cadenaSalon != NULL && tamSalon > 0 && cadenaArcade != NULL
			&& tamArcade > 0) {

		for (i = 0; i < tamSalon; i++) {

			if (cadenaSalon[i].isEmpty == OCUPADO) {
				contadorSalones++;
				}
			}

				for (j = 0; j < tamArcade; j++) {

					if (cadenaArcade[j].isEmpty == OCUPADO){

							contadorArcades++;
						}
					}

		if (contadorSalones >0 ) {
			promedio = contadorArcades / (float)(contadorSalones);
			printf("Promedio de ARCADES por SALON: %.2f", promedio);
			rtn++;
			}
	}
	return rtn;
}

int imprimirCantidadDeArcadesPorJuego(eArcade cadenaArcade[], int tamArcade) {

		int i;
		int rtn = 0;
		char charAux[NOMBRE_DE_JUEGO_LEN];
		int contadorArcades=0;

		pedirCadena(charAux,NOMBRE_DE_JUEGO_LEN,2,"Ingrese Nombre del Juego: ","Error, reingrese Nombre del Juego");

		printf("\n\t**********CANTIDAD DE ARCADES POR JUEGO**********\n");

		if (cadenaArcade != NULL && tamArcade > 0) {

			for (i = 0; i < tamArcade; i++) {

				if (cadenaArcade[i].isEmpty == OCUPADO && strcmp(cadenaArcade[i].nombreDelJuego, charAux)==0) {

					contadorArcades++;

						rtn++;
					}
				}
				printf("Cantidad de Arcades que contienen el juego %s es: %d", charAux, contadorArcades);
			}
		return rtn;
}

