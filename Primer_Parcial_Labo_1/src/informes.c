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

			if (cadenaSalon[i].isEmpty == OCUPADO) {

				for (j = 0; j < tamArcade; j++) {

					if (cadenaArcade[j].isEmpty == OCUPADO
							&& cadenaArcade[j].idSalon
									== cadenaSalon[i].idSalon) {
						contadorArcades++;

						if (contadorArcades > 4) {
							mostrarUnSalon(cadenaSalon[i]);
							rtn++;
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
